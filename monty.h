#ifndef MONTY_H
#define MONTY_H
#define LIMIT 1024
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
extern stack_t *stack[LIMIT];
extern int p;

void push(int value, int line_number);
void pall();
void pint(int line_number, FILE *bytecode);
int main(int argc, char *argv[]);
void pop(int line_number, FILE *bytecode);
void swap(int line_number, FILE *bytecode);
void add(int line_number, FILE *bytecode);
void nop(stack_t **stack, unsigned int line_number);
void sub(int line_number, FILE *bytecode);
void mul(int line_number, FILE *bytecode);
void div_op(int line_number, FILE *bytecode);

#endif

#include "monty.h"
stack_t *stack[LIMIT];
int p = 0;
/**
 *push - add an integer
 *@value: value to be added
 *@line: line it was added
 */
void push(int value, int line)
{
	char value_str[20];

	sprintf(value_str, "%d", value);

	if (!isdigit(value_str[0]) && value_str[0] != '-' && value_str[0] != '+')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	stack[p] = malloc(sizeof(stack_t));
	if (stack[p] == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	stack[p]->n = atoi(value_str);
	stack[p]->prev = NULL;
	stack[p]->next = NULL;

	p++;
}
/**
 *pall-prints the value of the opcode
 */
void pall(void)
{
	int i;

	if (p == 0)
	{
		return;
	}
	for (i = p - 1; i >= 0; i--)
	{
		printf("%d\n", stack[i]->n);
	}
}
/**
 *pint - prints the value
 */
void pint(int line_number, FILE *bytecode)
{
	if (p == 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(bytecode);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", stack[p - 1]->n);
}
/**
 *
 *
 *
 */
void pop(int line_number, FILE *bytecode)
{
	if (p == 0)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bytecode);
		exit(EXIT_FAILURE);
	}
	p--;
	free(stack[p]);
}
/**
 *
 *
 *
 */
void swap(int line_number, FILE *bytecode)
{
	int temp;

	if (p < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bytecode);
		exit(EXIT_FAILURE);
	}
	temp = stack[p - 1]->n;
	stack[p - 1]->n = stack[p - 2]->n;
	stack[p - 2]->n = temp;
}
/**
 *
 *
 *
 *
 */
void add(int line_number, FILE *bytecode)
{
	int sum;

	if (p < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(bytecode);
		exit(EXIT_FAILURE);
	}
	sum = stack[p -1]->n + stack[p - 2]->n;
	pop(line_number, bytecode);
	stack[p -1]->n = sum;
}
/**
 *
 *
 *
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 *
 *
 */
void sub(int line_number, FILE *bytecode)
{
	int result;

	if (p < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(bytecode);
		exit(EXIT_FAILURE);
	}
	result = stack[p - 2]->n - stack[p - 1]->n;
	pop(line_number, bytecode);
	stack[p - 1]->n = result;
}
void mul(int line_number, FILE *bytecode)
{
	int product;

	if (p < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(bytecode);
		exit(EXIT_FAILURE);
	}
	product = stack[p - 2]->n * stack[p - 1]->n;
	pop(line_number, bytecode);
	stack[p - 1]->n = product;
}
void div_op(int line_number, FILE *bytecode)
{
	int result;

	if (p < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(bytecode);
		exit(EXIT_FAILURE);
	}
	if (stack[p - 1]->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bytecode);
		exit(EXIT_FAILURE);
	}
	result = stack[p -2]->n / stack[p - 1]->n;
	pop(line_number, bytecode);
	stack[p -1]->n = result;
}

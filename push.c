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
	free(stack[p - 1]);
	p--;
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

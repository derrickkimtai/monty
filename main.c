#include "monty.h"
/**
 *
 *
 *
 *
 *
 */
int main(int argc, char *argv[])
{
	char *filename, line[100], *opcode, *value;
	int line_number = 0, int_value;
	FILE *bytecode;
	size_t line_length;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}
	filename = argv[1];

	bytecode = fopen(filename, "r");
	if (bytecode == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), bytecode) != NULL)
	{
		line_number++;
		line_length = strlen(line);
		if (line_length > 0 && line[line_length - 1] == '\n')
		{
			line[line_length - 1] = '\0';
		}
		opcode = strtok(line, " \t\n$");
		value = strtok(NULL, " \t\n$");
		if (opcode != NULL)
		{
			if (value != NULL)
			{
				int_value = atoi(value);
			}
			if (strcmp(opcode, "push") == 0)
			{
				if (value == NULL)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					fclose(bytecode);
					return (EXIT_FAILURE);
				}
				int_value = atoi(value);
				push(int_value, line_number);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall();
			}
			else if (strcmp(opcode, "pint") == 0)
			{
				pint(line_number, bytecode);
			}
			else if (strcmp(opcode, "pop") == 0)
			{
				pop(line_number, bytecode);
			}
			else if (strcmp(opcode, "swap") == 0)
			{
				swap(line_number, bytecode);
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n",line_number, opcode);
				fclose(bytecode);
				return (EXIT_FAILURE);
			}
		}
	}
	fclose(bytecode);
	return (EXIT_SUCCESS);
}

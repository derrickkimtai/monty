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
		opcode = strtok(line, " ");
		value = strtok(NULL, "$");
		if (opcode != NULL && value != NULL)
		{
			int_value = atoi(value);
			if (strcmp(opcode, "push") == 0)
			{
					push(int_value, line_number);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall();
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n",line_number, opcode);
				fclose(bytecode);
				return (EXIT_FAILURE);
			}
		}
	}
	pall();
	return (EXIT_SUCCESS);
}

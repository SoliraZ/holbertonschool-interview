#include <stdio.h>
#include "menger.h"

/**
 * is_space - checks if coordinates should be empty
 * @row: row index
 * @col: column index
 *
 * Return: 1 if cell is empty, 0 otherwise
 */
static int is_space(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (1);
		row /= 3;
		col /= 3;
	}

	return (0);
}

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the sponge
 */
void menger(int level)
{
	int size = 1;
	int i, row, col;

	if (level < 0)
		return;

	for (i = 0; i < level; i++)
		size *= 3;

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (is_space(row, col))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}


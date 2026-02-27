 #include <stdio.h>
 #include "sandpiles.h"

static void print_grid(int grid[3][3]);
static int is_unstable(int grid[3][3]);
static void topple(int grid[3][3]);

/**
 * sandpiles_sum - Compute the sum of two sandpiles
 * @grid1: left 3x3 grid, result is stored here
 * @grid2: right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}

	while (is_unstable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}

/**
 * is_unstable - Check if a sandpile grid is unstable
 * @grid: 3x3 grid
 *
 * Return: 1 if unstable, 0 otherwise
 */
static int is_unstable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (1);
		}
	}
	return (0);
}

/**
 * topple - Perform one toppling round on a sandpile grid
 * @grid: 3x3 grid
 */
static void topple(int grid[3][3])
{
	int i, j;
	int temp[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				temp[i][j] -= 4;
				if (i - 1 >= 0)
					temp[i - 1][j] += 1;
				if (i + 1 < 3)
					temp[i + 1][j] += 1;
				if (j - 1 >= 0)
					temp[i][j - 1] += 1;
				if (j + 1 < 3)
					temp[i][j + 1] += 1;
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid[i][j] += temp[i][j];
	}
}

/**
 * print_grid - Print a 3x3 sandpile grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

#include "slide_line.h"

/**
 * slide_left - slides and merges a line to the left
 * @line: line to slide
 * @size: number of elements
 */
static void slide_left(int *line, size_t size)
{
	size_t i, write;
	int merged = 0;

	write = 0;
	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
			continue;
		if (write > 0 && line[write - 1] == line[i] && !merged)
		{
			line[write - 1] *= 2;
			merged = 1;
		}
		else
		{
			if (write != i)
			{
				line[write] = line[i];
				line[i] = 0;
			}
			write++;
			merged = 0;
		}
	}
	while (write < size)
		line[write++] = 0;
}

/**
 * slide_right - slides and merges a line to the right
 * @line: line to slide
 * @size: number of elements
 */
static void slide_right(int *line, size_t size)
{
	size_t i, write;
	int merged = 0;

	write = size;
	i = size;
	while (i > 0)
	{
		i--;
		if (line[i] == 0)
			continue;
		if (write < size && line[write] == line[i] && !merged)
		{
			line[write] *= 2;
			merged = 1;
		}
		else
		{
			write--;
			if (write != i)
			{
				line[write] = line[i];
				line[i] = 0;
			}
			merged = 0;
		}
	}
	while (write > 0)
		line[--write] = 0;
}

/**
 * slide_line - slides and merges an array to one direction
 * @line: array to process
 * @size: number of elements
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL)
		return (0);
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_LEFT)
		slide_left(line, size);
	else
		slide_right(line, size);

	return (1);
}


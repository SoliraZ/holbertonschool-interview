#include <stdlib.h>
#include "holberton.h"

/**
 * is_number - checks if a string contains only digits
 * @s: string to check
 *
 * Return: 1 if all digits, 0 otherwise
 */
int is_number(char *s)
{
	int i = 0;

	if (s == NULL || s[0] == '\0')
		return (0);

	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - computes length of a string
 * @s: string
 *
 * Return: length
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * print_error - prints Error and exits with status 98
 */
void print_error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * multiply - multiplies two positive number strings and prints result
 * @num1: first number string
 * @num2: second number string
 */
void multiply(char *num1, char *num2)
{
	int len1 = _strlen(num1), len2 = _strlen(num2), i, j, carry, digit;
	int total_len = len1 + len2, start = 0;
	int *result = malloc(sizeof(int) * total_len);

	if (result == NULL)
		print_error();
	for (i = 0; i < total_len; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			digit = (num1[i] - '0') * (num2[j] - '0');
			digit += result[i + j + 1] + carry;
			result[i + j + 1] = digit % 10;
			carry = digit / 10;
		}
		result[i] += carry;
	}

	while (start < total_len - 1 && result[start] == 0)
		start++;
	for (i = start; i < total_len; i++)
		_putchar(result[i] + '0');
	_putchar('\n');
	free(result);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument list
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 3 || !is_number(argv[1]) || !is_number(argv[2]))
		print_error();

	multiply(argv[1], argv[2]);
	return (0);
}


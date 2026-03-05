#include "palindrome.h"

/**
 * is_palindrome - checks if an unsigned long integer is a palindrome
 * @n: number to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long original = n;
	unsigned long reversed = 0;

	while (n != 0)
	{
		unsigned long digit = n % 10;

		reversed = reversed * 10 + digit;
		n /= 10;
	}

	if (original == reversed)
		return (1);
	return (0);
}

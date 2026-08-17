#include "regex.h"

/**
 * regex_match - checks whether a pattern matches a string
 * @str: the string to scan
 * @pattern: the regular expression
 *
 * Return: 1 if the pattern matches the string, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	if (!*pattern)
		return (!*str);

	if (*(pattern + 1) == '*')
	{
		if (regex_match(str, pattern + 2))
			return (1);
		while (*str && (*pattern == '.' || *str == *pattern))
		{
			if (regex_match(str + 1, pattern))
				return (1);
			str++;
		}
		return (0);
	}

	if (!*str)
		return (0);

	if (*pattern == '.' || *str == *pattern)
		return (regex_match(str + 1, pattern + 1));

	return (0);
}

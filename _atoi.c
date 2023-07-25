#include "shell.h"
/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @b: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char b, char *delim)
{
	while (*delim)
		if (*delim++ == b)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@b: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int b)
{
	if ((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@t: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *t)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  t[i] != '\0' && flag != 2; i++)
	{
		if (t[i] == '-')
			sign *= -1;

		if (t[i] >= '0' && t[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (t[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}


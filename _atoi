/**
 * _atoi - converts a string to number
 * @str: the number in string
 *
 * Return: the converted number
 */

int _atoi(char *str)
{
	int i = 0;
	unsigned int number = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			number = number * 10 + (str[i] - '0');
		else
			return (-1);
		i++;
	}

	return (number);
}

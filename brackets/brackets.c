#include "brackets.h"

int		matching(char a, char b)
{
	return ((a == '(' && b == ')') || (a == '[' && b == ']') ||\
			(a == '{' && b == '}'));
}

int		brackets(char *str)
{
	int		v;
	int		i;
	int		stack[5000];

	v = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			stack[++v] = str[i];
		if (str[i] == ')' || str[i] == ']' || str[i] == '}')
		{
			if (!matching(stack[v--], str[i]))
				return (0);
		}
		i++;
	}
	return (!v);
}

int		main(int ac, char *av[])
{
	if (ac == 1)
		return (write(1, "\n", 1));
	av++;
	while (*av)
	{
		if (brackets(*av))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
		av++;
	}
	return 0;
}

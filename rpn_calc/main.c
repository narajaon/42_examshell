#include "rpn.h"

char		*get_val(char *str, int *stack)
{
	*stack = atoi(str);
	if (is_neg(str))
		str++;
	while (*str && is_nu(*str))
		str++;
	if (!is_space(*str))
		return (NULL);
	while (*str && is_space(*str))
		str++;
	return (str);
}

int			rpn_calc(char *str)
{
	int		stack[5000];
	int		i;
	int		nb_ope;
	int		nb_val;
	int		(*ope)(int, int);
	int		res;

	i = 0;
	nb_ope = 0;
	nb_val = 0;
	ope = NULL;
	while (*str && is_space(*str))
		str++;
	while (*str)
	{
		if (!is_nu(*str) && !is_space(*str) && !is_ope(*str) && !is_neg(str))
			return (-1);
		if (is_nu(*str) || is_neg(str))
		{
			nb_val++;
			if ((str = get_val(str, &stack[i++])) == NULL)
				return (-1);
		}
		if (*str && is_ope(*str) && !is_nu(*(str + 1)))
		{
			nb_ope++;
			if (nb_val < 2 || nb_ope >= nb_val)
				return (-1);
			if ((*str == '/' || *str == '%') && stack[i - 1] == 0)
				return (-1);
			ope = do_op(*str);
			res = ope(stack[i - 2], stack[i - 1]);
			i -= 1;
			stack[i - 1] = res;
			str++;
			while (*str && is_space(*str))
				str++;
		}
	}
	if (nb_ope != nb_val - 1)
		return (-1);
	printf("%d\n", res);
	return (0);
}

int			main(int ac, char **av)
{
	if (ac != 2)
		return (printf("Error\n"));
	if (rpn_calc(av[1]) < 0)
		return (printf("Error\n"));
	return (0);
}

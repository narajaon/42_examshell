#include "rpn.h"

int		add_val(int a, int b)
{
	return (a + b);
}

int		sub_val(int a, int b)
{
	return (a - b);
}

int		mult_val(int a, int b)
{
	return (a * b);
}

int		div_val(int a, int b)
{
	return (a / b);
}

int		mod_val(int a, int b)
{
	return (a % b);
}

void	*do_op(char c)
{
	if (c == '+')
		return (&add_val);
	if (c == '-')
		return (&sub_val);
	if (c == '*')
		return (&mult_val);
	if (c == '/')
		return (&div_val);
	if (c == '%')
		return (&mod_val);
	return (NULL);
}

int		is_nu(char c)
{
	return (c >= '0' && c <= '9');
}

int		is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int		is_ope(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int		is_neg(char *nb)
{
	if (*nb == '-' && *(nb + 1) != '\0')
	{
		if (is_nu(*(nb + 1)))
			return (1);
	}
	return (0);
}

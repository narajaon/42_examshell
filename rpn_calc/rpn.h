#ifndef RPN_H
#define RPN_H
# include <stdio.h>
# include <stdlib.h>
# define NBR(x) printf(#x "= |%d|\n", x)
# define STR(x) printf(#x "= |%s|\n", x)
# define CHAR(x) printf(#x "= |%c|\n", x)
# define ICI printf("ICI\n")
# define LA printf("LA\n")

int		add_val(int a, int b);
int		sub_val(int a, int b);
int		mult_val(int a, int b);
int		div_val(int a, int b);
int		mod_val(int a, int b);
void	*do_op(char c);

int		is_nu(char c);
int		is_space(char c);
int		is_neg(char *NBR);
int		is_ope(char c);
#endif

#include <stdio.h>
#include <unistd.h>
#define NBR(x) printf(#x " = %d\n", x)
#define STR(x) printf(#x " = %s\n", x)
#define CHAR(x) printf(#x " = %c\n", x)
#define HEX(x) printf(#x " = %x\n", x)

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	char		*tmp;

	tmp = str;
	while (*tmp)
	{
		ft_putchar(*tmp);
		tmp++;
	}
}

void		ft_puthex(int nb)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16);
		ft_puthex(nb % 16);
	}
	else if (nb < 16 && nb > 9)
		ft_putchar(nb - 10 + 'a');
	else
		ft_putchar(nb + '0');
}

void		print_bits(unsigned char *bits, int limit)
{
	int		i;

	i = 0;
	while (i < limit)
	{
		if (bits[i] >= ' ' && bits[i] <= '~')
			ft_putchar(bits[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putchar('\n');
}

void		print_memory(const void *addr, size_t size)
{
	size_t			i;
	unsigned char	*bit;
	int				rem;

	i = 0;
	bit = (unsigned char *)addr;
	while (i < size)
	{
		if (bit[i] < 16)
			ft_putchar('0');
		ft_puthex(bit[i++]);
		if (i % 2 == 0)
			ft_putchar(' ');
		if (i % 16 == 0)
			print_bits(&bit[i - 16], 16);
	}
	if (i % 16)
	{
		rem = (i % 16);
		while (rem < 16)
		{
			ft_putstr("  ");
			rem++;
			if (rem % 2 == 0)
				ft_putchar(' ');
		}
		print_bits(&bit[i - i % 16], i % 16);
	}
}

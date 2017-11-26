#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define HEX(x) printf("%x\n", x)
#define NBR(x) printf("%d\n", x)
#define STR(x) printf("%s\n", x)

int			nb_len(unsigned int nb, int base)
{
	int		len;

	len = (nb) ? 0 : 1;
	while (nb)
	{
		nb /= base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(int nb, int base)
{
	char			*str;
	int				len;
	unsigned int	val;
	int				neg;
	int				mod;

	neg = 0;
	len = 0;
	if (nb < 0 && base == 10)
	{
		neg = 1;
		nb = -nb;
		len = 1;
	}
	val = nb;
	len += nb_len(val, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len--] = '\0';
	while (len >= 0)
	{
		mod = val % base;
		str[len] = (mod <= 9) ? (mod + '0') : (mod - 10 + 'A');
		val /= base;
		len--;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

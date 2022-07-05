#include <stdarg.h>
#include <unistd.h>

void ft_putchar(char c, int *len)
{
	write(1, &c, 1);
}
	(*len)++;

void ft_putstr(char *str, int *len)
{
	int i = 0;
	if (!str)
		ft_putstr("(null)", len);
	else
		while (str[i])
			ft_putchar(str[i++], len);
}
void ft_putnbr(int nbr, int *len)
{
	long nb = nbr;
	if (nb < 0)
	{
		ft_putchar('-', len);
		nb = -nb;
	}
	if (nb < 10)
	{
		ft_putchar(nb + 48, len);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
}

void ft_puthex(unsigned int nbr, int *len)
{
	unsigned long nb = nbr;
	// check^^
	if (nb < 16)
	{
		if (nb < 10)
			ft_putchar(nb + 48, len);
		if (nb >= 10)
			ft_putchar((nb % 10) + 'a', len);
	}
	if (nb >= 16)
	{
		ft_puthex(nb / 16, len);
		ft_puthex(nb % 16, len);
	}
}

int check(va_list args, char type, int *len)
{
	if (type == 's')
		ft_putstr(va_arg(args, char *), len);
	if (type == 'd')
		ft_putnbr(va_arg(args, int), len);
	if (type == 'x')
		ft_puthex(va_arg(args, unsigned int), len);
	return (*len);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			check(args, format[i], &len);
		}
		else
			ft_putchar(format[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}

int main()
{
	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d", "number", 42);
	ft_printf("\nHexadecimal for %d is %x\n", 42, 42);
}
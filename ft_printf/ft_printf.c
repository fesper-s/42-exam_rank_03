#include <stdarg.h>
#include <unistd.h>

int	g_var = 0;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	nbr;

	nbr = (long) n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		nbr = nbr % 10;
	}
	ft_putchar(nbr + 48);
}

void	ft_puthex(unsigned nbr, unsigned len, char *sign)
{
	if (nbr >= len)
		ft_puthex(nbr / len, len, sign);
	write(1, &sign[nbr % len], 1);
	g_var++;
}

int	ft_printf(char *format, ...)
{
	g_var = 0;
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				int len = -1;
				char *str = va_arg(ap, char *);
				if (!str)
					str = "(null)";
				while (str[++len]);
				g_var += len;
				write(1, str, len);
			}
			else if (*format == 'd')
			{
				long long decimal = va_arg(ap, int);
				if (decimal < 0)
					g_var++;
				ft_putnbr(decimal);
			}
			else if (*format == 'x')
			{
				int hex = va_arg(ap, int);
				ft_puthex(hex, 16, "0123456789abcdef");
			}
			format++;
		}
		else
			g_var += write(1, format++, 1);
	}
	va_end(ap);
	return (g_var);
}

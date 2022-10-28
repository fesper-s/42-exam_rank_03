#include <unistd.h>
#include <stdarg.h>

int	g_var = 0;

void	ft_putnbr(long digits, int len, char *sign)
{
	if (digits >= len)
		ft_putnbr(digits / len, len, sign);
	write(1, &sign[digits % len], 1);
	g_var++;
}

void	ft_puthex(unsigned digits, unsigned len, char *sign)
{
	if (digits >= len)
		ft_puthex(digits / len, len, sign);
	write(1, &sign[digits % len], 1);
	g_var++;
}

int	ft_printf(const char *format, ...)
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
				int	len = 0;
				char *str = va_arg(ap, char *);
				if (!str)
					str = "(null)";
				while (str[len])
					len++;
				g_var += len;
				write(1, str, len);
			}
			else if (*format == 'd')
			{
				long long decimal = va_arg(ap, int);
				if (decimal < 0)
				{
					write(1, "-", 1);
					g_var++;
					decimal = -decimal;
				}
				ft_putnbr(decimal, 10, "0123456789");
			}
			else if (*format == 'x')
			{
				int	hex = va_arg(ap, int);
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

int	main(void)
{
	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d\n", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	return (0);
}

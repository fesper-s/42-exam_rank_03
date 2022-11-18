#include <unistd.h>
#include <stdarg.h>

size_t	ft_putstr(char *str, int len)
{
	while (str && str[len] && ++len);
	return (str ? write(1, str, len) : write(1, "(null)", 6));
}

void	ft_putnbr(long nbr, unsigned len, char *sign, int *size)
{
	if (nbr >= len)
		ft_putnbr(nbr / len, len, sign, size);
	*size += (int) write(1, &sign[nbr % len], 1);
}

void	ft_puthex(long nbr, int len, char *sign, int *size)
{
	(nbr < 0) ? (*size += (int) write(1, "-", 1), \
		ft_putnbr(-nbr, len, sign, size)) : (ft_putnbr(nbr, len, sign, size));
}

int	ft_printf(char *format, ...)
{
	int		size = 0;
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) == 's' && (format += 2))
			size += (int) ft_putstr(va_arg(ap, char *), 0);
		else if (*format == '%' && *(format + 1) == 'x' && (format += 2))
			ft_putnbr(va_arg(ap, int), 16, "0123456789abcdef", &size);
		else if (*format == '%' && *(format + 1) == 'd' && (format += 2))
			ft_puthex(va_arg(ap, int), 10, "0123456789", &size);
		else
			size += (int) write(1, format++, 1);
	}
	return (va_end(ap), size);
}

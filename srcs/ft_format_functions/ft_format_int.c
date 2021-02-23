#include <libftprintf.h>

static long long int	ft_get_ap_int(va_list ap, const char *s)
{
	if (ft_search(s, "l") && *(ft_search(s, "l") - 1) == 'l')
		return (va_arg(ap, long long int));
	else if (ft_search(s, "l"))
		return ((long long int)va_arg(ap, long int));
	else if (ft_search(s, "h") && *(ft_search(s, "h") - 1) == 'h')
		return ((long long int)va_arg(ap, int));
	else if (ft_search(s, "h"))
		return ((long long int)va_arg(ap, int));
	else
		return ((long long int)va_arg(ap, int));
}

static int		ft_size_displayed(t_flags flags, t_printf data, int size, unsigned long long int v)
{
	if (!(flags.prec == 0 && v == 0))
	{
		data.ret += flags.prec > size ? flags.prec : size;
		size = flags.prec > size ? flags.prec : size;
	}
	if (flags.nbr > size)
		data.ret += flags.nbr - size;
	else if (flags.min > size)
		data.ret += flags.min - size;
	else if (flags.zero > size)
		data.ret += flags.zero - size;
	return (data.ret);
}

static int		ft_format_int_size(long long int value)
{
	int			size;
	unsigned long long int	v;

	size = value < 0 ? 2 : 1;
	v = value < 0 ? value * -1 : value;
	while ((v /= 10) > 0)
		size++;
	return (size);
}

static void		ft_putllu_fd(unsigned long long int nbr, int fd)
{
	if (nbr > 9)
		ft_putllu_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
}

int			ft_format_int(t_printf data, t_flags flags, va_list ap)
{
	long long int	v;
	int		size;
	int		prec;

	v = ft_get_ap_int(ap, data.s);
	size = (v == 0 && flags.prec == 0) ? 0 : ft_format_int_size(v);
	flags.prec += v < 0 && flags.prec > 0 ? 1 : 0;
	prec = flags.prec;
	if (flags.nbr > 0)
		ft_flag_number(flags, prec > size ? prec : size);
	if (v < 0)
		ft_putchar_fd('-', 1);
	v *= v < 0 ? -1 : 1;
	if (flags.zero > 0 && flags.min <= 0)
		ft_flag_zero(flags, data, prec > size ? prec : size);
	while (prec-- > size)
		ft_putchar_fd('0', 1);
	if (!(flags.prec == 0 && v == 0))
		ft_putllu_fd(v, 1);
	if (flags.min > 0)
		ft_flag_min(flags, flags.prec > size ? flags.prec : size);
	return (ft_size_displayed(flags, data, size, v));
}

#include <libftprintf.h>

const char	*bases[] =  { 
	"0123456789", 
	"01234567", 
	"0123456789abcdef", 
	"0123456789ABCDEF" };

static unsigned long long int	ft_get_ap_uint(va_list ap, const char *s)
{
	if (ft_search(s, "l") && *(ft_search(s, "l") - 1) == 'l')
		return (va_arg(ap, unsigned long long int));
	else if (ft_search(s, "l"))
		return ((unsigned long long int)va_arg(ap, unsigned long int));
	else if (ft_search(s, "h") && *(ft_search(s, "h") - 1) == 'h')
		return ((unsigned long long int)va_arg(ap, unsigned int));
	else if (ft_search(s, "h"))
		return ((unsigned long long int)va_arg(ap, unsigned int));
	else
		return ((unsigned long long int)va_arg(ap, unsigned int));
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

static int		ft_format_uint_size(unsigned long long int value, const char *base)
{
	int			size;
	unsigned long long int	v;

	size = value < 0 ? 2 : 1;
	v = value < 0 ? value * -1 : value;
	while ((v /= ft_strlen(base)) > 0)
		size++;
	return (size);
}

static void		ft_putllu_fd(unsigned long long int nbr, const char *base, int fd)
{
	if (nbr > (ft_strlen(base) - 1))
		ft_putllu_fd(nbr / ft_strlen(base), base, fd);
	ft_putchar_fd(base[nbr % ft_strlen(base)], fd);
}

int			ft_format_uint(t_printf data, t_flags flags, va_list ap)
{
	char			*form = "uoxX";
	const char		*base;
	int			size;
	int			prec;
	unsigned long long int	v;

	base = bases[ft_strchr(form, *(data.s)) - form];
	v = ft_get_ap_uint(ap, data.s);
	size = (v == 0 && flags.prec == 0) ? 0 : ft_format_uint_size(v, base);
	flags.prec += v < 0 && flags.prec > 0 ? 1 : 0;
	prec = flags.prec;
	if (flags.nbr > 0)
		ft_flag_number(flags, prec > size ? prec : size);
	if (flags.zero > 0 && flags.min <= 0)
		ft_flag_zero(flags, data, prec > size ? prec : size);
	while (prec-- > size)
		ft_putchar_fd('0', 1);
	if (!(flags.prec == 0 && v == 0))
		ft_putllu_fd(v, base, 1);
	if (flags.min > 0)
		ft_flag_min(flags, flags.prec > size ? flags.prec : size);
	return (ft_size_displayed(flags, data, size, v));
}

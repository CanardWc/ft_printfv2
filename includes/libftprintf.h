#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libraries/libft/includes/libft.h"
# include <stdarg.h>

typedef struct		s_printf
{
	const char	*s;
	int		ret;
}			t_printf;

typedef struct		s_flags
{
	int		nbr;
	int		min;
	int		prec;
	int		zero;
}			t_flags;

typedef struct		s_form_f
{
	char		format;
	int		(*fct)(t_printf, t_flags, va_list);
}			t_form_f;

int			ft_printf(const char *s, ...);

char			*ft_search(const char *s, char *pos);

int			ft_format_c(t_printf data, t_flags flags, va_list ap);
int			ft_format_s(t_printf data, t_flags flags, va_list ap);
int			ft_format_p(t_printf data, t_flags flags, va_list ap);
int			ft_format_int(t_printf data, t_flags flags, va_list ap);
int			ft_format_uint(t_printf data, t_flags flags, va_list ap);
int			ft_format_percent(t_printf data, t_flags flags, va_list ap);
/*
int			ft_format_f(t_printf data, t_flags flags, va_list ap);
int			ft_format_n(t_printf data, t_flags flags, va_list ap);
int			ft_format_e(t_printf data, t_flags flags, va_list ap);
int			ft_format_g(t_printf data, t_flags flags, va_list ap);
*/

t_flags			ft_flag_asterisk(const char *s, va_list ap);
void			ft_flag_number(t_flags flags, int size);
void			ft_flag_min(t_flags flags, int size);
void			ft_flag_zero(t_flags flags, t_printf data, int size);
void			ft_flag_plus(void);
void			ft_flag_spc(void);
void			ft_flag_hash(char format);

#endif

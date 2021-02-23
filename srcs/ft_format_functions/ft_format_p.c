/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:38:16 by edassess          #+#    #+#             */
/*   Updated: 2021/02/08 13:50:07 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int		ft_format_p_size(unsigned long int value)
{
	int			size;

	size = 1;
	while ((value /= 16) > 0)
		size++;
	return (size + 2);
}

int 	ft_format_p(t_printf data, t_flags flags, va_list ap)
{
	char			*base;
	int			size;
	unsigned long int	v;

	base = "0123456789abcdef";
	v = va_arg(ap, unsigned long int);
	size = ft_format_p_size(v);
	if (flags.nbr > 0)
		ft_flag_number(flags, size);
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_fd(v, base, 1);
	if (flags.min > 0)
		ft_flag_min(flags, size);
	data.ret += size;
	data.ret += flags.nbr > size ? flags.nbr - size : 0;
	data.ret += flags.min > size ? flags.min - size : 0;
	return (data.ret);
}

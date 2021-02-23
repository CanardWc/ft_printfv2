/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:40:05 by edassess          #+#    #+#             */
/*   Updated: 2021/02/12 11:23:18 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int	ft_format_s(t_printf data, t_flags flags, va_list ap)
{
	char	*str;
	int	size;

	if(!(str = va_arg(ap, char *)))
		str = "(null)";
	size = ft_strlen(str);
	if (flags.prec > 0 || (flags.prec == 0 && ft_search(data.s, ".")))
		size = size > flags.prec ? flags.prec : size;
	if (flags.nbr > size)
		ft_flag_number(flags, size);
	write(1, str, size);
	if (flags.min > size)
		ft_flag_min(flags, size);
	data.ret += size;
	data.ret += flags.nbr > size ? flags.nbr - size : 0;
	data.ret += flags.min > size ? flags.min - size : 0;
	return (data.ret);
}

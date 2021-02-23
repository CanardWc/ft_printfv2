/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:39:50 by edassess          #+#    #+#             */
/*   Updated: 2021/02/04 11:14:02 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int	ft_format_percent(t_printf data, t_flags flags, va_list ap)
{
	ap = (void *)ap;
	flags.prec = 0;
	ft_putchar_fd('%', 1);
	return (data.ret + 1);
}

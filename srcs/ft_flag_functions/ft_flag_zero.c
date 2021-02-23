/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:13:19 by mrochet           #+#    #+#             */
/*   Updated: 2021/02/10 14:55:36 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	ft_flag_zero(t_flags flags, t_printf data, int size)
{
	if (ft_search(data.s, "-") || (ft_strchr("diouxX", *(data.s)) && \
				ft_search(data.s, ".")))
		return ;
	while (flags.zero-- > size)
		ft_putchar_fd('0', 1);
}

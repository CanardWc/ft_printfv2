/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:13:31 by mrochet           #+#    #+#             */
/*   Updated: 2021/02/10 14:55:46 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	ft_flag_number(t_flags flags, int size)
{
	flags.nbr -= size;
	while (flags.nbr-- > 0)
		ft_putchar_fd(' ', 1);
}

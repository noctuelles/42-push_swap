/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:44:53 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/06 16:22:27 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	show_stacks(t_data data)
{
	int	i;

	ft_printf("\n{4;1;31}Stack A :{0}\n\n");
	if (data.a.top == 0)
		ft_putstr("Empty.\n\n");
	else
	{
		i = data.a.top - 1;
		while (i >= 0)
		{
			ft_printf("%7d  i: %3u idx: %3u\n", data.a.content[i].value, i, data.a.content[i].sort_idx);
			i--;
		}
		ft_printf("{96}-{0}\n{31}a{0}\n\n");
	}
	ft_printf("{4;1;93}Stack B :{0}\n\n");
	if (data.b.top == 0)
	{
		ft_putstr("Empty.\n\n");
		return ;
	}
	i = data.b.top - 1;
	while (i >= 0)
	{
			ft_printf("%7d  i: %3u idx: %3u\n", data.b.content[i].value, i, data.b.content[i].sort_idx);
			i--;
	}
	ft_printf("{96}-{0}\n{93}b{0}\n\n");
}

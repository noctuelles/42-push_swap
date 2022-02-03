/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:45:10 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/02 19:15:09 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
# include "libft.h"
# include <unistd.h>

void	pa(t_data *data)
{
	if (data->b.top < 1)
		return ;
	push(&data->a, pop(&data->b));
	data->nbr++;
	write(STDOUT, STR_PA, sizeof(STR_PA) - 1);
}

void	pb(t_data *data)
{
	if (data->a.top < 1)
		return ;
	push(&data->b, pop(&data->a));
	data->nbr++;
	write(STDOUT, STR_PB, sizeof(STR_PB) - 1);
}

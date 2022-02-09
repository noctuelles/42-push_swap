/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:45:10 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/09 16:51:10 by plouvel          ###   ########.fr       */
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
	add_instruction(data, pa);
	data->nbr++;
#ifdef OUTPUT
	write(STDOUT, STR_PA, sizeof(STR_PA) - 1);
#endif
}

void	pb(t_data *data)
{
	if (data->a.top < 1)
		return ;
	push(&data->b, pop(&data->a));
	add_instruction(data, pb);
	data->nbr++;
#ifdef OUTPUT
	write(STDOUT, STR_PB, sizeof(STR_PB) - 1);
#endif
}

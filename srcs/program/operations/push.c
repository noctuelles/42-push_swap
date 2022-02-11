/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:45:10 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/11 16:53:47 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
# include <stdlib.h>

void	pa(t_data *data)
{
	if (data->b.top < 1)
		return ;
	push(&data->a, pop(&data->b));
	if(!add_instruction(data, pa))
		exit(throw_error(data));
}

void	pb(t_data *data)
{
	if (data->a.top < 1)
		return ;
	push(&data->b, pop(&data->a));
	if(!add_instruction(data, pb))
		exit(throw_error(data));
}

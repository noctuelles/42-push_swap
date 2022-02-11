/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:01:46 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/11 16:19:27 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* index_stack() gives for each element in the given stack, based on their order
 * sort order.
 * Information are hold in the info structure. */

void	index_stack(t_stack *stack)
{
	t_index	i;
	t_index	j;

	i = 0;
	while (i < stack->top)
	{
		j = 0;
		stack->content[i].sort_idx = 0;
		while (j < stack->top)
		{
			if (stack->content[i].value > stack->content[j].value)
				stack->content[i].sort_idx++;
			j++;
		}
		i++;
	}
}

/* init_stacks() index the stack A, and first push all the elements below
 * the median, then push all the remaining elements (which are upper the
 * median) except 3, that will be sorted quickly using the dedicated 
 * "algorithm", which is more a if forest. */

void	init_stacks(t_data *data)
{
	t_index	i;
	t_index	median;

	i = 0;
	median = data->a.top / 2 - 1;
	while (i <= median)
	{
		if (data->a.content[data->a.top - 1].sort_idx <= median)
		{
			pb(data);
			i++;
		}
		else
			ra(data);
	}
	while (data->a.top > 3)
		pb(data);
	sort_three_elem_stack(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 01:18:10 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/10 19:08:56 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline t_bool	bigger_than(t_data *data, t_index idx1, t_index idx2)
{
	if (data->a.content[idx1].sort_idx > data->a.content[idx2].sort_idx)
		return (TRUE);
	else
		return (FALSE);
}

static inline t_bool	less_than(t_data *data, t_index idx1, t_index idx2)
{
	if (data->a.content[idx1].sort_idx < data->a.content[idx2].sort_idx)
		return (TRUE);
	else
		return (FALSE);
}

void		sort_three_elem_stack(t_data *data)
{
	if (bigger_than(data, 2, 1) && less_than(data, 1, 0)
			&& less_than(data, 0, 2))
		ra(data);
	else if (bigger_than(data, 2, 1) && bigger_than(data, 1, 0)
			&& less_than(data, 0, 2))
	{
		sa(data);
		rra(data);
	}
	else if (bigger_than(data, 2, 1) && less_than(data, 1, 0)
			&& bigger_than(data, 0, 2))
		sa(data);
	else if (less_than(data, 2, 1) && bigger_than(data, 1, 0)
			&& less_than(data, 0, 2))
		rra(data);
	else if (less_than(data, 2, 1) && bigger_than(data, 1, 0)
			&& bigger_than(data, 0, 2))
	{
		rra(data);
		sa(data);
	}
}

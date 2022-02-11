/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:06:34 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/11 16:19:32 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* move_element_to_stack_x_top/bottom() computes how many instruction (and
 * what type of instruction) you need to move the element elem to the top of
 * the specified stack. */

void	move_element_to_stack_a_top(t_data *data, t_move *move, t_index idx)
{
	size_t	distance_from_top;

	distance_from_top = (data->a.top - idx) - 1;
	if (distance_from_top > data->a.top / 2)
	{
		move->stack_a_inst = rra;
		move->stack_a_inst_rpt = idx + 1;
	}
	else
	{
		move->stack_a_inst = ra;
		move->stack_a_inst_rpt = distance_from_top;
	}
}

void	move_element_to_stack_b_top(t_data *data, t_move *move, t_index idx)
{
	size_t	distance_from_top;

	distance_from_top = (data->b.top - idx) - 1;
	if (distance_from_top > data->b.top / 2)
	{
		move->stack_b_inst = rrb;
		move->stack_b_inst_rpt = idx + 1;
	}
	else
	{
		move->stack_b_inst = rb;
		move->stack_b_inst_rpt = distance_from_top;
	}
}

void	move_element_to_stack_a_bottom(t_data *data, t_move *move, t_index idx)
{
	size_t	distance_from_bottom;

	distance_from_bottom = idx;
	if (distance_from_bottom > data->a.top / 2)
	{
		move->stack_a_inst = ra;
		move->stack_a_inst_rpt = data->a.top - idx;
	}
	else
	{
		move->stack_a_inst = rra;
		move->stack_a_inst_rpt = distance_from_bottom;
	}
}

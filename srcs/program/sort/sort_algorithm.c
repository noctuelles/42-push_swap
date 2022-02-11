/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:54:16 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/11 18:24:42 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* insert_elem_in_stack_a() computes the move needed to insert the element
 * to_push in the stack A. The element to_push is considered as the top element
 * of the stack B.
 * If it fails to insert to_push, it will be the new biggest or new smallest
 * element if we push it to stack A, so we call insert_extreme_elem() to take
 * care of the job.
 */

static void	insert_extreme_elem(t_data *data, t_move *move, t_element to_push)
{
	t_index	extreme_idx;

	if (is_biggest(data->a, to_push))
	{
		extreme_idx = find_biggest_in_stack(data->a);
		if (extreme_idx != 0)
			move_element_to_stack_a_bottom(data, move, extreme_idx);
		else
		{
			move->stack_a_inst = ra;
			move->stack_a_inst_rpt = 1;
			move->do_inst_after_push = TRUE;
		}
	}
	else
	{
		extreme_idx = find_smallest_in_stack(data->a);
		if (extreme_idx != data->a.top - 1)
			move_element_to_stack_a_top(data, move, extreme_idx);
		else
		{
			move->stack_a_inst = pa;
			move->stack_a_inst_rpt = 1;
		}
	}
}

static void	insert_elem_in_stack_a(t_data *data, t_move *move,
															t_element to_push)
{
	t_index	i;

	i = data->a.top - 1;
	while (i > 0)
	{
		if (is_in_between(data->a.content[i].sort_idx,
				data->a.content[i - 1].sort_idx, to_push.sort_idx))
			return (move_element_to_stack_a_top(data, move, i - 1));
		i--;
	}
	if (is_in_between(data->a.content[0].sort_idx,
			data->a.content[data->a.top - 1].sort_idx, to_push.sort_idx))
	{
		move->stack_a_inst = pa;
		move->stack_a_inst_rpt = 1;
	}
	else
		insert_extreme_elem(data, move, to_push);
}

static t_move	find_best_move(t_data *data)
{
	t_move		best_move;
	t_move		curr_move;
	t_sindex	i;

	best_move.stack_a_inst_rpt = SIZE_MAX;
	best_move.stack_b_inst_rpt = 0;
	i = data->b.top - 1;
	while (i >= 0)
	{
		curr_move.do_inst_after_push = FALSE;
		move_element_to_stack_b_top(data, &curr_move, i);
		insert_elem_in_stack_a(data, &curr_move, data->b.content[i]);
		if ((curr_move.stack_a_inst_rpt + curr_move.stack_b_inst_rpt)
			< (best_move.stack_a_inst_rpt + best_move.stack_b_inst_rpt))
			best_move = curr_move;
		i--;
	}
	return (best_move);
}

void	do_sort(t_data *data)
{
	t_move	move;
	t_index	smallest_idx;

	while (data->b.top)
	{
		move = find_best_move(data);
		do_op(data, move.stack_b_inst, move.stack_b_inst_rpt);
		if (move.do_inst_after_push)
			pa(data);
		do_op(data, move.stack_a_inst, move.stack_a_inst_rpt);
		if (move.stack_a_inst != pa && !move.do_inst_after_push)
			pa(data);
	}
	smallest_idx = find_smallest_in_stack(data->a);
	move_element_to_stack_a_top(data, &move, smallest_idx);
	do_op(data, move.stack_a_inst, move.stack_a_inst_rpt);
}

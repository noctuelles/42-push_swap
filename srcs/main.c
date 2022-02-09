/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:42:11 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/09 16:57:38 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"
#include "get_next_line.h"

static inline int	throw_error(t_data data)
{
	ft_putstr_fd(STR_ERROR, STDERR);
	free_stack(data.a);
	free_stack(data.b);
	return (1);
}

#include <stdio.h>

void	do_op(t_data *data, size_t t, void (*f)(t_data *))
{
	size_t	i;

	i = 0;
	while (i++ < t)
		f(data);
}

void	push_low_median(t_data *data)
{
	t_index	i;

	i = 0;
	//printf("median is %lu\n", data->median);
	while (i <= data->median)
	{
		//show_stacks(*data);
		//getchar();
		if (data->a.content[data->a.top - 1].sort_idx <= data->median)
		{
			//printf("%lu <= %lu\n",data->a.content[data->a.top - 1].sort_idx, data->median);
			pb(data);
			i++;
		}
		else
			ra(data);
	}
}

void	push_high_median(t_data *data)
{
	while (data->a.top > 3)
		pb(data);
}

size_t	get_stack_a_config_cost(t_element elem)
{
	
}

t_bool	is_in_between(int range_a, int range_b, int nbr)
{
	if (range_a < range_b)
	{
		if (nbr > range_a && nbr < range_b)
			return (TRUE);
	}
	return (FALSE);
}

t_bool	is_smallest(t_data *data, t_element to_push)
{
	t_index	i;

	i = 0;
	while (i < data->a.top)
	{
		if (data->a.content[i].sort_idx < to_push.sort_idx)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	is_biggest(t_data *data, t_element to_push)
{
	t_index	i;

	i = 0;
	while (i < data->a.top)
	{
		if (data->a.content[i].sort_idx > to_push.sort_idx)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_index	find_biggest_in_a(t_data *data)
{
	t_index	i;
	int		biggest;
	t_index	biggest_i;

	i = 0;
	biggest_i = 0;
	biggest = data->a.content[i].value;
	while (++i < data->a.top)
	{
		if (data->a.content[i].value > biggest)
		{
			biggest_i = i;
			biggest = data->a.content[i].value;
		}
	}
	return (biggest_i);
}

t_index	find_smallest_in_a(t_data *data)
{
	t_index	i;
	int		smallest;
	t_index	smallest_i;

	i = 0;
	smallest_i = 0;
	smallest = data->a.content[i].value;
	while (++i < data->a.top)
	{
		if (data->a.content[i].value < smallest)
		{
			smallest_i = i;
			smallest = data->a.content[i].value;
		}
	}
	return (smallest_i);
}

void	move_to_top(t_data *data, t_index idx, t_move *move)
{
	size_t	distance_from_top;

	//ft_printf("{33}Moving index %u to top.{0}\n", idx);
	distance_from_top = (data->a.top - idx) - 1;
	if (distance_from_top > data->a.top / 2)
	{
		distance_from_top = idx + 1;
		move->instruction = rra;
		//ft_printf("{31}Instruction used will be RRA.{0}\n");
	}
	else
	{
		//ft_printf("{31}Instruction used will be RA.{0}\n");
		move->instruction = ra;
	}
	move->times = distance_from_top;
	//ft_printf("{32}You will use this instruction %u times.{0}\n\n", move->times);
}

void	move_to_top_b(t_data *data, t_index idx, t_move *move)
{
	size_t	distance_from_top;

	//ft_printf("{33}Moving index %u to top.{0}\n", idx);
	distance_from_top = (data->b.top - idx) - 1;
	if (distance_from_top > data->b.top / 2)
	{
		distance_from_top = idx + 1;
		move->instruction_b = rrb;
		//ft_printf("{31}Instruction used will be RRA.{0}\n");
	}
	else
	{
		//ft_printf("{31}Instruction used will be RA.{0}\n");
		move->instruction_b = rb;
	}
	move->times_b = distance_from_top;
	//ft_printf("{32}You will use this instruction %u times.{0}\n\n", move->times);
}

void	move_to_bottom(t_data *data, t_index idx, t_move *move)
{
	size_t	distance_from_bottom;

	//ft_printf("{34}Moving index %u to bottom.{0}\n", idx);
	distance_from_bottom = idx;
	if (distance_from_bottom < data->a.top / 2)
	{
		distance_from_bottom = data->a.top - idx;
		move->instruction = ra;
		//ft_printf("{31}Instruction used will be RA.{0}\n");
	}
	else
	{
		//ft_printf("{31}Instruction used will be RRA.{0}\n");
		move->instruction = rra;
	}
	move->times = distance_from_bottom;
	//ft_printf("{32}You will use this instruction %u times.{0}\n\n", move->times);
}

t_move	prepare_stack_b(t_data *data, t_element to_push)
{

}

/* Returns what you must do in order to have the stack A ready to welcome the
 * element to push. */

t_move	prepare_stack_a(t_data *data, t_element to_push, t_move *move)
{
	t_index	i;
	size_t	distance_from_top;

	i = data->a.top - 1;
	distance_from_top = 0;
	move->after_push = 0;
	while (i > 0)
	{
		if (is_in_between(data->a.content[i].sort_idx,
					data->a.content[i - 1].sort_idx, to_push.sort_idx))
		{
			move_to_top(data, i - 1, move);
			return (*move);
		}
		i--;
	}
	if (i == 0)
	{
		if (is_in_between(data->a.content[0].sort_idx,
					data->a.content[data->a.top - 1].sort_idx, to_push.sort_idx))
		{
			move->instruction = pa;
			move->times = 1;
			//ft_printf("{36}Special case!{0}\nYou just have to push it man.");
		}
		else
		{
			if (is_biggest(data, to_push))
			{
				//ft_printf("{35}The element to push will be the biggest of A.{0}\n");
				t_index	idx = find_biggest_in_a(data);
				if (idx != 0)
				{
					//ft_printf("{35}Dam. The biggest element of A is not at the bottom.{0}\n");
					move_to_bottom(data, idx, move);
				}
				else
				{
					/* 
					 * Here, we've to push and rotate.
					 * */
					move->instruction = ra;
					move->after_push = 1;
					move->times = 1;
					//ft_printf("{36}Do it yourself lazy boy.{0}\n");
				}
			}
			else
			{
				//ft_printf("{35}The element to push will be the smallest of A.{0}\n");
				t_index	idx = find_smallest_in_a(data);
				if (idx != data->a.top - 1)
				{
					//ft_printf("{35}Dam. The smallest element of A is not at the top.{0}\n");
					move_to_top(data, idx, move);
				}
				else
				{
					/*
					 * Here, we just have to push.
					 */
					move->instruction = pa;
					move->times = 1;
					//ft_printf("{36}Do it yourself lazy boy.{0}\n");
				}
			}
		}
	}
	return (*move);
}

int	main(int argc, char **argv)
{
	t_data	data = {0};

	if (!alloc_stack(&data.a, argc - 1)
			|| !alloc_stack(&data.b, argc -1))
		return (throw_error(data));
	if (fill_stack_from_args(&data.a, argc, argv) == -1)
		return (throw_error(data));

	index_stack(&data.a);

	data.median = data.a.top / 2 - 1;
	push_low_median(&data);
	push_high_median(&data);
	sort_stack_three(&data);
	//show_stacks(data);
	
	while (data.b.top)
	{
		ssize_t	i;
		t_move	best_move;

		best_move.times = 99999;
		best_move.times_b = 99999;
		i = data.b.top - 1;
		while (i >= 0)
		{
			t_move		current_move;
			t_element	temp;

			current_move.idx = i;

			temp = data.b.content[data.b.top - 1];

			move_to_top_b(&data, i, &current_move);
			data.b.content[data.b.top - 1] = data.b.content[i];
			prepare_stack_a(&data, data.b.content[data.b.top - 1], &current_move);

			data.b.content[data.b.top - 1] = temp;
			if ((current_move.times + current_move.times_b) < (best_move.times + best_move.times_b))
			{
				best_move = current_move;
			}
			i--;
		}
		do_op(&data, best_move.times_b, best_move.instruction_b);
		if (best_move.after_push)
		{
			pa(&data);
			ra(&data);
		}
		else
		{
			do_op(&data, best_move.times, best_move.instruction);
			if (best_move.instruction != pa)
				pa(&data);
		}
	}
	t_move	move;
	t_index	idx = find_smallest_in_a(&data);
	move_to_top(&data, idx, &move);
	do_op(&data, move.times, move.instruction);
	//ft_putstr("\n");
	launch_instructions(&data);
	/*char *line;
	while ((line = get_next_line(0)))
	{
		t_move move = prepare_stack_a(&data, data.b.content[data.b.top - 1]);
		if (strcmp(line, "ra\n") == 0)
			ra(&data);
		else if (strcmp(line, "rb\n") == 0)
			rb(&data);
		else if (strcmp(line, "rr\n") == 0)
			rr(&data);
		else if (strcmp(line, "sa\n") == 0)
			sa(&data);
		else if (strcmp(line, "sb\n") == 0)
			sb(&data);
		else if (strcmp(line, "ss\n") == 0)
			ss(&data);
		else if (strcmp(line, "rra\n") == 0)
			rra(&data);
		else if (strcmp(line, "rrb\n") == 0)
			rrb(&data);
		else if (strcmp(line, "rrr\n") == 0)
			rrr(&data);
		else if (strcmp(line, "pa\n") == 0)
			pa(&data);
		else if (strcmp(line, "pb\n") == 0)
			pb(&data);
		show_stacks(data);
		free(line);
	}*/

	//show_stacks(data);
	free_stack(data.a);
	free_stack(data.b);
	//printf("OK in %zu operations.\n", data.nbr);
	//printf("OK in %zu operations with improvements.\n", data.nbr2);
	return (0);
}

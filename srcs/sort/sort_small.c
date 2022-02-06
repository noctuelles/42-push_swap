/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 01:18:10 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/06 16:18:19 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Cas no 1
 * Si top > middle et que middle < bottom : ra
 *
 *	3	0		ra
 *	0	1
 *	1	3
 *
 *	3	1	0	sa and rra
 *	1	3	1
 *	0	0	3
 *
 * 1	0		sa
 * 0	1
 * 3	3
 *
 * 1	0		rra
 * 3	1
 * 0	3
 *
 * 0	1	0	rra and sa
 * 3	0	1
 * 1	3	3
 *
 * 0			sorted already
 * 1
 * 3
 *
 * 7
 * 1
 * 2
 * 8
 * 0
 *
 * 0
 * 2
 * 8
 *
 * 7
 * 1
 *
 * 7
 * 0
 * 2
 * 8
 *
 */
/*
void		sort_stack_three(t_data *data)
{
	int		*a_content;

	a_content = data->a.content;
	if (a_content[2] > a_content[1] && a_content[1] < a_content[0]
			&& a_content[0] < a_content[2])
		ra(data);
	else if (a_content[2] > a_content[1] && a_content[1] > a_content[0]
			&& a_content[0] < a_content[2])
	{
		sa(data);
		rra(data);
	}
	else if (a_content[2] > a_content[1] && a_content[1] < a_content[0]
			&& a_content[0] > a_content[2])
		sa(data);
	else if (a_content[2] < a_content[1] && a_content[1] > a_content[0]
			&& a_content[0] < a_content[2])
		rra(data);
	else if (a_content[2] < a_content[1] && a_content[1] > a_content[0]
			&& a_content[0] > a_content[2])
	{
		rra(data);
		sa(data);
	}
}

int		is_min(t_stack *stack, int i)
{
	size_t	j;

	j = 0;
	while (j < stack->top)
	{
		if (stack->content[j] < i)
			return (0);
		j++;
	}
	return (1);
}

int		is_max(t_stack *stack, int i)
{
	size_t	j;

	j = 0;
	while (j < stack->top)
	{
		if (stack->content[j] > i)
			return (0);
		j++;
	}
	return (1);
}

void	sort_stack_five(t_data *data)
{
	pb(data);
	pb(data);
	sort_stack_three(data);
	if (is_min(&data->a, data->b.content[1]))
		pa(data);
	else if (is_max(&data->a, data->b.content[1]))
	{
		pa(data);
		ra(data);
	}
	if (is_min(&data->a, data->b.content[0]))
		pa(data);
	else if (is_max(&data->a, data->b.content[0]))
	{
		pa(data);
		ra(data);
	}
}

void	sort_small_stack(t_data *data, size_t size)
{
	if (size == 2)
	{
		if (data->a.content[0] > data->a.content[1])
			sa(data);
	}
}*/

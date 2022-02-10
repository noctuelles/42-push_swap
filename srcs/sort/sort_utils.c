/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:00:09 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/10 19:19:17 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find_biggest_in_stack() finds the biggest element of in the stack specified
 * and returns his index.
 * find_smallest_in_a() finds the ..... and returns his index.*/ 

t_index	find_biggest_in_stack(t_stack stack)
{
	t_index	i;
	int		biggest;
	t_index	biggest_i;

	i = 0;
	biggest_i = 0;
	biggest = stack.content[i].value;
	while (++i < stack.top)
	{
		if (stack.content[i].value > biggest)
		{
			biggest_i = i;
			biggest = stack.content[i].value;
		}
	}
	return (biggest_i);
}

t_index	find_smallest_in_stack(t_stack stack)
{
	t_index	i;
	int		smallest;
	t_index	smallest_i;

	i = 0;
	smallest_i = 0;
	smallest = stack.content[i].value;
	while (++i < stack.top)
	{
		if (stack.content[i].value < smallest)
		{
			smallest_i = i;
			smallest = stack.content[i].value;
		}
	}
	return (smallest_i);
}

/* is_biggest_in_stack() returns true if the element to_push is the biggest in
 * the given stack. In my algorithm we're always checking in the stack A.
 * I don't need to make a function to check if an element is the smallest,
 * because in my algorithm, if it's not biggest, it's the smallest. */

t_bool	is_biggest(t_stack stack, t_element to_push)
{
	t_index	i;

	i = 0;
	while (i < stack.top)
	{
		if (stack.content[i].sort_idx > to_push.sort_idx)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/* is_in_beetween() check if the integer nbr is in the range a-b.
 * In other words, it checks if the assertion range_a < nbr < range_b is true.*/

t_bool	is_in_between(int range_a, int range_b, int nbr)
{
	if (range_a < range_b)
	{
		if (nbr > range_a && nbr < range_b)
			return (TRUE);
	}
	return (FALSE);
}

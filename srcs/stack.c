/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:12:57 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/05 18:26:05 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

t_stack	*alloc_stack(t_stack *stack, size_t stack_size) {
	stack->content = (int *) ft_calloc(stack_size, sizeof(int));
	if (!stack->content)
		return (NULL);
	stack->info = (t_content_info *) malloc(stack_size *
			sizeof(t_content_info));
	if (!stack->info)
	{
		free(stack->content);
		return (NULL);
	}
	stack->top = 0;
	return (stack);
}

/* check_stack_duplicate() Perform a sentry linear search on the stack to check
 * if a duplicate has been found. */

int		check_stack_duplicate(t_stack stack, int nbr)
{
	size_t	i;
	int		save;

	if (!stack.top)
		return (0);
	save = stack.content[stack.top - 1];
	stack.content[stack.top - 1] = nbr;
	i = 0;
	while (stack.content[i] != nbr)
		i++;
	stack.content[stack.top - 1] = save;
	if (i < (stack.top - 1) || stack.content[i] == nbr)
		return (1);
	else
		return (0);
}

/* index_stack() gives for each element in the given stack, based on their order
 * sort order.
 * Information are hold in the info structure. */

void	index_stack(t_stack *stack)
{
	t_index	i;
	t_index	j;
	t_index	sort_index;

	i = 0;
	while (i < stack->top)
	{
		j = 0;
		sort_index = 0;
		while (j < stack->top)
		{
			if (stack->content[i] > stack->content[j])
				sort_index++;
			j++;
		}
		stack->info[i].i = sort_index;
		i++;
	}
}

void	free_stack(t_stack stack)
{
	free(stack.content);
}

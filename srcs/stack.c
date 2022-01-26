/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:12:57 by plouvel           #+#    #+#             */
/*   Updated: 2022/01/26 16:25:41 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_stack	*alloc_stack(t_stack *stack, size_t stack_size)
{
	stack->content = (int *) calloc(stack_size, sizeof(int));
	if (!stack->content)
		return (NULL);
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

void	free_stack(t_stack stack)
{
	free(stack.content);
}

void	push(t_stack *stack, int i)
{
	stack->content[stack->top++] = i;
}

int	pop(t_stack *stack)
{
	if (stack->top != 0)
		return(stack->content[(stack->top--) - 1]);
	else
		return (0);
}

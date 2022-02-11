/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:12:57 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/11 18:19:35 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

t_stack	*alloc_stack(t_stack *stack, size_t stack_size)
{
	stack->content = (t_element *) ft_calloc(stack_size, sizeof(t_element));
	if (!stack->content)
		return (NULL);
	stack->top = 0;
	return (stack);
}

/* check_stack_duplicate() Perform a sentry linear search on the stack to check
 * if a duplicate has been found. */

int	check_stack_duplicate(t_stack stack, int nbr)
{
	size_t	i;
	int		save;

	if (!stack.top)
		return (0);
	save = stack.content[stack.top - 1].value;
	stack.content[stack.top - 1].value = nbr;
	i = 0;
	while (stack.content[i].value != nbr)
		i++;
	stack.content[stack.top - 1].value = save;
	if (i < (stack.top - 1) || stack.content[i].value == nbr)
		return (1);
	else
		return (0);
}

t_bool	is_stack_sorted(t_stack stack)
{
	t_index	i;

	i = stack.top;
	while (i > 1)
	{
		if (stack.content[i - 1].value > stack.content[i - 2].value)
			return (FALSE);
		i--;
	}
	return (TRUE);
}

void	free_stacks(t_data *data)
{
	free(data->a.content);
	data->a.content = NULL;
	free(data->b.content);
	data->b.content = NULL;
}

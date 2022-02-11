/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:09:59 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/11 18:15:43 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_HELPER_H
# define PUSH_SWAP_HELPER_H

/* Recurrent functions. */

static inline void	push(t_stack *stack, t_element elem)
{
	stack->content[stack->top++] = elem;
}

static inline t_element	pop(t_stack *stack)
{
	t_element	empty;

	if (stack->top != 0)
		return (stack->content[stack->top-- - 1]);
	ft_memset(&empty, 0, sizeof(t_element));
	return (empty);
}

#endif

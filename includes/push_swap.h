/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:39:55 by plouvel           #+#    #+#             */
/*   Updated: 2022/01/26 16:14:06 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

# define STR_ERROR "Error\n"
# define STR_INT_MAX "2147483647"
# define STR_INT_MIN "-2147483648"

typedef struct s_stack
{
	int				*content;
	size_t			top;
}				t_stack;

typedef struct s_push_swap
{
	t_stack	a;
	t_stack	b;
}				t_push_swap;

/* stack.c */

t_stack	*alloc_stack(t_stack *stack, size_t stack_size);
void	free_stack(t_stack stack);
int		check_stack_duplicate(t_stack stack, int nbr);
void	push(t_stack *stack, int i);
int		pop(t_stack *stack);

/* operation.c */

#endif

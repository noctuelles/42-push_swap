/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:39:55 by plouvel           #+#    #+#             */
/*   Updated: 2022/01/30 01:11:23 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

# define STR_ERROR "Error\n"
# define SILENT_OUTPUT 1
# define STDOUT    1

typedef struct s_stack
{
	int		*content;
	size_t	top;
}				t_stack;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
}				t_data;

/* stack.c */

t_stack	*alloc_stack(t_stack *stack, size_t stack_size);
void	free_stack(t_stack stack);
int		check_stack_duplicate(t_stack stack, int nbr);

static inline void	push(t_stack *stack, int i)
{
	stack->content[stack->top++] = i;
}

static inline int	pop(t_stack *stack)
{
	if (stack->top != 0)
		return(stack->content[(stack->top--) - 1]);
	else
		return (0);
}

/* operation.c */

/* parsing.c */

int		fill_stack_from_args(t_stack *stack, int argc, char **argv);

#endif

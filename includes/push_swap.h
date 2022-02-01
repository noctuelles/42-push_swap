/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:39:55 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/01 22:21:38 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

# define STR_ERROR "Error\n"

# define SILENT_OUTPUT 1

# define STR_RA "ra\n"
# define STR_RB "rb\n"
# define STR_RR "rr\n"

# define STR_RRA "rra\n"
# define STR_RRB "rrb\n"
# define STR_RRR "rrr\n"

# define STR_PA "pa\n"
# define STR_PB "pb\n"

# define STR_SA "sa\n"
# define STR_SB "sb\n"
# define STR_SS "ss\n"


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

/* rotate.c */

void	rb(t_data *data);
void	ra(t_data *data);
void	rr(t_data *data);

/* reverse_rotate.c */

void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

/* push.c */

void	pa(t_data *data);
void	pb(t_data *data);

/* swap.c */

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);

/* debug_tools.c */

void	show_stacks(t_data data);

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

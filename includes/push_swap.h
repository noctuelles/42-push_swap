/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */ /*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:39:55 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/09 17:06:07 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include "libft.h"

# define STR_ERROR "Error\n"

//# define OUTPUT 1

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

typedef struct s_element
{
	int		value;
	t_index	sort_idx;
}				t_element;

typedef struct s_stack
{
	t_element	*content;
	t_index			top;
}				t_stack;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
	size_t	nbr;
	size_t	nbr2;
	t_list	*instructions;
}				t_data;

typedef void (*t_instruction)(t_data *);

typedef struct s_move
{
	t_index			idx;
	t_instruction	instruction_b;
	size_t			times_b;
	t_instruction	instruction;
	size_t			times;

	t_instruction	stack_a_inst;
	size_t			stack_a_inst_rpt;
	t_instruction	stack_b_inst;
	size_t			stack_b_inst_rpt;
	t_bool			after_push;
}				t_move;

/* stack.c */

t_stack	*alloc_stack(t_stack *stack, size_t stack_size);
int		check_stack_duplicate(t_stack stack, int nbr);
t_bool	is_stack_sorted(t_stack stack);
void	free_stacks(t_data *data);

/* sort/sort_helper.c */

void	sort_three_elem_stack(t_data *data);

/* sort/sort_init.c */

void	index_stack(t_stack *stack);
void	init_stacks(t_data *data);

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

/* parsing.c */

int		fill_stack_from_args(t_stack *stack, int argc, char **argv);

/* instructions.c */


void	launch_instructions(t_data *data);
t_list	*add_instruction(t_data *data, t_instruction instruction);

/* Recurrent functions. */

static inline void	push(t_stack *stack, t_element elem)
{
	stack->content[stack->top].value = elem.value;
	stack->content[stack->top].sort_idx = elem.sort_idx;
	stack->top++;
}

static inline t_element	pop(t_stack *stack)
{
	t_element	empty;

	if (stack->top != 0)
		return(stack->content[stack->top-- - 1]);
	ft_memset(&empty, 0, sizeof(t_element));
	return (empty);
}

#endif

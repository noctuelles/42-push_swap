/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:37:10 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/09 16:51:12 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <unistd.h>

/* These two inline function are only here to comply with the norms. */

static inline void swap_a(t_data *data, t_element *last_val, t_element *saved,
																	ssize_t *i)
{
	*saved = data->a.content[*i];
	data->a.content[*i] = *last_val;
	*last_val = *saved;
	(*i)--;
}

static inline void swap_b(t_data *data, t_element *last_val, t_element *saved,
																	ssize_t *i)
{
	*saved = data->b.content[*i];
	data->b.content[*i] = *last_val;
	*last_val = *saved;
	(*i)--;
}

/* Reverse rotate the stack a. Shift down all elements by 1. The last element
 * becomes the first one. */

void	rra(t_data *data)
{
	ssize_t		i;
	t_element	last_val;
	t_element	saved;

	if (data->a.top < 2)
		return ;
	last_val = data->a.content[data->a.top - 1];
	i = data->a.top - 2;
	while (i >= 0)
		swap_a(data, &last_val, &saved, &i);
	data->a.content[data->a.top - 1] = last_val;
	data->nbr++;
	add_instruction(data, rra);
#ifdef OUTPUT
	write(STDOUT, STR_RRA, sizeof(STR_RRA) - 1);
#endif
}

/* Reverse rotate the stack b. Shift down all elements by 1. The last element
 * becomes the first one. */

void	rrb(t_data *data)
{
	ssize_t	i;
	t_element		last_val;
	t_element		saved;

	if (data->b.top < 2)
		return ;
	last_val = data->b.content[data->b.top - 1];
	i = data->b.top - 2;
	while (i >= 0)
		swap_b(data, &last_val, &saved, &i);
	data->b.content[data->b.top - 1] = last_val;
	data->nbr++;
	add_instruction(data, rrb);
#ifdef OUTPUT
	write(STDOUT, STR_RRB, sizeof(STR_RRB) - 1);
#endif
}

/* Do rra and rrb at the same time. */

void	rrr(t_data *data)
{
	ssize_t	i;
	t_element		last_val;
	t_element		saved;

	if (data->a.top >= 2)
	{
		last_val = data->a.content[data->a.top - 1];
		i = data->a.top - 2;
		while (i >= 0)
			swap_a(data, &last_val, &saved, &i);
		data->a.content[data->a.top - 1] = last_val;
	}
	if (data->b.top < 2)
		return ;
	last_val = data->b.content[data->b.top - 1];
	i = data->b.top - 2;
	while (i >= 0)
		swap_b(data, &last_val, &saved, &i);
	data->b.content[data->b.top - 1] = last_val;
	data->nbr++;
	write(STDOUT, STR_RRR, sizeof(STR_RRR) - 1);
}

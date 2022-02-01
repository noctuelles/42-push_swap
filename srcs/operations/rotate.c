/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:41:56 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/01 23:12:35 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <unistd.h>

/* These two inline function are only here to comply with the norms. */

static inline void swap_a(t_data *data, int *last_val, int *saved, size_t *i)
{
	*saved = data->a.content[*i];
	data->a.content[*i] = *last_val;
	*last_val = *saved;
	(*i)++;
}

static inline void swap_b(t_data *data, int *last_val, int *saved, size_t *i)
{
	*saved = data->b.content[*i];
	data->b.content[*i] = *last_val;
	*last_val = *saved;
	(*i)++;
}

/* Rotate the stack a. Shift up all elements by 1. The first element becomes
 * the last one. */

void	ra(t_data *data)
{
	size_t	i;
	int		last_val;
	int		saved;

	if (data->a.top < 2)
		return ;
	last_val = data->a.content[0];
	i = 1;
	while (i < data->a.top)
		swap_a(data, &last_val, &saved, &i);
	data->a.content[0] = last_val;
	write(STDOUT, STR_RA, sizeof(STR_RA) - 1);
}

/* Rotate the stack b. Shift up all elements by 1. The first element becomes
 * the last one. */

void	rb(t_data *data)
{
	size_t	i;
	int		last_val;
	int		saved;

	if (data->b.top < 2)
		return ;
	last_val = data->b.content[0];
	i = 1;
	while (i < data->b.top)
		swap_b(data, &last_val, &saved, &i);
	data->b.content[0] = last_val;
	write(STDOUT, STR_RB, sizeof(STR_RB) - 1);
}

/* Do ra and rb at the same time. */

void	rr(t_data *data)
{
	size_t	i;
	int		last_val;
	int		saved;

	if (data->a.top >= 2)
	{
		last_val = data->a.content[0];
		i = 1;
		while (i < data->a.top)
			swap_a(data, &last_val, &saved, &i);
		data->a.content[0] = last_val;
	}
	if (data->b.top < 2)
		return ;
	last_val = data->b.content[0];
	i = 1;
	while (i < data->b.top)
		swap_b(data, &last_val, &saved, &i);
	data->b.content[0] = last_val;
	write(STDOUT, STR_RR, sizeof(STR_RR) - 1);
}

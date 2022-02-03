/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:58:08 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/03 15:05:34 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_biggest_a(t_data *data)
{
	size_t	i;

	i = data->a.biggest_nbr_i;
	if (i == 0)
		return ;
	if (i <= (data->a.top / 2) - 1)
	{
		while (i--)
			rra(data);
	}
	else
	{
		while (i++ < data->a.top)
			ra(data);
	}
	data->a.biggest_nbr_i = 0;
}

size_t	find_biggest_in_b(t_data *data)
{
	ssize_t	i;
	size_t	biggest_nbr_i;
	int		max;

	if (data->b.top == 2)	// si la stack b est de deux elem.
		return (0);
	i = 1;
	max = data->b.content[0];
	biggest_nbr_i = 0;
	while (i < data->b.top - 1)
	{
		if (data->b.content[i] > max)
		{
			max = data->b.content[i];
			biggest_nbr_i = i;
		}
		i++;
	}
	return (biggest_nbr_i);
}

void	shift_biggest_b(t_data *data)
{
	ssize_t	i;

	i = data->b.biggest_nbr_i; 
	if (i == data->b.top - 1)
	{
		data->b.biggest_nbr_i = find_biggest_in_b(data);
		return ;
	}
	if (i <= (data->b.top / 2) - 1)
	{
		while (i-- >= 0)
			rrb(data);
	}
	else
	{
		while (i++ < data->b.top - 1)
			rb(data);
	}
	data->b.biggest_nbr_i = find_biggest_in_b(data);
}

void	transfer_b(t_data *data)
{
	size_t	i;

	i = data->a.top - 1;
	while (i-- > 0)
		pb(data);
}

void	sort(t_data *data)
{
	size_t	i;
	size_t	b_size;

	i = 0;
	b_size = data->b.top;
	while (i++ < b_size - 1)
	{
		shift_biggest_b(data);
		pa(data);
	}
	pa(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:42:11 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/07 19:51:40 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"
#include "get_next_line.h"

static inline int	throw_error(t_data data)
{
	ft_putstr_fd(STR_ERROR, STDERR);
	free_stack(data.a);
	free_stack(data.b);
	return (1);
}

#include <stdio.h>

void	do_op(t_data *data, size_t t, void (*f)(t_data *))
{
	size_t	i;

	i = 0;
	while (i++ < t)
		f(data);
}

void	push_low_median(t_data *data)
{
	t_index	i;

	i = 0;
	//printf("median is %lu\n", data->median);
	while (i <= data->median)
	{
		//show_stacks(*data);
		//getchar();
		if (data->a.content[data->a.top - 1].sort_idx <= data->median)
		{
			//printf("%lu <= %lu\n",data->a.content[data->a.top - 1].sort_idx, data->median);
			pb(data);
			i++;
		}
		else
			ra(data);
	}
}

void	push_high_median(t_data *data)
{
	while (data->a.top > 3)
		pb(data);
}

size_t	get_stack_a_config_cost(t_element elem)
{

}

int	main(int argc, char **argv)
{
	t_data	data = {0};

	if (!alloc_stack(&data.a, argc - 1)
			|| !alloc_stack(&data.b, argc -1))
		return (throw_error(data));
	if (fill_stack_from_args(&data.a, argc, argv) == -1)
		return (throw_error(data));
	index_stack(&data.a);
	data.median = data.a.top / 2 - 1;
	printf("median is %lu\n", data.median);
	push_low_median(&data);
	push_high_median(&data);
	sort_stack_three(&data);
	show_stacks(data);
	
	char *line;
	while ((line = get_next_line(0)))
	{
		if (strcmp(line, "ra\n") == 0)
			ra(&data);
		else if (strcmp(line, "rb\n") == 0)
			rb(&data);
		else if (strcmp(line, "rr\n") == 0)
			rr(&data);
		else if (strcmp(line, "sa\n") == 0)
			sa(&data);
		else if (strcmp(line, "sb\n") == 0)
			sb(&data);
		else if (strcmp(line, "ss\n") == 0)
			ss(&data);
		else if (strcmp(line, "rra\n") == 0)
			rra(&data);
		else if (strcmp(line, "rrb\n") == 0)
			rrb(&data);
		else if (strcmp(line, "rrr\n") == 0)
			rrr(&data);
		else if (strcmp(line, "pa\n") == 0)
			pa(&data);
		else if (strcmp(line, "pb\n") == 0)
			pb(&data);
		show_stacks(data);
		free(line);
	}

	free_stack(data.a);
	free_stack(data.b);
	printf("OK in %zu operations.\n", data.nbr);
	return (0);
}

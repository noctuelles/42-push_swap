/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:42:11 by plouvel           #+#    #+#             */
/*   Updated: 2022/01/30 01:10:18 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rotate.h"
#include "push.h"
#include <stdlib.h>
#include "push_swap.h"

static inline int	throw_error(t_data data)
{
	fputs(STR_ERROR, stdout);
	free_stack(data.a);
	free_stack(data.b);
	return (1);
}

void	show_stacks(t_data data)
{
	int	i;

	if (data.a.top > data.b.top)
		i = data.a.top - 1;
	else if (data.a.top < data.b.top)
		i = data.b.top - 1;
	else
		i = data.a.top - 1;
	while (i >= 0)
	{
		if (i >= data.b.top)
			printf("%d\n", data.a.content[i--]);
		else if (i >= data.a.top)
			printf("  %d\n", data.b.content[i--]);
		else
		{
			printf("%d %d\n", data.a.content[i], data.b.content[i]);
			i--;
		}
	}
	puts("-  -\na  b");
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!alloc_stack(&data.a, argc - 1)
			|| !alloc_stack(&data.b, argc -1))
		return (throw_error(data));
	if (fill_stack_from_args(&data.a, argc, argv) == -1)
		return (throw_error(data));
	pb(&data);
	pb(&data);
	pb(&data);
	rr(&data);
	show_stacks(data);
	free_stack(data.a);
	free_stack(data.b);
	puts("OK.");
	return (0);
}

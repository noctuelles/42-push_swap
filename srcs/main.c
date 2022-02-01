/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:42:11 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/01 23:12:41 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	t_data	data;

	if (!alloc_stack(&data.a, argc - 1)
			|| !alloc_stack(&data.b, argc -1))
		return (throw_error(data));
	if (fill_stack_from_args(&data.a, argc, argv) == -1)
		return (throw_error(data));
	show_stacks(data);
	do_op(&data, 3, pb);
	show_stacks(data);
	do_op(&data, 2, rrr);
	show_stacks(data);
	free_stack(data.a);
	free_stack(data.b);
	puts("OK.");
	return (0);
}

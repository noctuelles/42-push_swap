/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:42:11 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/10 19:19:14 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"
#include "get_next_line.h"

static inline int	throw_error(t_data *data)
{
	ft_putstr_fd(STR_ERROR, STDERR);
	free_stacks(data);
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

/* Returns what you must do in order to have the stack A ready to welcome the
 * element to push. */

int	main(int argc, char **argv)
{
	t_data	data = {0};

	if (!alloc_stack(&data.a, argc - 1)
			|| !alloc_stack(&data.b, argc -1))
		return (throw_error(&data));
	if (fill_stack_from_args(&data.a, argc, argv) == -1)
		return (throw_error(&data));
	if (!is_stack_sorted(data.a))
	{
		index_stack(&data.a);
		if (argc == 4)
			sort_three_elem_stack(&data);
		else
		{
			init_stacks(&data);
		}
		show_stacks(data);
	}
	free_stacks(&data);
	return (0);
}

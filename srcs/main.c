/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:42:11 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/01 14:45:27 by plouvel          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_data	data;

	if (!alloc_stack(&data.a, argc - 1)
			|| !alloc_stack(&data.b, argc -1))
		return (throw_error(data));
	if (fill_stack_from_args(&data.a, argc, argv) == -1)
		return (throw_error(data));
	pb(&data);
	show_stacks(data);
	free_stack(data.a);
	free_stack(data.b);
	puts("OK.");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:42:11 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/16 21:26:53 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	throw_error(t_data *data)
{
	ft_putstr_fd(STR_ERROR, STDERR);
	ft_lstclear_nocnt_alloc(&data->insts);
	free_stacks(data);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 2)
	{
		ft_memset(&data, 0, sizeof(t_data));
		if (!alloc_stack(&data.a, argc - 1) || !alloc_stack(&data.b, argc - 1))
			return (throw_error(&data));
		if (fill_stack_from_args(&data.a, argc, argv) == -1)
			return (throw_error(&data));
		if (!is_stack_sorted(data.a))
		{
			index_stack(&data.a);
			if (argc <= 4)
				sort_small_stack(&data, argc);
			else
			{
				init_stacks(&data);
				do_sort(&data);
			}
			print_instructions(&data);
		}
		free_stacks(&data);
		ft_lstclear_nocnt_alloc(&data.insts);
	}
	return (0);
}

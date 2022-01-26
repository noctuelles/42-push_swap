/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:42:11 by plouvel           #+#    #+#             */
/*   Updated: 2022/01/26 16:36:35 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

static inline int	throw_error(t_push_swap push_swap)
{
	fputs(STR_ERROR, stdout);
	free_stack(push_swap.a);
	free_stack(push_swap.b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_push_swap	push_swap;

	if (!alloc_stack(&push_swap.a, argc - 1)
			|| !alloc_stack(&push_swap.b, argc -1))
		return (throw_error(push_swap));
	if (fill_stack_from_args(&push_swap.a, argc, argv) == -1)
		return (throw_error(push_swap));
	free_stack(push_swap.a);
	free_stack(push_swap.b);
	puts("OK.");
	return (0);
}

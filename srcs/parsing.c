/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:15:32 by plouvel           #+#    #+#             */
/*   Updated: 2022/01/26 16:36:33 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <string.h>

/* get_int_weight() returns how many digits they are in a number.
 * it adds one if the number is negative. */ 

static size_t	get_int_digits(int i)
{
	size_t	digits;

	if (i == 0)
		return (1);
	if (i < 0)
		digits = 1;
	else
		digits = 0;
	while (i % 10 != 0)
	{
		digits++;
		i /= 10;
	}
	return (digits);
}

/* is_integer returns() NULL if the int *i is not a correct integer.
 * It checks if the number of digits in the number match the len of the str-
 * -ing. */

static int	*is_integer(const char *str, int *i)
{
	size_t	int_digits;

	if (!isdigit(str[0]))
			return (NULL);
	int_digits = get_int_digits(*i);
	if ((strlen(str) != int_digits))
		return (NULL);
	return (i);
}

/* fill_stack_from_args() is straightforward. */

int	fill_stack_from_args(t_stack *stack, int argc, char **argv)
{
	size_t	n;
	int		i;

	n = 1;
	while (n < argc)
	{
		i = atoi(argv[n]);
		if (is_integer((const char *) argv[n], &i))
		{
			if (!check_stack_duplicate(*stack, i))
				push(stack, i);
			else
				return (-1);
		}
		else
			return (-1);
		n++;	
	}
	return (0);
}

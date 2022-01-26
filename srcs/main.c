/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:42:11 by plouvel           #+#    #+#             */
/*   Updated: 2022/01/26 16:14:06 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "push_swap.h"


/* get_int_weight() returns how many digits they are in a number.
 * it adds one if the number is negative. */ 

size_t	get_int_digits(int i)
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

int	*is_integer(const char *str, int *i)
{
	size_t	int_digits;

	int_digits = get_int_digits(*i);
	if (strlen(str) != int_digits)
	{
		return (NULL);
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	int		i;
	size_t	n;

	n = 1;
	alloc_stack(&a, argc - 1);
	//printf("%zu\n", get_int_weight(atoi(argv[1])));
	while (n < argc)
	{
		i = atoi(argv[n]);
		if (is_integer((const char *) argv[n], &i))
		{
			if (!check_stack_duplicate(a, i))
				push(&a, i);
			else
			{
				puts("Find duplicate, bye.");
				break ;
			}
		}
		else
		{
			puts("This is a bad integer, bye.");
			break ;
		}
		n++;
	}
	puts("OK.");
	free_stack(a);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:15:32 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/11 18:18:56 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_helper.h"
#include "libft.h"

/* get_int_weight() returns how many digits they are in a number.
 * it adds one if the number is negative.
 * So -12 gives 3 end result in get_int_digits function.
 * 12 gives 2 end result in get_int_digits function. */

static inline size_t	get_int_digits(int i)
{
	size_t	digits;

	if (i < 0)
		digits = 2;
	else
		digits = 1;
	while (i / 10)
	{
		digits++;
		i /= 10;
	}
	return (digits);
}

/*
 * ft_strlen_skip_beg_zero() computes the lenght of the string without the
 * zeroes at the beginning.
 * The string "-000012" returns 3.
 * The string "-12" returns 3.
 * The string "-12000" returns 6.
 */

static size_t	ft_strlen_skip_beg_zero(const char *str)
{
	t_index	i;
	size_t	len_no_zero;

	i = 0;
	len_no_zero = 0;
	if (str[0] == '0' && str[1] == '\0')
		return (1);
	if (str[0] == '-')
	{
		i++;
		len_no_zero++;
	}
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		len_no_zero++;
		i++;
	}
	return (len_no_zero);
}

/* is_integer returns() NULL if the int *i is not a correct integer.
 * It checks if the number of digits in the number match the len of the str-
 * -ing (without beginning zero. */

static inline int	*is_integer(const char *str, int *i)
{
	size_t	int_digits;

	int_digits = get_int_digits(*i);
	if ((ft_strlen_skip_beg_zero(str) != int_digits))
		return (NULL);
	return (i);
}

/* fill_stack_from_args() is straightforward. 
 * It performs all the necessary check to see if the number is compatible with
 * the subject requirements.
 * */

int	fill_stack_from_args(t_stack *stack, int argc, char **argv)
{
	t_index		i;
	t_element	elem;

	i = argc;
	while (i > 1)
	{
		elem.value = ft_atoi(argv[i - 1]);
		elem.sort_idx = 0;
		if (is_integer((const char *) argv[i - 1], &elem.value))
		{
			if (!check_stack_duplicate(*stack, elem.value))
				push(stack, elem);
			else
				return (-1);
		}
		else
			return (-1);
		i--;
	}
	return (0);
}

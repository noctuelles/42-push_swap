/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:15:32 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/01 14:14:35 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
	size_t	i;
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
	size_t	n;
	int		i;

	n = 1;
	while (n < argc)
	{
		i = ft_atoi(argv[n]);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 01:18:10 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/07 19:51:40 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Cas no 1
 * Si top > middle et que middle < bottom : ra
 *
 *	3	0		ra
 *	0	1
 *	1	3
 *
 *	3	1	0	sa and rra
 *	1	3	1
 *	0	0	3
 *
 * 1	0		sa
 * 0	1
 * 3	3
 *
 * 1	0		rra
 * 3	1
 * 0	3
 *
 * 0	1	0	rra and sa
 * 3	0	1
 * 1	3	3
 *
 * 0			sorted already
 * 1
 * 3
 *
 * 7
 * 1
 * 2
 * 8
 * 0
 *
 * 0
 * 2
 * 8
 *
 * 7
 * 1
 *
 * 7
 * 0
 * 2
 * 8
 *
 */

void		sort_stack_three(t_data *data)
{
	t_element	*a_content;

	a_content = data->a.content;
	if (a_content[2].value > a_content[1].value && a_content[1].value < a_content[0].value
			&& a_content[0].value < a_content[2].value)
		ra(data);
	else if (a_content[2].value > a_content[1].value && a_content[1].value > a_content[0].value
			&& a_content[0].value < a_content[2].value)
	{
		sa(data);
		rra(data);
	}
	else if (a_content[2].value > a_content[1].value && a_content[1].value < a_content[0].value
			&& a_content[0].value > a_content[2].value)
		sa(data);
	else if (a_content[2].value < a_content[1].value && a_content[1].value > a_content[0].value
			&& a_content[0].value < a_content[2].value)
		rra(data);
	else if (a_content[2].value < a_content[1].value && a_content[1].value > a_content[0].value
			&& a_content[0].value > a_content[2].value)
	{
		rra(data);
		sa(data);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:25:18 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/07 17:33:45 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*add_instruction(t_data *data, t_instruction instruction)
{
	t_list	*elem;

	elem = ft_lstnew((void *) instruction);
	if (!elem)
		return (NULL);
	ft_lstadd_back(&data->instructions, elem);
	return (data->instructions);
}

static inline t_instruction	factor_instruction(t_instruction current,
															t_instruction next)
{
	if ((current == sa && next == sb) || (current == sb && next == sa))
		return (ss);
	if ((current == ra && next == rb) || (current == rb && next == ra))
		return (rr);
	if ((current == rra && next == rrb) || (current == rrb && next == rra))
		return (rrr);
	return (current);
}

void	launch_instructions(t_data *data)
{
	t_list			*elem;
	t_instruction	current_instruction;
	t_instruction	next_instruction;
	t_instruction	rslt;

	elem = data->instructions;
	while (elem)
	{
		current_instruction = (t_instruction) elem->content;
		if (elem->next)
		{
			next_instruction = (t_instruction) elem->next->content;
			rslt = factor_instruction(current_instruction, next_instruction);
			rslt(data);
			if (rslt != current_instruction)
				elem = elem->next->next;
			else
				elem = elem->next;
		}
		else
		{
			current_instruction(data);
			break ;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:25:18 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/11 18:19:52 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*add_instruction(t_data *data, t_inst inst)
{
	t_list	*elem;

	elem = ft_lstnew((void *) inst);
	if (!elem)
		return (NULL);
	ft_lstadd_back(&data->insts, elem);
	return (data->insts);
}

static inline int	multiple_inst(t_inst curr, t_inst next)
{
	int	mult_inst;

	mult_inst = 1;
	if ((curr == sa && next == sb) || (curr == sb && next == sa))
		ft_putstr(STR_SS);
	else if ((curr == ra && next == rb) || (curr == rb && next == ra))
		ft_putstr(STR_RR);
	else if ((curr == rra && next == rrb) || (curr == rrb && next == rra))
		ft_putstr(STR_RRR);
	else
		mult_inst = 0;
	return (mult_inst);
}

static inline void	normal_inst(t_inst current)
{
	if (current == ra)
		ft_putstr(STR_RA);
	else if (current == rb)
		ft_putstr(STR_RB);
	else if (current == rra)
		ft_putstr(STR_RRA);
	else if (current == rrb)
		ft_putstr(STR_RRB);
	else if (current == sa)
		ft_putstr(STR_SA);
	else if (current == sb)
		ft_putstr(STR_SB);
	else if (current == pa)
		ft_putstr(STR_PA);
	else if (current == pb)
		ft_putstr(STR_PB);
}

void	print_instructions(t_data *data)
{
	t_list	*elem;
	t_inst	current_inst;
	t_inst	next_inst;

	elem = data->insts;
	while (elem)
	{
		current_inst = (t_inst) elem->content;
		if (elem->next)
		{
			next_inst = (t_inst) elem->next->content;
			if (multiple_inst(current_inst, next_inst))
				elem = elem->next->next;
			else
			{
				normal_inst(current_inst);
				elem = elem->next;
			}
		}
		else
		{
			normal_inst(current_inst);
			break ;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:25:18 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/09 16:53:35 by plouvel          ###   ########.fr       */
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

static inline int	multiple_instruction(t_instruction current,
															t_instruction next)
{
	if ((current == sa && next == sb) || (current == sb && next == sa))
	{
		ft_putstr("ss\n");
		return (1);
	}
	if ((current == ra && next == rb) || (current == rb && next == ra))
	{
		ft_putstr("rr\n");
		return (1);
	}
	if ((current == rra && next == rrb) || (current == rrb && next == rra))
	{
		ft_putstr("rrr\n");
		return (1);
	}
	return (0);
}

static inline void	normal_instruction(t_instruction current)
{
	if (current == ra)
		ft_putstr("ra\n");
	else if (current == rb)
		ft_putstr("rb\n");
	else if (current == rra)
		ft_putstr("rra\n");
	else if (current == rrb)
		ft_putstr("rrb\n");
	else if (current == sa)
		ft_putstr("sa\n");
	else if (current == sb)
		ft_putstr("sb\n");
	else if (current == pa)
		ft_putstr("pa\n");
	else if (current == pb)
		ft_putstr("pb\n");
}

void	launch_instructions(t_data *data)
{
	t_list			*elem;
	t_instruction	current_instruction;
	t_instruction	next_instruction;

	elem = data->instructions;
	while (elem)
	{
		current_instruction = (t_instruction) elem->content;
		if (elem->next)
		{
			next_instruction = (t_instruction) elem->next->content;
			if(multiple_instruction(current_instruction, next_instruction))
				elem = elem->next->next;
			else
			{
				normal_instruction(current_instruction);
				elem = elem->next;
			}
			data->nbr2++;
		}
		else
		{
			data->nbr2++;
			normal_instruction(current_instruction);
			break ;
		}
	}
}

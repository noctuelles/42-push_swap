/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:47:47 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/09 16:51:14 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
# include "libft.h"
# include <unistd.h>

void	sa(t_data *data)
{
	t_element	tmp;

	if (data->a.top < 2)
		return ;
	tmp = data->a.content[data->a.top - 1];
	data->a.content[data->a.top - 1] = data->a.content[data->a.top - 2];
	data->a.content[data->a.top - 2] = tmp;
	data->nbr++;
	add_instruction(data, sa);
#ifdef OUTPUT
	write(STDOUT, STR_SA, sizeof(STR_SA) - 1);
#endif
}

void	sb(t_data *data)
{
	t_element	tmp;

	if (data->a.top < 2)
		return ;
	tmp = data->a.content[data->a.top - 1];
	data->a.content[data->a.top - 1] = data->a.content[data->a.top - 2];
	data->a.content[data->a.top - 2] = tmp;
	data->nbr++;
	add_instruction(data, sb);
#ifdef OUTPUT
	write(STDOUT, STR_SB, sizeof(STR_SB) - 1);
#endif
}

void	ss(t_data *data)
{
	t_element	tmp;

	if (data->a.top < 2 || data->b.top < 2)
		return ;
	tmp = data->a.content[data->a.top - 1];
	data->a.content[data->a.top - 1] = data->a.content[data->a.top - 2];
	data->a.content[data->a.top - 2] = tmp;
	tmp = data->b.content[data->b.top - 1];
	data->b.content[data->b.top - 1] = data->b.content[data->b.top - 2];
	data->b.content[data->b.top - 2] = tmp;
	data->nbr++;
	write(STDOUT, STR_SS, sizeof(STR_SS) - 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:47:47 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/11 18:20:27 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	sa(t_data *data)
{
	t_element	tmp;

	if (data->a.top < 2)
		return ;
	tmp = data->a.content[data->a.top - 1];
	data->a.content[data->a.top - 1] = data->a.content[data->a.top - 2];
	data->a.content[data->a.top - 2] = tmp;
	if (!add_instruction(data, sa))
		exit(throw_error(data));
}

void	sb(t_data *data)
{
	t_element	tmp;

	if (data->a.top < 2)
		return ;
	tmp = data->a.content[data->a.top - 1];
	data->a.content[data->a.top - 1] = data->a.content[data->a.top - 2];
	data->a.content[data->a.top - 2] = tmp;
	if (!add_instruction(data, sb))
		exit(throw_error(data));
}

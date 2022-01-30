/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 23:35:40 by plouvel           #+#    #+#             */
/*   Updated: 2022/01/30 01:18:22 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATE_H
# define ROTATE_H

# include "push_swap.h"
# include <unistd.h>

# define STR_RA "ra\n"
# define STR_RB "rb\n"
# define STR_RR "rr\n"

static inline void	ra(t_data *data)
{
	size_t	i;
	int		last_val;
	int		saved;

	if (data->a.top < 2)
		return ;
	last_val = data->a.content[0];
	i = 1;
	while (i < data->a.top)
	{
		saved = data->a.content[i];
		data->a.content[i++] = last_val;
		last_val = saved;
	}
	data->a.content[0] = last_val;
# ifndef SILENT_OUTPUT
	write(STDOUT, STR_RA, sizeof(STR_RA) - 1);
# endif
}

static inline void	rb(t_data *data)
{
	size_t	i;
	int		last_val;
	int		saved;

	if (data->b.top < 2)
		return ;
	last_val = data->b.content[0];
	i = 1;
	while (i < data->b.top)
	{
		saved = data->b.content[i];
		data->b.content[i++] = last_val;
		last_val = saved;
	}
	data->b.content[0] = last_val;
# ifndef SILENT_OUTPUT
	write(STDOUT, STR_RB, sizeof(STR_RB) - 1);
# endif
}

static inline void	rr(t_data *data)
{
	size_t	i;
	int		last_val;
	int		saved;

	if (data->a.top < 2 || data->b.top < 2)
		return ;
	last_val = data->a.content[0];
	i = 1;
	while (i < data->a.top)
	{
		saved = data->a.content[i];
		data->a.content[i++] = last_val;
		last_val = saved;
	}
	data->a.content[0] = last_val;
	last_val = data->b.content[0];
	i = 1;
	while (i < data->b.top)
	{
		saved = data->b.content[i];
		data->b.content[i++] = last_val;
		last_val = saved;
	}
	data->b.content[0] = last_val;
# ifndef SILENT_OUTPUT
	write(STDOUT, STR_RR, sizeof(STR_RR) - 1);
# endif
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 23:07:31 by plouvel           #+#    #+#             */
/*   Updated: 2022/01/30 01:17:31 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# include "push_swap.h"
# include <unistd.h>

# define STR_SA "sa\n"
# define STR_SB "sb\n"
# define STR_SS "ss\n"

static inline void	sa(t_data *data)
{
	int	tmp;

	if (data->a.top < 2)
		return ;
	tmp = data->a.content[data->a.top - 1];
	data->a.content[data->a.top - 1] = data->a.content[data->a.top - 2];
	data->a.content[data->a.top - 2] = tmp;
# ifndef SILENT_OUTPUT
	write(STDOUT, STR_SA, sizeof(STR_SA) - 1);
# endif
}

static inline void	sb(t_data *data)
{
	int	tmp;

	if (data->a.top < 2)
		return ;
	tmp = data->a.content[data->a.top - 1];
	data->a.content[data->a.top - 1] = data->a.content[data->a.top - 2];
	data->a.content[data->a.top - 2] = tmp;
# ifndef SILENT_OUTPUT
	write(STDOUT, STR_SB, sizeof(STR_SB) - 1);
# endif
}

static inline void	sb(t_data *data)
{
	int	tmp;

	if (data->a.top < 2)
		return ;
	tmp = data->a.content[data->a.top - 1];
	data->a.content[data->a.top - 1] = data->a.content[data->a.top - 2];
	data->a.content[data->a.top - 2] = tmp;
# ifndef SILENT_OUTPUT
	write(STDOUT, STR_SB, sizeof(STR_SB) - 1);
# endif
}

static inline void	ss(t_data *data)
{
	int	tmp;

	if (data->a.top < 2 || data->b.top < 2)
		return ;
	tmp = data->a.content[data->a.top - 1];
	data->a.content[data->a.top - 1] = data->a.content[data->a.top - 2];
	data->a.content[data->a.top - 2] = tmp;
	tmp = data->b.content[data->b.top - 1];
	data->b.content[data->b.top - 1] = data->b.content[data->b.top - 2];
	data->b.content[data->b.top - 2] = tmp;
# ifndef SILENT_OUTPUT
	write(STDOUT, STR_SS, sizeof(STR_SS) - 1);
# endif
}

#endif

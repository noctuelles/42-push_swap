/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 23:27:36 by plouvel           #+#    #+#             */
/*   Updated: 2022/01/30 01:15:40 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "push_swap.h"
# include <unistd.h>

# define STR_PA "pa\n"
# define STR_PB "pb\n"

static inline void	pa(t_data *data)
{
	if (data->b.top < 1)
		return ;
	push(&data->a, pop(&data->b));
# ifndef SILENT_OUTPUT
		write(STDOUT, STR_PA, sizeof(STR_PA) - 1);
# endif
}

static inline void	pb(t_data *data)
{
	if (data->a.top < 1)
		return ;
	push(&data->b, pop(&data->a));
# ifndef SILENT_OUTPUT
	write(STDOUT, STR_PB, sizeof(STR_PB) - 1);
# endif
}

#endif

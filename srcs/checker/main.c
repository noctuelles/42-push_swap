/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:42:11 by plouvel           #+#    #+#             */
/*   Updated: 2022/02/11 20:12:25 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"
#include <stdlib.h>

static int	throw_error_checker(t_data *data, const char *err_str)
{
	if (ft_strcmp(err_str, STR_ERROR) == 0)
		ft_putstr_fd(err_str, STDERR);
	else
		ft_putstr(err_str);
	free_stacks(data);
	return (1);
}

static t_inst	str_to_inst(const char *str)
{
	if (ft_strcmp(str, STR_SA) == 0)
		return (sa);
	if (ft_strcmp(str, STR_SB) == 0)
		return (sb);
	if (ft_strcmp(str, STR_SS) == 0)
		return (ss);
	if (ft_strcmp(str, STR_PA) == 0)
		return (pa);
	if (ft_strcmp(str, STR_PB) == 0)
		return (pb);
	if (ft_strcmp(str, STR_RA) == 0)
		return (ra);
	if (ft_strcmp(str, STR_RB) == 0)
		return (rb);
	if (ft_strcmp(str, STR_RR) == 0)
		return (rr);
	if (ft_strcmp(str, STR_RRA) == 0)
		return (rra);
	if (ft_strcmp(str, STR_RRB) == 0)
		return (rrb);
	if (ft_strcmp(str, STR_RRR) == 0)
		return (rrr);
	return (NULL);
}

static char	*get_line(char **line)
{
	free(*line);
	*line = get_next_line(STDIN);
	return (*line);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_inst	inst;
	char	*line;

	line = NULL;
	if (argc > 1)
	{
		ft_memset(&data, 0, sizeof(t_data));
		if (!alloc_stack(&data.a, argc - 1) || !alloc_stack(&data.b, argc - 1))
			return (throw_error_checker(&data, STR_ERROR));
		if (fill_stack_from_args(&data.a, argc, argv) == -1)
			return (throw_error_checker(&data, STR_ERROR));
		while (get_line(&line))
		{
			inst = str_to_inst(line);
			if (!inst)
				return (throw_error_checker(&data, STR_ERROR));
			inst(&data);
		}
		if (!is_stack_sorted(data.a))
			return (throw_error_checker(&data, STR_KO));
		free_stacks(&data);
		ft_putstr(STR_OK);
	}
	return (0);
}

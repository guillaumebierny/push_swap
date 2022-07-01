/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_and_sec_function.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:54:40 by gbierny           #+#    #+#             */
/*   Updated: 2022/07/01 20:24:52 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*strjoin_sep(char **argv, char *sep)
{
	int		i;
	char	*line;
	char	*all_line;

	i = 0;
	line = NULL;
	all_line = NULL;
	while (argv[++i])
	{
		all_line = ft_strjoin(line, argv[i]);
		free(line);
		if (argv[i + 1] != 0)
		{
			line = ft_strjoin(all_line, sep);
			free(all_line);
		}
	}
	return (all_line);
}

static int	check_double(char **arg, t_variables *v_push_swap)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		while (arg[j])
		{
			if (i != j && !ft_strcmp(arg[i], arg[j]))
			{
				error_message("Error\n", v_push_swap);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	*set_clean_tab(char **arg, t_list **stack_a,
		int *data, t_variables *v_push_swap)
{
	size_t	i;
	size_t	j;
	int		count;
	int		*to_int;

	*stack_a = NULL;
	i = -1;
	to_int = char_to_int(arg, v_push_swap);
	if (!to_int)
		return (0);
	while (++i < tab_len(arg))
	{
		count = 1;
		j = -1;
		while (++j < tab_len(arg))
		{
			if (i != j && to_int[i] > to_int[j])
				count++;
		}
		data[i] = count;
		ft_lstadd_back(stack_a, ft_lstnew(&data[i]));
	}
	free(to_int);
	return (data);
}

int	check_arguments(char **arg, t_variables *v_push_swap)
{
	int	i;

	i = -1;
	if (!only_digits(arg, v_push_swap))
		return (0);
	if (!check_double(arg, v_push_swap))
		return (0);
	if (!arg[1])
		return (0);
	return (1);
}

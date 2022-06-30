/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:53:33 by gbierny           #+#    #+#             */
/*   Updated: 2022/04/18 22:07:10 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*set_real_number(t_list **stack_a, char **arg,
		int *data, t_variables *v_push_arg)
{
	int		*to_int;
	int		i;
	t_list	*ptr;

	ptr = *stack_a;
	i = -1;
	to_int = char_to_int(arg, v_push_arg);
	if (!to_int)
		return (0);
	while (++i < tab_len(arg))
	{
		data[i] = to_int[i];
		ft_lstadd_back(stack_a, ft_lstnew(&data[i]));
	}
	free(to_int);
	return (data);
}

void	free_arg(t_variables *v_push_swap)
{
	while (v_push_swap->arg[v_push_swap->i])
	{
		free(v_push_swap->arg[v_push_swap->i]);
		v_push_swap->i++;
	}
	free(v_push_swap->arg);
}

void	function_ok_or_not(t_wep *stru)
{
	if (stru->stack_a && check_if_ordered(&stru->stack_a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	deal_with_stdin(t_wep *stru)
{
	char	*line;

	line = get_next_line(0);
	if (!line)
		return (1);
	while (line)
	{
		if (check_line_by_line(line, stru))
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_variables	v_push_swap;
	t_wep		stru;

	v_push_swap = initialize_t_variables();
	stru = initialize_stru(NULL, NULL);
	v_push_swap.whole_arg = strjoin_sep(argv, " ");
	v_push_swap.arg = ft_split(v_push_swap.whole_arg, ' ');
	while (v_push_swap.arg[v_push_swap.i])
		v_push_swap.i++;
	v_push_swap.data = malloc(sizeof(int) * v_push_swap.i);
	if (!v_push_swap.data)
		return (0);
	if (!(set_real_number(&stru.stack_a, v_push_swap.arg,
				v_push_swap.data, &v_push_swap)))
		return (0);
	free_arg(&v_push_swap);
	if (deal_with_stdin(&stru))
		return (1);
	function_ok_or_not(&stru);
	free(v_push_swap.data);
	return (0);
}

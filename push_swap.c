/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:39:14 by gbierny           #+#    #+#             */
/*   Updated: 2022/04/30 21:45:13 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*char_to_int(char **arg, t_variables *v_push_swap)
{	
	int	*stack_a;
	int	i;

	i = -1;
	stack_a = malloc(sizeof (int) * tab_len(arg));
	while (arg[++i])
	{
		if (!ft_amoi(arg[i], v_push_swap) && arg[i][0] != '0')
		{
			free(stack_a);
			return (0);
		}
		stack_a[i] = ft_amoi(arg[i], v_push_swap);
	}
	return (stack_a);
}

int	only_digits(char **arg, t_variables *v_push_swap)
{
	int	i;
	int	j;

	i = -1;
	while (arg[++i])
	{
		j = -1;
		while (arg[i][++j])
		{
			if (arg[i][j] < '0' || arg[i][j] > '9')
			{
				if ((arg[i][j] == '-' && j != 0) ||
					(arg[i][j] != '-') || (!arg[i][1]))
				{
					error_message("Error\n", v_push_swap);
					return (0);
				}
			}
		}
	}
	return (1);
}

void	choose_the_algo(t_wep *stru, int i)
{
	if (i < 4)
		algo_3(stru);
	else if (i < 6)
		algo_5(stru);
	else
		best_big_algo(stru);
}

int	sec_and_parsing(t_variables *v_push_swap, char **argv)
{
	size_t	i;

	i = 0;
	// if (argc < 2)
	// 	return (error_message("error: aucun argument", v_push_swap));
	v_push_swap->whole_arg = strjoin_sep(argv, " ");
	v_push_swap->arg = ft_split(v_push_swap->whole_arg, ' ');
	if (!(v_push_swap->arg))
		return (0);
	// if (!(v_push_swap->arg)[1])
	// 	return (error_message("error: que un argument", v_push_swap));
	if (!check_arguments(v_push_swap->arg, v_push_swap))
		return (0);
	return (1);
}

void	push_swap(int argc, char **argv)
{
	t_variables	v_push_swap;
	t_wep		stru;
	t_ind_num	tmp;
	t_ind_num	final;
	
	(void)argc;
	v_push_swap = initialize_t_variables();
	tmp = initialyze_ind_num();
	final = initialyze_ind_num();
	stru = initialize_stru(&tmp, &final);
	if (!sec_and_parsing(&v_push_swap, argv))
		return ;
	while (v_push_swap.arg[v_push_swap.i])
		v_push_swap.i++;
	v_push_swap.data = malloc(sizeof(int) * v_push_swap.i);
	if (!v_push_swap.data)
		return ;
	if (!(set_clean_tab(v_push_swap.arg, &stru.stack_a,
				v_push_swap.data, &v_push_swap)))
		return ;
	choose_the_algo(&stru, v_push_swap.i);
	ft_lstclear(&stru.stack_a, ft_lstdel);
	free_var_push_swap(&v_push_swap);
}

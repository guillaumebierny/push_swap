/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialyser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:49:12 by gbierny           #+#    #+#             */
/*   Updated: 2022/04/07 23:54:38 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_variables	initialize_t_variables(void)
{
	t_variables	v_push_swap;

	v_push_swap.arg = NULL;
	v_push_swap.whole_arg = NULL;
	v_push_swap.data = NULL;
	v_push_swap.i = 0;
	return (v_push_swap);
}

t_ind_num	initialyze_ind_num(void)
{
	t_ind_num	whatever;

	whatever.ra = 0;
	whatever.rra = 0;
	whatever.rb = 0;
	whatever.rrb = 0;
	whatever.best_op = 0;
	whatever.best_num = -1;
	return (whatever);
}

t_wep	initialize_stru(t_ind_num *tmp, t_ind_num *final)
{
	t_wep	stru;

	stru.stack_a = NULL;
	stru.stack_b = NULL;
	if (tmp && final)
	{
		stru.final = final;
		stru.tmp = tmp;
	}
	else
	{
		stru.final = NULL;
		stru.tmp = NULL;
	}
	stru.total_len = 0;
	stru.biggest_num = 0;
	stru.lowest_num = -1;
	stru.current_len = 0;
	stru.current_len_stack_b = 0;
	stru.num = 0;
	return (stru);
}

t_list	initialize_t_list(void)
{
	t_list	liste;

	liste.content = NULL;
	liste.next = NULL;
	return (liste);
}

t_type_of_mix	initilyze_type_of_mix(void)
{
	t_type_of_mix	grrr;

	grrr.rr = 0;
	grrr.rrr = 0;
	grrr.ra_and_rrb = 0;
	grrr.rra_and_rb = 0;
	return (grrr);
}

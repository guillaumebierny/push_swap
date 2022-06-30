/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_the_operation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:40:48 by gbierny           #+#    #+#             */
/*   Updated: 2022/04/07 23:43:07 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation_rr(t_wep *stru)
{
	while (stru->final->ra > 0 && stru->final->rb > 0)
	{
		stru->final->ra--;
		stru->final->rb--;
		rr(stru);
	}
	while (stru->final->ra > 0)
	{
		stru->final->ra--;
		do_ra(stru);
	}
	while (stru->final->rb > 0)
	{
		stru->final->rb--;
		do_rb(stru);
	}
}

void	operation_rrr(t_wep *stru)
{
	while (stru->final->rra > 0 && stru->final->rrb > 0)
	{
		stru->final->rra--;
		stru->final->rrb--;
		rrr(stru);
	}
	while (stru->final->rra > 0)
	{
		stru->final->rra--;
		do_rra(stru);
	}
	while (stru->final->rrb > 0)
	{
		stru->final->rrb--;
		do_rrb(stru);
	}
}

void	operation_ra_and_rrb(t_wep *stru)
{
	while (stru->final->ra > 0)
	{
		stru->final->ra--;
		do_ra(stru);
	}
	while (stru->final->rrb > 0)
	{
		stru->final->rrb--;
		do_rrb(stru);
	}
}

void	operation_rra_and_rb(t_wep *stru)
{
	while (stru->final->rra > 0)
	{
		stru->final->rra--;
		do_rra(stru);
	}
	while (stru->final->rb > 0)
	{
		stru->final->rb--;
		do_rb(stru);
	}
}

void	do_operation(t_wep *stru)
{
	if (stru->final->best_op == 1)
		operation_rr(stru);
	if (stru->final->best_op == 2)
		operation_rrr(stru);
	if (stru->final->best_op == 3)
		operation_ra_and_rrb(stru);
	if (stru->final->best_op == 4)
		operation_rra_and_rb(stru);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:12:53 by gbierny           #+#    #+#             */
/*   Updated: 2022/04/16 17:12:16 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_3_utils(t_wep *stru, int a, int b, int c)
{
	if (a < b)
	{
		if (b < c && a < c)
			return ;
		if (b > c && a < c)
		{
			do_rra(stru);
			do_sa(stru);
		}
		else
			do_rra(stru);
	}
	if (a > b)
	{
		if (a > c && b < c)
			do_ra(stru);
		else if (a > c && b > c)
		{
			do_ra(stru);
			do_sa(stru);
		}
		else
			do_sa(stru);
	}
}

void	algo_3(t_wep *stru)
{
	int	a ;
	int	b ;
	int	c ;

	a = *(int *)stru->stack_a->content;
	b = *(int *)stru->stack_a->next->content;
	if (!stru->stack_a->next->next)
	{
		if (a > b)
			do_sa(stru);
		return ;
	}
	c = *(int *)(stru->stack_a->next->next->content);
	algo_3_utils(stru, a, b, c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:49:55 by gbierny           #+#    #+#             */
/*   Updated: 2022/04/18 14:20:20 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
{
	void	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = tmp;
		return (1);
	}
	return (0);
}

void	do_sa(t_wep *stru)
{
	if (swap(&stru->stack_a))
		write(1, "sa\n", 3);
}

void	do_sb(t_wep *stru)
{
	if (swap(&stru->stack_b))
		write(1, "sb\n", 3);
}

void	ss(t_wep *stru)
{
	if ((stru->stack_a && stru->stack_a->next)
		&& (stru->stack_b && stru->stack_b->next))
	{
		write(1, "ss\n", 3);
		swap(&stru->stack_a);
		swap(&stru->stack_b);
	}
	else
	{
		do_sa(stru);
		do_sb(stru);
	}
}

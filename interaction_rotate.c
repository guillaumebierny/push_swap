/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:51:10 by gbierny           #+#    #+#             */
/*   Updated: 2022/04/08 00:14:21 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	void	*new_last;
	t_list	*new_first;

	if (*stack && (*stack)->next)
	{
		new_last = (*stack)->content;
		new_first = (*stack)->next;
		ft_lstdelete(*stack);
		*stack = new_first;
		ft_lstadd_back(stack, ft_lstnew(new_last));
	}
}

void	do_ra(t_wep *stru)
{
	if (stru->stack_a && stru->stack_a->next)
	{
		rotate(&stru->stack_a);
		write(1, "ra\n", 3);
	}
}

void	do_rb(t_wep *stru)
{
	if (stru->stack_b && stru->stack_b->next)
	{
		rotate(&stru->stack_b);
		write(1, "rb\n", 3);
	}
}

void	rr(t_wep *stru)
{
	if ((stru->stack_b && stru->stack_b->next)
		&& (stru->stack_a && stru->stack_a->next))
	{
		rotate(&stru->stack_a);
		rotate(&stru->stack_b);
		write(1, "rr\n", 3);
	}
	else
	{
		do_ra(stru);
		do_rb(stru);
	}
}

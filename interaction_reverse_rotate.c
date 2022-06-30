/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction_reverse_rotate.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:52:58 by gbierny           #+#    #+#             */
/*   Updated: 2022/04/08 00:11:23 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{
	void	*new_first;
	t_list	*ptr;

	ptr = *stack;
	if (*stack && (*stack)->next)
	{
		new_first = ft_lstlast(*stack)->content;
		while (ptr->next->next)
			ptr = ptr->next;
		ft_lstdelete(ft_lstlast(*stack));
		ptr->next = NULL;
		ft_lstadd_front(stack, ft_lstnew(new_first));
	}
}

void	do_rrb(t_wep *stru)
{
	if (stru->stack_b && stru->stack_b->next)
	{
		reverse_rotate(&stru->stack_b);
		write(1, "rrb\n", 4);
	}
}

void	do_rra(t_wep *stru)
{
	if (stru->stack_a && stru->stack_a->next)
	{
		reverse_rotate(&stru->stack_a);
		write(1, "rra\n", 4);
	}
}

void	rrr(t_wep *stru)
{
	if ((stru->stack_b && stru->stack_b->next)
		&& (stru->stack_a && stru->stack_a->next))
	{
		reverse_rotate(&stru->stack_a);
		reverse_rotate(&stru->stack_b);
		write(1, "rrr\n", 4);
	}
	else
	{
		do_rra(stru);
		do_rrb(stru);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:53:27 by gbierny           #+#    #+#             */
/*   Updated: 2022/04/16 22:22:12 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelete(t_list *lst)
{
	if (!lst)
		return ;
	lst->content = NULL;
	free(lst);
}

void	pb(t_wep *stru)
{
	t_list	*tmp;

	if (stru->stack_a)
	{
		ft_lstadd_front(&stru->stack_b, ft_lstnew(stru->stack_a->content));
		tmp = stru->stack_a->next;
		ft_lstdelete(stru->stack_a);
		stru->stack_a = tmp;
		ft_putstr("pb\n");
	}
}

void	pa(t_wep *stru)
{
	t_list	*tmp;

	tmp = NULL;
	if (stru->stack_b)
	{
		ft_lstadd_front(&stru->stack_a, ft_lstnew(stru->stack_b->content));
		tmp = stru->stack_b->next;
		ft_lstdelete(stru->stack_b);
		stru->stack_b = tmp;
		ft_putstr("pa\n");
	}
}

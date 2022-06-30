/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:45:07 by gbierny           #+#    #+#             */
/*   Updated: 2022/04/30 20:14:36 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	change_tmp(t_wep *stru, int index)
{
	stru->tmp->rb = index;
	stru->tmp->rrb = stru->current_len_stack_b - index;
	if ((stru->tmp->rb) == 0)
		stru->tmp->rrb = 0;
}

void num_bigger_at_first(t_wep *stru, int index)
{
	t_list *ptr;
	int interupteur;
	int first_lower;

	first_lower = 0;
	interupteur = 0;
	ptr = stru->stack_b;
	while (ptr)
	{
		if (stru->num > *(int *)ptr->content && !first_lower)
		{
			change_tmp(stru, index);
			first_lower = 1;
			if (interupteur)
				return ;
		}
		if (*(int *)ptr->content == stru->biggest_num)
		{
			interupteur = 1;
			first_lower = 0;
			if (stru->num > stru->biggest_num)
				return (change_tmp(stru, index));
		}

		ptr = ptr->next;
		index++;
	}
}

void num_lower_at_first(t_wep *stru, int index)
{
    t_list *ptr;
    ptr = stru->stack_b;
	if (!ptr->next)
		return (change_tmp(stru, index));
    while (ptr)
    {
        if (stru->num > *(int *)ptr->content)
            return (change_tmp(stru, index));
        if (*(int *)ptr->content == stru->lowest_num && stru->num < stru->lowest_num)
            return (change_tmp(stru, (index+1)));
		ptr = ptr->next;
		index++;
    }
}

void check_stack_b(t_wep *stru)
{
	int index;

	index = 0;
	if (!stru->stack_b)
		return (change_tmp(stru, index));
	if (stru->num > *(int *)stru->stack_b->content)
		num_bigger_at_first(stru, index);
	else if (stru->num < *(int *)stru->stack_b->content)
		num_lower_at_first(stru, index);
}

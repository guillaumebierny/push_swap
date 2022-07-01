/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackb_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:40:30 by gbierny           #+#    #+#             */
/*   Updated: 2022/07/01 19:32:27 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_bigger_atfirst_cond(t_wep *stru, int *first_lower,
	int interupteur, int index)
{
	stru->tmp->rb = index;
	stru->tmp->rrb = stru->current_len_stack_b - index;
	if (stru->tmp->rb == 0)
		stru->tmp->rrb = 0;
	*first_lower = 1;
	if (interupteur)
		return (1);
	return (0);
}

void	case_bigger_atfirst(t_list *stack_b, t_wep *stru)
{
	t_list	*ptr;
	int		index;
	int		interupteur;
	int		first_lower;

	first_lower = 0;
	index = 0;
	interupteur = 0;
	ptr = stack_b;
	while (ptr)
	{
		if (stru->num > *(int *)ptr->content && !first_lower
			&& case_bigger_atfirst_cond(stru,
				&first_lower, interupteur, index))
			return ;
		if (*(int *)ptr->content == stru->biggest_num)
		{
			interupteur = 1;
			first_lower = 0;
			if (stru->num > stru->biggest_num)
				return ;
		}
		ptr = ptr->next;
		index ++;
	}
}

void	case_lower_atfirst(t_list *stack_b, t_wep *stru)
{
	t_list	*ptr;
	int		index;

	index = 0;
	ptr = stack_b;
	while (ptr)
	{
		if (stru->num > *(int *)ptr->content)
		{
			stru->tmp->rb = index;
			stru->tmp->rrb = stru->current_len_stack_b - index;
			if (stru->tmp->rb == 0)
				stru->tmp->rrb = 0;
			return ;
		}
		if (ptr->content == stru->lowest_num && stru->num < stru->lowest_num)
		{
			stru->tmp->rb = index + 1;
			stru->tmp->rrb = stru->current_len_stack_b - (index + 1);
			if (stru->tmp->rb == 0)
				stru->tmp->rrb = 0;
			return ;
		}
	}
}

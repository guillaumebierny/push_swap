/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:38:08 by gbierny           #+#    #+#             */
/*   Updated: 2022/04/16 17:10:55 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_ordered(t_list **stack)
{
	t_list	*ptr;
	int		a;
	int		b;

	ptr = *stack;
	while (ptr->next)
	{
		a = *(int *)ptr->content;
		b = *(int *)ptr->next->content;
		if (a > b)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

void	reset(t_wep *stru, void (*f)(t_list **), int index)
{
	while (index-- > 0)
		f(&stru->stack_b);
}

int	return_minimal_operation(t_wep *stru, t_type_of_mix *mix)
{
	if (mix->rr <= mix->rrr && mix->rr <= mix->ra_and_rrb
		& mix->rr <= mix->rra_and_rb)
	{
		stru->tmp->best_num = mix->rr;
		return (1);
	}
	if (mix->rrr < mix->rr && mix->rrr <= mix->ra_and_rrb
		&& mix->rrr <= mix->rra_and_rb)
	{	
		stru->tmp->best_num = mix->rrr;
		return (2);
	}
	if (mix->ra_and_rrb < mix->rr && mix->ra_and_rrb < mix->rrr
		&& mix->ra_and_rrb <= mix->rra_and_rb)
	{	
		stru->tmp->best_num = mix->ra_and_rrb;
		return (3);
	}
	if (mix->rra_and_rb < mix->rr && mix->rra_and_rb < mix->rrr
		&& mix->rra_and_rb < mix->ra_and_rrb)
	{	
		stru->tmp->best_num = mix->rra_and_rb;
		return (4);
	}
	return (0);
}

int	compare_mix_of_operation(t_wep *stru)
{	
	t_type_of_mix	mix;

	mix = initilyze_type_of_mix();
	if (stru->tmp->ra < stru->tmp->rb)
		mix.rr = stru->tmp->rb;
	else
		mix.rr = stru->tmp->ra;
	if (stru->tmp->rra < stru->tmp->rrb)
		mix.rrr = stru->tmp->rrb;
	else
		mix.rrr = stru->tmp->rra;
	mix.ra_and_rrb = stru->tmp->ra + stru->tmp->rrb;
	mix.rra_and_rb = stru->tmp->rra + stru->tmp->rb;
	return (return_minimal_operation(stru, &mix));
}

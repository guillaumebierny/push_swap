/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:43:31 by gbierny           #+#    #+#             */
/*   Updated: 2022/04/07 23:16:32 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	show_stack(t_list *stack)
// {
// 	t_list *ptr;

// 	ptr = stack;
// 	// printf("\n");
// 	while (ptr)
// 	{
// 		printf("%d ", *(int *)ptr->content);
// 		ptr = ptr->next;
// 	}
// 	printf("\n");
// }

void	reorder_stack_b(t_wep *stru)
{
	t_list	*ptr;
	int		index;

	index = 0;
	ptr = stru->stack_b;
	while (*(int *)ptr->content != stru->biggest_num)
	{
		index++;
		ptr = ptr->next;
	}
	if (index <= stru->current_len_stack_b - index)
	{
		while (index-- > 0)
			do_rb(stru);
	}
	else
	{
		index = stru->current_len_stack_b - index;
		while (index-- > 0)
			do_rrb(stru);
	}
}

void	make_the_change(t_wep *stru)
{
	stru->final->ra = stru->tmp->ra;
	stru->final->rra = stru->tmp->rra;
	stru->final->rb = stru->tmp->rb;
	stru->final->rrb = stru->tmp->rrb;
	stru->final->best_op = stru->tmp->best_op;
	stru->final->best_num = stru->tmp->best_num;
}

void	make_the_operation(t_wep *stru)
{
	do_operation(stru);
	pb(stru);
	if (stru->biggest_num < *(int *)stru->stack_b->content)
		stru->biggest_num = *(int *)stru->stack_b->content;
	if (stru->lowest_num > *(int *)stru->stack_b->content
		|| stru->lowest_num == -1)
		stru->lowest_num = *(int *)stru->stack_b->content;
	stru->current_len--;
	stru->current_len_stack_b++;
}

void	for_each_from_stack_a(t_wep *stru, t_list *ptr_a)
{
	t_ind_num	tmp;
	int			index;

	index = 0;
	while (ptr_a)
	{
		tmp = initialyze_ind_num();
		stru->tmp = &tmp;
		stru->num = *(int *)ptr_a->content;
		stru->tmp->ra = index;
		stru->tmp->rra = stru->current_len - index;
		if (stru->tmp->ra == 0)
			stru->tmp->rra = 0;
		check_stack_b(stru);
		stru->tmp->best_op = compare_mix_of_operation(stru);
		if (stru->tmp->best_num < stru->final->best_num
			|| stru->final->best_num == -1)
			make_the_change(stru);
		index++;
		ptr_a = ptr_a->next;
	}
}

void	best_big_algo(t_wep *stru)
{
	t_list	*ptr_a;

	if (check_if_ordered(&stru->stack_a))
		return ;
	stru->current_len = ft_lstsize(stru->stack_a);
	while (stru->stack_a)
	{
		ptr_a = stru->stack_a;
		stru->final->best_num = -1;
		for_each_from_stack_a(stru, ptr_a);
		make_the_operation(stru);
	}
	reorder_stack_b(stru);
	while (stru->stack_b)
		pa(stru);
}

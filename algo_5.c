/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:26:38 by gbierny           #+#    #+#             */
/*   Updated: 2022/04/30 21:38:53 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_lower_return(int *i, int size, int down, int up)
{
	if (up <= size - down)
	{
		*i = up;
		return (1);
	}
	if (up > size - down)
	{
		*i = size - down;
		return (0);
	}
	return (1);
}

int	find_lower(t_list **stack, int *i, int size)
{
	t_list	*ptr;
	int		up;
	int		down;
	int		j;

	up = 6;
	down = 1;
	*i = 0;
	j = 0;
	ptr = *stack;
	while (ptr)
	{
		if ((*(int *)ptr->content < 3) && (*i <= size / 2 + 1 && up > j))
			up = j;
		else if ((*(int *)ptr->content < 3) && (*i > size / 2 + 1))
			down = j;
		ptr = ptr->next;
		(*i)++;
		j++;
	}
	return (find_lower_return(i, size, down, up));
}

void	algo_5_utils(t_wep *stru, int i)
{
	int	time;

	while (i--)
	{
		time = 0;
		if (find_lower(&stru->stack_a, &time, ft_lstsize(stru->stack_a)))
		{
			while (time-- > 0)
				do_ra(stru);
			if (!stru->stack_b)
				pb(stru);
		}
		else
		{
			while (time-- > 0)
				do_rra(stru);
			if (!stru->stack_b)
				pb(stru);
		}
	}
}

void	algo_5(t_wep *stru)
{
	int	i;
	int	size;

	i = 2;
	size = ft_lstsize(stru->stack_a);
	if (size == 4)
		i--;
	if (check_if_ordered(&stru->stack_a))
		return ;
	algo_5_utils(stru, i);
	if (!check_if_ordered(&stru->stack_a))
	{
		if (size > 4)
			pb(stru);
		algo_3(stru);
	}
	pa(stru);
	if (size == 5)
		pa(stru);
	if (*(int *)stru->stack_a->content > *(int *)stru->stack_a->next->content)
		do_sa(stru);
	return ;
}

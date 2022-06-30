/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:32:59 by gbierny           #+#    #+#             */
/*   Updated: 2022/04/18 22:04:28 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	tab_len(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	return ((size_t)i);
}

void	free_var_push_swap(t_variables *v)
{
	int	i;

	i = 0;
	if (!v->whole_arg)
		return ;
	free(v->whole_arg);
	if (!v->arg)
		return ;
	while ((v->arg)[i])
	{
		free((v->arg)[i]);
		i++;
	}
	free((v->arg));
	if (!v->data)
		return ;
	free(v->data);
}

int	error_message(char *s, t_variables *v_push_swap)
{
	ft_putstr_fd(s, 2);
	free_var_push_swap(v_push_swap);
	return (0);
}

void	ft_putstr(const char *c)
{
	write(1, c, ft_strlen(c));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:29:28 by gbierny           #+#    #+#             */
/*   Updated: 2022/04/30 21:46:47 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_numbers(char *str, int *i,
	int *signe, t_variables *v_push_swap)
{
	long int	res;

	res = 0;
	while (str[(*i)] >= 48 && str[(*i)] <= 57)
	{
		res = res * 10 + (str[(*i)] - 48);
		((*i))++;
		if (res > 2147483647 && ((*signe)) == 1)
			return (error_message("Error\n", v_push_swap));
		if (res > 2147483648 && ((*signe)) == -1)
			return (error_message("Error\n", v_push_swap));
		if (res)
			if (res < 0 && ((*signe)) == -1)
				return (0);
		if (res < 0 && ((*signe)) == 1)
			return (-1);
	}
	return (res);
}

static int	get_sign(char *str, int *i, int signe, int count)
{
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			signe *= -1;
		if (++count > 1)
			return (0);
		(*i)++;
	}
	return (signe);
}

int	ft_amoi(const char *str, t_variables *v_push_swap)
{
	int			i;
	int			signe;
	int			count;
	long int	res;

	res = 0;
	count = 0;
	signe = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	signe = get_sign((char *)str, &i, signe, count);
	if (signe == 0)
		return (0);
	res = count_numbers((char *)str, &i, &signe, v_push_swap);
	if (res == 0)
		return (0);
	else
		return ((res * signe));
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i])
	{
		if (s1[i] != s2[i])
			return (1);
	}
	if (s2[i] != 0)
		return (1);
	return (0);
}

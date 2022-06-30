/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:10:13 by gbierny           #+#    #+#             */
/*   Updated: 2022/04/16 17:56:32 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putstr_fd_for_checker(char *line, int fd)
{
	if (!line)
		return (1);
	write(fd, line, ft_strlen(line));
	return (1);
}

int	check_line_by_line(char *line, t_wep *stru)
{
	if (!ft_strncmp(line, "rb\n", 5))
		do_rb(stru);
	else if (!ft_strncmp(line, "rrb\n", 5))
		do_rrb(stru);
	else if (!ft_strncmp(line, "rr\n", 5))
		rr(stru);
	else if (!ft_strncmp(line, "rrr\n", 5))
		rrr(stru);
	else if (!ft_strncmp(line, "sa\n", 5))
		do_sa(stru);
	else if (!ft_strncmp(line, "sb\n", 5))
		do_sb(stru);
	else if (!ft_strncmp(line, "ss\n", 5))
		ss(stru);
	else if (!ft_strncmp(line, "pb\n", 5))
		pb(stru);
	else if (!ft_strncmp(line, "pa\n", 5))
		pa(stru);
	else if (!ft_strncmp(line, "ra\n", 5))
		do_ra(stru);
	else if (!ft_strncmp(line, "rra\n", 5))
		do_rra(stru);
	else
		return (ft_putstr_fd_for_checker(line, 2));
	return (0);
}

// int	check_line_by_line(char *line, t_wep *stru)
// {
// 	if (check_line_by_line_second_part(line, stru))
// 		return (1);
// 	line = get_next_line(0);
// 	return (0);
// }

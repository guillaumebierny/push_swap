/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:35:43 by gbierny           #+#    #+#             */
/*   Updated: 2022/04/28 19:25:58 by gbierny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <stdio.h>
#include <limits.h>

typedef struct s_type_of_mix
{
	int rr;
	int rrr;
	int ra_and_rrb;
	int rra_and_rb;
} t_type_of_mix;

typedef struct s_ind_num
{
	int ra;
	int rra;
	int rb;
	int rrb;
	int best_op;
	int best_num;
} t_ind_num;

typedef struct s_variables
{
	char **arg;
	char *whole_arg;
	int *data;
	size_t i;
} t_variables;

typedef struct s_wep
{
	t_list *stack_a;
	t_ind_num *final;
	t_ind_num *tmp;
	size_t total_len;
	t_list *stack_b;
	int biggest_num;
	int lowest_num;
	int current_len;
	int current_len_stack_b;
	int num;
} t_wep;

void push_swap(int argc, char **argv);
int sec_and_parsing(t_variables *v_push_swap,
					char **argv);
// UTILS:
int ft_amoi(const char *str, t_variables *v_push_swap);
void ft_putstr(const char *c);
int ft_strcmp(char *s1, char *s2);
// THE OPERATION:
void ss(t_wep *stru);
void do_sa(t_wep *stru);
void do_sb(t_wep *stru);
void pa(t_wep *stru);
void pb(t_wep *stru);
int swap(t_list **stack);
void rotate(t_list **stack);
void reverse_rotate(t_list **stack);
void do_ra(t_wep *stru);
void do_rb(t_wep *stru);
void rr(t_wep *stru);
void do_rrb(t_wep *stru);
void do_rra(t_wep *stru);
void rrr(t_wep *stru);
void best_big_algo(t_wep *stru);
void ft_lstdelete(t_list *lst);
// INITIALYSER:
t_ind_num initialyze_ind_num(void);
t_wep initialize_stru(t_ind_num *tmp, t_ind_num *final);
t_variables initialize_t_variables(void);
t_list initialize_t_list(void);
t_type_of_mix initilyze_type_of_mix(void);

int check_if_ordered(t_list **stack);
int *set_clean_tab(char **arg, t_list **stack_a,
				   int *data, t_variables *v_push_swap);
int check_arguments(char **arg, t_variables *v_push_swap);
char *strjoin_sep(char **argv, char *sep);
int *char_to_int(char **arg, t_variables *v_push_swap);
int only_digits(char **arg, t_variables *v_push_swap);
// ALGO_3
void algo_3_utils(t_wep *stru, int a, int b, int c);
void algo_3(t_wep *stru);
// ALGO_5
int find_lower_return(int *i, int size, int down, int up);
int find_lower(t_list **stack, int *i, int size);
void algo_5_utils(t_wep *stru, int i);
void algo_5(t_wep *stru);
// ALGO_BIG
// DO_THE_OPERATION:
void operation_rr(t_wep *stru);
void operation_rrr(t_wep *stru);
void operation_ra_and_rrb(t_wep *stru);
void operation_rra_and_rb(t_wep *stru);
void do_operation(t_wep *stru);
// CHECK_STACK_B:
void num_bigger_at_first(t_wep *stru, int index);
void lower_at_first_second_part(t_wep *stru, int index);
void num_lower_at_first(t_wep *stru, int index);
void check_stack_b(t_wep *stru);
// BEST_ALGO/UTILS:
void reset(t_wep *stru, void (*f)(t_list **), int index);
int check_if_ordered(t_list **stack);
int return_minimal_operation(t_wep *stru, t_type_of_mix *mix);
int compare_mix_of_operation(t_wep *stru);
// PUSH_SWAP_UTILS:
size_t tab_len(char **arg);
int error_message(char *s, t_variables *v_push_swap);
void free_var_push_swap(t_variables *v);
// FOR_CHECKER:
int check_line_by_line(char *line, t_wep *stru);

#endif

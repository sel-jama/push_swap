/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:02:23 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/04 06:29:58 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "libft/libft.h"

void		ft_assign_pos(t_list **head);
int			get_tar_pos(t_list **stka, int stkb_rank, int min_rank, int t_pos);
void		assign_target_pos(t_list **stka, t_list **stkb);
void		move_sort_elements(t_list **stka, t_list **stkb);
void		mini_sort(t_list **stack_a);
void		ft_assign_pos(t_list **head);
void		assign_rank(t_list *stack_a, int stack_size);
void		quick_sort(t_list **stack_a, t_list **stack_b, int stack_size);
int			*get_ranks_arr(t_list **stka, int stack_size);
void		assign_rank(t_list *stack_a, int stack_size);
void		get_cost(t_list **stka, t_list **stkb);
t_list		*get_cheapest_cost(t_list **head_b, t_list **head_a);
int			largest_index(int stack_size, int *arr, int **ranks_arr);
int			*get_stack_arr(t_list **stka);
char		*concat_args(char **strings, int ac);
void		load_to_stack(int ac, char **av, t_list **stka, int bonus);
void		check_numbers(char **av);
void		check_args(int ac, char **av, t_list **stka, int bonus);
void		check_duplicates(char **av);
int			check_max_int(char **av);
int			is_sorted(t_list **head);
char		**ft_split_args(int ac, char **av);
void		sa(t_list **head_a, int show);
void		sb(t_list **head_b, int show);
void		ss(t_list **stk_a, t_list **stk_b, int show);
void		ra(t_list **stk_a, int show);
void		rb(t_list **stk_b, int show);
void		rr(t_list **stk_a, t_list **stk_b, int show);
void		rra(t_list **stk_a, int show);
void		rrb(t_list **stk_b, int show);
void		rrr(t_list **stk_a, t_list **stk_b, int show);
void		pa(t_list **stk_a, t_list **stk_b, int show);
int			pb(t_list **stk_a, t_list **stk_b, int show);
void		ft_error_exit_ps(char *msg, int n);
long long	ft_atoll(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
int			ft_abs(int n);
void		ft_free_stack(t_list **stack);
int			check_opperations(char *opp);
void		do_opperation(t_list **stk_a, t_list **stk_b, char *opp);
void		ft_checker_result(t_list **stk_a);
void		free_av(char **av);
void		ft_ko_exit_ps(char *msg, int n);
void		initialize_stack(t_list	**stk_a, t_list **stk_b);
void		ft_check_empty(int ac, char **av);
#endif 

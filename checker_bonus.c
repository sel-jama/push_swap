/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 04:46:38 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/05 06:20:56 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line/get_next_line.h"

int	check_opperations(char *opp)
{
	if (ft_strcmp(opp, "sa\n") == 0)
		return (1);
	else if (ft_strcmp(opp, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(opp, "ss\n") == 0)
		return (1);
	else if (ft_strcmp(opp, "ra\n") == 0)
		return (1);
	else if (ft_strcmp(opp, "rb\n") == 0)
		return (1);
	else if (ft_strcmp(opp, "rr\n") == 0)
		return (1);
	else if (ft_strcmp(opp, "rra\n") == 0)
		return (1);
	else if (ft_strcmp(opp, "rrb\n") == 0)
		return (1);
	else if (ft_strcmp(opp, "rrr\n") == 0)
		return (1);
	else if (ft_strcmp(opp, "pa\n") == 0)
		return (1);
	else if (ft_strcmp(opp, "pb\n") == 0)
		return (1);
	return (0);
}

void	do_opperation(t_list **stk_a, t_list **stk_b, char *opp)
{
	if (ft_strcmp(opp, "sa\n") == 0)
		sa(stk_a, 0);
	else if (ft_strcmp(opp, "sb\n") == 0)
		sb(stk_b, 0);
	else if (ft_strcmp(opp, "ss\n") == 0)
		ss(stk_a, stk_b, 0);
	else if (ft_strcmp(opp, "ra\n") == 0)
		ra(stk_a, 0);
	else if (ft_strcmp(opp, "rb\n") == 0)
		rb(stk_b, 0);
	else if (ft_strcmp(opp, "rr\n") == 0)
		rr(stk_a, stk_b, 0);
	else if (ft_strcmp(opp, "rra\n") == 0)
		rra(stk_a, 0);
	else if (ft_strcmp(opp, "rrb\n") == 0)
		rrb(stk_b, 0);
	else if (ft_strcmp(opp, "rrr\n") == 0)
		rrr(stk_a, stk_b, 0);
	else if (ft_strcmp(opp, "pa\n") == 0)
		pa(stk_a, stk_b, 0);
	else if (ft_strcmp(opp, "pb\n") == 0)
		pb(stk_a, stk_b, 0);
}

void	ft_checker_result(t_list **stk_a)
{
	if (is_sorted(stk_a))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	char	*opp;
	t_list	*stka;
	t_list	*stkb;
	int		err;

	err = 0;
	ft_check_empty(ac, av);
	initialize_stack(&stka, &stkb);
	check_args(ac, av, &stka, 1);
	opp = get_next_line(0);
	while (opp && *opp != '\n')
	{
		if (!check_opperations(opp))
			err = 1;
		else
			do_opperation(&stka, &stkb, opp);
		free(opp);
		opp = get_next_line(0);
	}
	if (err)
		ft_error_exit_ps("Error", 1);
	if (stkb)
		ft_ko_exit_ps("KO", 1);
	ft_checker_result(&stka);
	ft_free_stack(&stka);
	return (0);
}

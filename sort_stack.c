/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:59:50 by sel-jama          #+#    #+#             */
/*   Updated: 2023/02/26 22:03:07 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_sort_elements_2(t_list *node_to_move, t_list **stka, t_list **stkb)
{
	while (node_to_move->cost_stack_a != 0)
	{
		if (node_to_move->cost_stack_a > 0)
		{
			ra(stka, 1);
			(node_to_move->cost_stack_a) -= 1;
		}
		else if (node_to_move->cost_stack_a < 0)
		{
			rra(stka, 1);
			(node_to_move->cost_stack_a) += 1;
		}
	}
	while (node_to_move->cost_stack_b != 0)
	{
		if (node_to_move->cost_stack_b > 0)
		{
			rb(stkb, 1);
			(node_to_move->cost_stack_b) -= 1;
		}
		else if (node_to_move->cost_stack_b < 0)
			rrb(stkb, 1);
		if (node_to_move->cost_stack_b < 0)
			(node_to_move->cost_stack_b) += 1;
	}
}

void	move_sort_elements(t_list **stka, t_list **stkb)
{
	t_list	*node_to_move;

	node_to_move = get_cheapest_cost(stkb, stka);
	if (node_to_move == NULL)
		return ;
	if (node_to_move->cost_stack_a < 0 && node_to_move->cost_stack_b < 0)
	{
		while (node_to_move->cost_stack_a < 0 && node_to_move->cost_stack_b < 0)
		{
			rrr(stka, stkb, 1);
			(node_to_move->cost_stack_a) += 1;
			(node_to_move->cost_stack_b) += 1;
		}
	}
	else if (node_to_move->cost_stack_a > 0 && node_to_move->cost_stack_b > 0)
	{
		while (node_to_move->cost_stack_a > 0 && node_to_move->cost_stack_b > 0)
		{
			rr(stka, stkb, 1);
			(node_to_move->cost_stack_a) -= 1;
			(node_to_move->cost_stack_b) -= 1;
		}
	}
	move_sort_elements_2(node_to_move, stka, stkb);
	pa(stka, stkb, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:45:31 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/02 18:09:53 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_list **stka, t_list **stkb)
{
	t_list	*crt_a;
	t_list	*crt_b;
	int		stack_a_size;
	int		stack_b_size;

	stack_a_size = ft_lstsize(*stka);
	stack_b_size = ft_lstsize(*stkb);
	crt_a = *stka;
	crt_b = *stkb;
	while (crt_b)
	{
		if (crt_b->pos <= stack_b_size / 2)
			crt_b->cost_stack_b = crt_b->pos;
		else
			crt_b->cost_stack_b = (stack_b_size - crt_b->pos) * -1;
		if (crt_b->target_pos <= stack_a_size / 2)
			crt_b->cost_stack_a = crt_b->target_pos;
		else
			crt_b->cost_stack_a = (stack_a_size - crt_b->target_pos) * -1;
		crt_b = crt_b->next;
	}
}

t_list	*get_cheapest_cost(t_list **head_b, t_list **head_a)
{
	int		cost;
	int		min_cost;
	t_list	*min_cost_node;
	t_list	*tmpb;

	min_cost = INT_MAX;
	min_cost_node = NULL;
	get_cost(head_a, head_b);
	tmpb = *head_b;
	while (tmpb != NULL)
	{
		cost = ft_abs(tmpb->cost_stack_a) + ft_abs(tmpb->cost_stack_b);
		if (cost < ft_abs(min_cost))
		{
			min_cost = ft_abs(tmpb->cost_stack_a) + ft_abs(tmpb->cost_stack_b);
			min_cost_node = tmpb;
		}
		tmpb = tmpb->next;
	}
	return (min_cost_node);
}

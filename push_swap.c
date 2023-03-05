/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:40:30 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/04 04:51:19 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_pos(t_list **stack)
{
	t_list	*current;
	int		least_rank;
	int		min_pos;

	least_rank = INT_MAX;
	current = *stack;
	while (current)
	{
		if (least_rank > current->rank)
		{
			least_rank = current->rank;
			min_pos = current->pos;
		}
		current = current->next;
	}
	return (min_pos);
}

void	last_sort(t_list **stack, int stack_size)
{
	int	min_pos;

	ft_assign_pos(stack);
	min_pos = get_min_pos(stack);
	if (min_pos > stack_size / 2)
	{
		while (min_pos < stack_size)
		{
			rra(stack, 1);
			min_pos++;
		}
	}
	else
	{
		while (min_pos)
		{
			ra(stack, 1);
			min_pos--;
		}
	}
}

void	sort_less_than_three(t_list	*stka, int stack_a_size)
{
	if (stack_a_size == 2)
	{
		sa(&stka, 1);
		exit(0);
	}
	else if (stack_a_size == 3)
	{
		mini_sort(&stka);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_list	*stka;
	t_list	*stkb;
	int		stack_a_size;

	ft_check_empty(ac, av);
	initialize_stack(&stka, &stkb);
	check_args(ac, av, &stka, 0);
	stack_a_size = ft_lstsize(stka);
	assign_rank(stka, stack_a_size);
	sort_less_than_three(stka, stack_a_size);
	quick_sort(&stka, &stkb, stack_a_size);
	while (stkb)
	{
		assign_target_pos(&stka, &stkb);
		move_sort_elements(&stka, &stkb);
	}
	if (!is_sorted(&stka))
		last_sort(&stka, stack_a_size);
	ft_free_stack(&stka);
	return (0);
}

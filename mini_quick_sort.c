/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_quick_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:20:14 by sel-jama          #+#    #+#             */
/*   Updated: 2023/02/28 23:15:43 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort(t_list **stack_a)
{
	t_list	*tmp;
	int		pos;
	int		max;

	tmp = *stack_a;
	ft_assign_pos(&tmp);
	max = INT_MIN;
	while (tmp)
	{
		if (tmp->rank > max)
		{
			max = tmp->rank;
			pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (pos == 0)
		ra(stack_a, 1);
	else if (pos == 1)
		rra(stack_a, 1);
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a, 1);
}

void	quick_sort(t_list **stack_a, t_list **stack_b, int stack_size)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (stack_size > 6 && i++ < stack_size && count < stack_size / 2)
	{
		if ((*stack_a)->rank <= stack_size / 2)
			count += pb(stack_a, stack_b, 1);
		else
			ra(stack_a, 1);
	}
	while (stack_size - count > 3)
		count += pb(stack_a, stack_b, 1);
	mini_sort(stack_a);
}

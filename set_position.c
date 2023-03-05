/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:38:36 by sel-jama          #+#    #+#             */
/*   Updated: 2023/02/26 21:44:39 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_tar_pos(t_list **stka, int stkb_rank, int min_rank, int t_pos)
{
	t_list	*current;

	current = *stka;
	while (current)
	{
		if (current->rank > stkb_rank && current->rank < min_rank)
		{
			min_rank = current->rank;
			t_pos = current->pos;
		}
		current = current->next;
	}
	if (min_rank != INT_MAX)
		return (t_pos);
	current = *stka;
	while (current)
	{
		if (current->rank < min_rank)
		{
			min_rank = current->rank;
			t_pos = current->pos;
		}
		current = current->next;
	}
	return (t_pos);
}

void	assign_target_pos(t_list **stka, t_list **stkb)
{
	t_list	*current;
	int		target_pos;

	current = *stkb;
	ft_assign_pos(stka);
	ft_assign_pos(stkb);
	target_pos = 0;
	while (current)
	{
		target_pos = get_tar_pos(stka, current->rank, INT_MAX, target_pos);
		current->target_pos = target_pos;
		current = current->next;
	}
}

void	ft_assign_pos(t_list **head)
{
	t_list	*current;
	int		pos;

	current = *head;
	pos = 0;
	while (*head != NULL)
	{
		(*head)->pos = pos;
		*head = (*head)->next;
		pos++;
	}
	*head = current;
}

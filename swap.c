/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:03:36 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/05 06:08:07 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **head_a, int show)
{
	t_list	*node1;
	t_list	*node2;

	if (!(*head_a) || (*head_a)->next == NULL)
		return ;
	node1 = *head_a;
	node2 = (*head_a)->next;
	
	node1->next = node2->next;
	node2->next = node1;
	*head_a = node2;
	if (show)
		write(1, "sa\n", 3);
}

void	sb(t_list **head_b, int show)
{
	t_list	*node1;
	t_list	*node2;

	if (!(*head_b) || (*head_b)->next == NULL)
		return ;
	node1 = *head_b;
	node2 = (*head_b)->next;
	
	node1->next = node2->next;
	node2->next = node1;
	*head_b = node2;
	if (show)
		write(1, "sb\n", 3);
}

void	ss(t_list **stk_a, t_list **stk_b, int show)
{
	if (!(*stk_a) || !(*stk_b))
		return ;
	sa(stk_a, 0);
	sb(stk_b, 0);
	if (show == 1)
		write(1, "ss\n", 3);
}

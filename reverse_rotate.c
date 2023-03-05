/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:24:52 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/05 06:26:43 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stk_a, int show)
{
	t_list	*head;
	t_list	*seclast;
	t_list	*last;

	head = *stk_a;
	if (show == 1)
		write(1, "rra\n", 4);
	if (*stk_a == NULL || (*stk_a)->next == NULL)
		return ;
	seclast = NULL;
	last = *stk_a;
	while (last->next != NULL)
	{
		seclast = last;
		last = last->next;
	}
	seclast->next = NULL;
	*stk_a = last;
	last->next = head;
	
}

void	rrb(t_list **stk_b, int show)
{
	t_list	*head;
	t_list	*seclast;
	t_list	*last;

	if (show == 1)
		write(1, "rrb\n", 4);	
	if (*stk_b == NULL || (*stk_b)->next == NULL)
		return ;
	head = *stk_b;
	seclast = NULL;
	last = *stk_b;
	while (last->next != NULL)
	{
		seclast = last;
		last = last->next;
	}
	seclast->next = NULL;
	*stk_b = last;
	last->next = head;
	
}

void	rrr(t_list **stk_a, t_list **stk_b, int show)
{
	if (show == 1)
		write(1, "rrr\n", 4);
	if ((*stk_b == NULL || (*stk_b)->next == NULL)
		|| (*stk_a == NULL || (*stk_a)->next == NULL))
		return ;
	rra(stk_a, 0);
	rrb(stk_b, 0);
	
}

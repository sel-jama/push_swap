/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:35:17 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/05 06:24:49 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stk_a, int show)
{
	t_list	*head;
	t_list	*last;
	
	if (show == 1)
		write(1, "ra\n", 3);
	if (*stk_a == NULL || (*stk_a)->next == NULL)
		return ;
	head = *stk_a;
	last = ft_lstlast(*stk_a);
	last->next = *stk_a;
	*stk_a = (*stk_a)->next;
	head->next = NULL;
	
}

void	rb(t_list **stk_b, int show)
{
	t_list	*head;
	t_list	*last;

	if (show == 1)
		write(1, "rb\n", 3);
	if (*stk_b == NULL || (*stk_b)->next == NULL)
		return ;
	head = *stk_b;
	last = ft_lstlast(*stk_b);
	last->next = *stk_b;
	*stk_b = (*stk_b)->next;
	head->next = NULL;
	
}

void	rr(t_list **stk_a, t_list **stk_b, int show)
{
	if (show == 1)
		write(1, "rr\n", 3);
	if ((*stk_b == NULL || (*stk_b)->next == NULL)
		|| (*stk_a == NULL || (*stk_a)->next == NULL))
		return ;
	ra(stk_a, 0);
	rb(stk_b, 0);
	
}

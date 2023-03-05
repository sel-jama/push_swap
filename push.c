/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:39:33 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/05 06:19:37 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stk_a, t_list **stk_b, int show)
{
	t_list	*tmpa;
	t_list	*tmpb;

	if (show == 1)
		write(1, "pa\n", 3);
	if (*stk_b == NULL)
		return ;
	tmpa = *stk_a;
	tmpb = *stk_b;
	*stk_a = *stk_b;
	*stk_b = (*stk_b)->next;
	tmpb->next = tmpa;
	
}

int	pb(t_list **stk_a, t_list **stk_b, int show)
{
	t_list	*tmpa;
	t_list	*tmpb;

	if (show == 1)
		write(1, "pb\n", 3);
	if (*stk_a == NULL)
		return (1);
	tmpa = *stk_a;
	tmpb = *stk_b;
	*stk_b = *stk_a;
	*stk_a = (*stk_a)->next;
	tmpa->next = tmpb;
	
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:26:40 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/04 06:14:32 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	current = *stack;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	stack = NULL;
}

void	free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
	free(av);
}

char	*ft_strcpy(char *dst, const char *src)
{
	char	*start;

	start = dst;
	while (*src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
	}
	return (start);
}

void	ft_ko_exit_ps(char *msg, int n)
{
	ft_putendl_fd(msg, 1);
	exit(n);
}

void	initialize_stack(t_list	**stk_a, t_list **stk_b)
{
	t_list	stk;

	*stk_a = NULL;
	*stk_b = NULL;
	stk.rank = 0;
	stk.target_pos = 0;
	stk.value = 0;
	stk.cost_stack_a = 0;
	stk.cost_stack_b = 0;
}

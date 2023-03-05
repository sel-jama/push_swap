/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:18:12 by sel-jama          #+#    #+#             */
/*   Updated: 2023/02/28 22:03:31 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	largest_index(int stack_size, int *arr, int **ranks_arr)
{
	int	i;
	int	max_index;
	int	largest;

	largest = INT_MIN;
	i = 0;
	while (i < stack_size)
	{
		if (arr[i] > largest && *(*ranks_arr + i) == 0)
		{
			largest = arr[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int	*get_stack_arr(t_list **stka)
{
	int		i;
	int		stack_size;
	t_list	*temp;
	int		*arr;

	stack_size = 0;
	temp = *stka;
	i = 0;
	stack_size = ft_lstsize(temp);
	arr = (int *)malloc(sizeof(int) * stack_size);
	while (i < stack_size)
	{
		arr[i] = (*stka)->data;
		*stka = (*stka)->next;
		i++;
	}
	return (arr);
}

int	*get_ranks_arr(t_list **stka, int stack_size)
{
	int	*ranks_arr;
	int	index;
	int	i;
	int	*arr;
	int	size;

	arr = get_stack_arr(stka);
	ranks_arr = (int *)malloc(sizeof(int) * stack_size);
	if (!ranks_arr)
		return (NULL);
	i = 0;
	while (i < stack_size)
		ranks_arr[i++] = 0;
	size = stack_size;
	i = 0;
	while (i < stack_size)
	{
		index = largest_index(stack_size, arr, &ranks_arr);
		ranks_arr[index] = size--;
		i++;
	}
	free(arr);
	return (ranks_arr);
}

void	assign_rank(t_list *stack_a, int stack_size)
{
	int		*rank_arr;
	t_list	*save;
	t_list	*temp;
	int		i;

	i = 0;
	save = stack_a;
	temp = stack_a;
	rank_arr = get_ranks_arr(&temp, stack_size);
	while (stack_a != NULL)
	{
		stack_a->rank = rank_arr[i];
		i++;
		stack_a = stack_a->next;
	}
	free(rank_arr);
	stack_a = save;
}

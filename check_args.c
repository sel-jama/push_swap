/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:55:44 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/04 04:58:22 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_max_int(char **av)
{
	long long	n;
	int			i;

	i = 0;
	while (av[i])
	{
		n = ft_atoll(av[i]);
		if (n < INT_MIN || n > INT_MAX || ft_strlen(av[i]) >= 12)
			return (0);
		i++;
	}
	return (1);
}

void	check_numbers(char **av)
{
	if (!av[0])
		exit(1);
	if (check_max_int(av) == 0)
		ft_error_exit_ps("Error", 1);
}

int	is_sorted(t_list **head)
{
	t_list	*current;
	t_list	*follow;

	current = *head;
	while (current != NULL)
	{
		follow = current->next;
		while (follow != NULL)
		{
			if (current->data > follow->data)
				return (0);
			follow = follow->next;
		}
		current = current->next;
	}
	return (1);
}

void	check_duplicates(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				ft_error_exit_ps("Error", 1);
			j++;
		}
		i++;
	}
}

void	ft_check_empty(int ac, char **av)
{
	int	i;
	int	j;
	int	empty_found;

	i = -1;
	empty_found = 0;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ' && !(av[i][j] >= 9 && av[i][j] <= 13))
				break ;
			j++;
		}
		if (av[i][j] == '\0')
		{
			empty_found = 1;
			break ;
		}
	}
	if (empty_found)
		ft_error_exit_ps("Error", 1);
	if (ac < 2)
		exit(0);
}

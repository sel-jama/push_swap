/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:19:53 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/05 06:17:30 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	load_to_stack(int ac, char **av, t_list **stka, int bonus)
{
	int	i;

	i = 0;
	if (ac >= 2)
	{
		while (av[i] != NULL)
			ft_lstadd_back(stka, ft_lstnew(ft_atoll(av[i++])));
		free_av(av);
		if (is_sorted(stka) == 1)
		{
			if (bonus)
				return ;
			ft_free_stack(stka);
			exit (0);
		}
	}
}

char	**ft_split_args(int ac, char **av)
{
	int		i;
	char	**arg;

	arg = NULL;
	i = 1;
	if (ac == 2)
		arg = ft_split(av[i], ' ');
	else
	{
		av[i] = concat_args(av, ac);
		arg = ft_split(av[i], ' ');
		free(av[i]);
	}
	return (arg);
}

void	check_args(int ac, char **av, t_list **stka, int bonus)
{
	int		a;
	int		b;
	char	**arg;

	arg = ft_split_args(ac, av);
	a = -1;
	while (arg[++a] != NULL)
	{
		b = -1;
		while (arg[a][++b] != '\0')
		{
			if ((arg[a][b] == '-' || arg[a][b] == '+'))
			{
				if (b != 0)
					ft_error_exit_ps("Error", 1);
				else
					b++;
			}
			if (!(arg[a][b] >= '0' && arg[a][b] <= '9'))
				ft_error_exit_ps("Error", 1);
		}
	}
	check_numbers(arg);
	check_duplicates(arg);
	load_to_stack(ac, arg, stka, bonus);
}	

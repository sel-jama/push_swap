/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:19:48 by sel-jama          #+#    #+#             */
/*   Updated: 2023/03/04 21:32:52 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(const char *str)
{
	int			i;
	int			sign;
	long long	nb;
	char		*s;

	s = (char *)str;
	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	sign = 1;
	if (s[i] == '-')
		sign *= -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	nb = 0;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		nb = nb * 10 + (s[i] - '0');
		i++;
	}
	return (sign * nb);
}

void	ft_error_exit_ps(char *msg, int n)
{
	ft_putendl_fd(msg, 2);
	exit(n);
}

char	*concat_args(char **strings, int ac)
{
	size_t	total_length;
	int		i;
	char	*result;
	size_t	offset;

	i = 0;
	total_length = 0;
	while (++i < ac)
		total_length += ft_strlen(strings[i]) + 1;
	result = malloc(total_length);
	if (!result)
		return (NULL);
	offset = 0;
	i = 0;
	while (++i < ac)
	{
		ft_strcpy(result + offset, strings[i]);
		offset += ft_strlen(strings[i]);
		if (i < ac - 1)
			result[offset] = ' ';
		offset += 1;
	}
	result[offset - 1] = '\0';
	return (result);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

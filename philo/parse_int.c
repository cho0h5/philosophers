/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:43:23 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/21 11:30:49 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_space(char c)
{
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\r')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

static long long	ft_atol(const char *str)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		result += (str[i] - '0') * sign;
		i++;
		if ('0' <= str[i] && str[i] <= '9')
			result *= 10;
	}
	return (result);
}

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

static int	check_int_format(char *str)
{
	const int	len = ft_strlen(str);
	int			i;

	if (len >= 12 || len == 0)
		return (-1);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (len <= 1)
			return (-1);
		i++;
	}
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (0);
}

long long	parse_int(char *str)
{
	long long	num;

	if (check_int_format(str) == -1)
		return (NOT_INT);
	num = ft_atol(str);
	if (num > ~(1 << (8 * sizeof(int) - 1)))
		return (NOT_INT);
	if (num < 1 << (8 * sizeof(int) - 1))
		return (NOT_INT);
	if (num <= 0)
		return (NOT_INT);
	return (num);
}

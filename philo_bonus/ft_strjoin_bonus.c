/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:06:39 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/21 11:32:18 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	size = ft_strlen(s1) + ft_strlen(s2);
	char			*result;

	result = ft_calloc(size + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, size + 1);
	ft_strlcat(result, s2, size + 1);
	return (result);
}

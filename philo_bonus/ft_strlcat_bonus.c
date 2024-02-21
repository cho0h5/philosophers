/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:03:13 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/21 11:32:19 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		dstlen;

	i = 0;
	while (i < dstsize && dst[i] != '\0')
		i++;
	dstlen = i;
	if (i == dstsize)
		return (dstlen + ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && dstlen + i + 1 < dstsize)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + ft_strlen(src));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:34:06 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/16 16:34:19 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdio.h>
#include <stdlib.h>

void panic(char *error_message)
{
	printf("%s\n", error_message);
	exit(1);
}


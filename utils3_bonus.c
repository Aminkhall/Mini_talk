/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallou <mkhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:20:35 by mkhallou          #+#    #+#             */
/*   Updated: 2025/03/07 15:06:47 by mkhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

int	is_valid(int c)
{
	return ((c >= '0' && c <= '9') || c == '+');
}

int	ft_isdigit2(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == '+')
			count++;
		if (!is_valid(*s))
			return (1);
		s++;
	}
	if (count > 1)
		return (1);
	return (0);
}

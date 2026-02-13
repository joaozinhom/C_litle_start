/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftargs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:20:24 by joamoren          #+#    #+#             */
/*   Updated: 2026/02/01 09:20:24 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		return (0);
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
	i++;
	}
	return (1);
}

char	*normalize_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0' && str[i + 1] != '\0')
	{
		i++;
	}
	return (&str[i]);
}

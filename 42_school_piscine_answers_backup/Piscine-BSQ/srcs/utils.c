/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:40:45 by joamoren          #+#    #+#             */
/*   Updated: 2026/02/03 14:16:07 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

void	ft_putstr(char *str)
{
	int		i;
	ssize_t	ret;

	i = 0;
	while (str[i] != '\0')
	{
		ret = write(1, &str[i], 1);
		(void)ret;
		i++;
	}
}

int	convert_to_number(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	ft_isdigit(char a)
{
	return (a >= '0' && a <= '9');
}

int	ft_isprint(char a)
{
	return (a >= 32 && a <= 126);
}

int	min3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}
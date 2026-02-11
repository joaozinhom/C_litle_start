/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:23:37 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/14 13:57:53 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	positive;
	char	negative;

	positive = 'P';
	negative = 'N';
	if (n < 0)
	{
		write(1, &negative, 1);
	}
	else if (n >= 0)
	{
		write(1, &positive, 1);
	}
}
/*
int	main()
{
	ft_is_negative(0);
	ft_is_negative(-42);
	ft_is_negative(42);
	return 0;
}
*/
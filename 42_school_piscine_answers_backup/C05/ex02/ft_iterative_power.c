/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:58:20 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/21 14:04:18 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	original;

	original = nb;
	if (power == 0)
	{
		return (1);
	}
	power = power - 1;
	while (power != 0)
	{
		nb *= original;
		power--;
	}
	return (nb);
}

/*
int main()
{
	printf("%d", ft_iterative_power(3, 3));
}
*/
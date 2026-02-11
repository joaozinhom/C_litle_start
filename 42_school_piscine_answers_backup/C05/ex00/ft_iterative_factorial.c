/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 08:48:30 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/21 09:33:16 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	while (nb != 0)
	{
		result *= nb;
		--nb;
	}
	return (result);
}
/*
int main()
{
	printf("%d", ft_iterative_factorial(5));
	return 0;
}
*/
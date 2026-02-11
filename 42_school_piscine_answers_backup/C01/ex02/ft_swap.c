/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:44:58 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/15 17:12:45 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	copy;

	copy = *a;
	*a = *b;
	*b = copy;
}


int main()
{
	int something1 = 0;
	int something2 = 1;
	ft_swap(&something1, &something2);
	printf("%d", something1);
	printf("%d", something2);
	return 0;
}


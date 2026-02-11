/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:06:46 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/15 16:38:17 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}


int main()
{
	int something;
	ft_ft(&something);
	printf("%d", something);
	return 0;
}

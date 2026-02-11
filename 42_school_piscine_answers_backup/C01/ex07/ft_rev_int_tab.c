/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:19:30 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/15 11:10:08 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tempo;

	i = 0;
	while (i < size / 2)
	{
		tempo = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tempo;
		i++;
	}
}

/*
int main()
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	printf("%d\n", array[0]);

	ft_rev_int_tab(array, 9);

	printf("%d\n", array[0]);
	return (0);
}
*/
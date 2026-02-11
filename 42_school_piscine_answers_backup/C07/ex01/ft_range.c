/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:31:41 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/27 13:47:35 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*range;

	i = min;
	if (min >= max)
	{
		return (NULL);
	}
	while (i != max)
	{
		i++;
	}
	range = malloc(sizeof(int) * (max - min));
	i = 0;
	while (i < max - min)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
// #include <stdio.h>
// int main(){
// 	int i = 0;
// 	int *numbers = ft_range(0, 10);
// 	while(i < 9){
// 		printf("%d", numbers[i]);
// 		i++;
// 	}
// 	return (0);
// }
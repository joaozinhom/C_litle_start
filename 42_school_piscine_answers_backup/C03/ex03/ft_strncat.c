/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 10:43:11 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/19 09:27:40 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	end_of_dest;
	unsigned int	i;

	i = 0;
	end_of_dest = 0;
	while (dest[end_of_dest] != '\0')
	{
		end_of_dest++;
	}
	while (src[i] != '\0' && i < nb)
	{
		dest[end_of_dest + i] = src[i];
		i++;
	}
	dest[end_of_dest + i] = '\0';
	return (dest);
}
/*
int main()
{
	char algo1[10] = "B";
	char *algo2 = "A";
	char *resposta = ft_strcat(algo1, algo2);
	printf("%s", resposta);
}
*/
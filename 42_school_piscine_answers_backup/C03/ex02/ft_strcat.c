/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 10:15:01 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/19 09:17:35 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	end_of_dest;

	i = 0;
	end_of_dest = 0;
	while (dest[end_of_dest] != '\0')
	{
		end_of_dest++;
	}
	while (src[i] != '\0')
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
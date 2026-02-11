/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:30:08 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/17 13:03:56 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

/*
int main() {
char *something = "Olá, mundo!";


char copy[20];

printf("%s\n",copy);
printf("%s\n", something);
ft_strcpy(copy, something);
printf("%s\n",copy);
printf("%s\n", something);


return 0;
}
*/
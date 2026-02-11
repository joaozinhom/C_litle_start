/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 11:24:34 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/28 15:10:12 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = 0;
	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	while (dest[dest_len] != '\0' && dest_len != size)
	{
		dest_len++;
	}
	if (dest_len < size)
	{
		while (src[i] != '\0' && (dest_len + i) < (size - 1))
		{
			dest[dest_len + i] = src[i];
			i++;
		}
		dest[dest_len + i] = '\0';
	}
	return (dest_len + src_len);
}


int main()
{
	char d1[20] = "Ola ";
	char *s1 = "Mundo";
	unsigned int r1;
	r1 = ft_strlcat(d1, s1, 6);
	printf("%d", r1);
}

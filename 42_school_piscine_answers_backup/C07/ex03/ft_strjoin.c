/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:48:40 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/28 09:49:31 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* */
/* :::      ::::::::   */
/* ft_strjoin.c                                       :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/01/28 08:48:40 by joamoren          #+#    #+#             */
/* Updated: 2026/01/28 09:36:25 by joamoren         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest + i);
}

int	get_total_len(int size, char **strs, char *sep)
{
	int	full_len;
	int	i;

	full_len = 0;
	i = 0;
	while (i < size)
	{
		full_len += ft_strlen(strs[i]);
		if (i < size - 1)
			full_len += ft_strlen(sep);
		i++;
	}
	return (full_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		full_len;
	int		i;
	char	*res;
	char	*ptr;

	if (size <= 0)
		return ((char *)malloc(sizeof(char)));
	full_len = get_total_len(size, strs, sep);
	i = 0;
	res = (char *)malloc(sizeof(char) * (full_len + 1));
	if (!res)
		return (NULL);
	ptr = res;
	i = 0;
	while (i < size)
	{
		ptr = ft_strcpy(ptr, strs[i]);
		if (i < size - 1)
			ptr = ft_strcpy(ptr, sep);
		i++;
	}
	*ptr = '\0';
	return (res);
}


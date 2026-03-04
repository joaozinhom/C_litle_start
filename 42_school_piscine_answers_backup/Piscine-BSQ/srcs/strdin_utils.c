/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdin_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:10:00 by joamoren          #+#    #+#             */
/*   Updated: 2026/02/04 17:26:34 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

void	*ft_memcpy(void *dest, const void *src, int n)
{
	int				i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

static char	*append_buffer(char *buffer, char *temp, int total, int bytes)
{
	char	*new_buffer;

	new_buffer = malloc(total + bytes + 1);
	if (!new_buffer)
	{
		if (buffer)
			free(buffer);
		return (NULL);
	}
	if (buffer)
	{
		ft_memcpy(new_buffer, buffer, total);
		free(buffer);
	}
	ft_memcpy(new_buffer + total, temp, bytes);
	return (new_buffer);
}

char	*read_stdin(void)
{
	char	temp[4096];
	char	*buffer;
	int		bytes;
	int		total_size;

	buffer = NULL;
	total_size = 0;
	bytes = read(0, temp, 4096);
	while (bytes > 0)
	{
		buffer = append_buffer(buffer, temp, total_size, bytes);
		if (!buffer)
			return (NULL);
		total_size += bytes;
		bytes = read(0, temp, 4096);
	}
	if (buffer)
		buffer[total_size] = '\0';
	return (buffer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:57:47 by joamoren          #+#    #+#             */
/*   Updated: 2026/02/03 14:09:04 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

static int	check_printable(char *buf, int i)
{
	if (!ft_isprint(buf[i]))
		return (0);
	if (!ft_isprint(buf[i + 1]))
		return (0);
	if (!ft_isprint(buf[i + 2]))
		return (0);
	return (1);
}

static int	verify_map_line(char *buf, int i, int len, char *c)
{
	int	k;

	k = 0;
	while (k < len)
	{
		if (buf[i + k] != c[0] && buf[i + k] != c[1] && buf[i + k] != c[2])
			return (0);
		k++;
	}
	return (1);
}

static int	verify_map(char *buf, int start, int line_len, char *c)
{
	int	i;
	int	j;
	int	map_lines;

	map_lines = 0;
	i = start;
	while (buf[i] != '\0')
	{
		j = 0;
		while (buf[i + j] != '\n' && buf[i + j] != '\0')
			j++;
		if (j != line_len)
			return (0);
		if (!verify_map_line(buf, i, line_len, c))
			return (0);
		map_lines++;
		i += j;
		if (buf[i] == '\n')
			i++;
	}
	return (map_lines > 0);
}

static int	parse_header(char *buf, int *out_hdr, char *c)
{
	int	i;
	int	n;

	i = 0;
	if (!ft_isdigit(buf[i]))
		return (0);
	while (ft_isdigit(buf[i]))
		i++;
	n = convert_to_number(buf);
	if (n <= 0)
		return (0);
	if (!check_printable(buf, i))
		return (0);
	c[0] = buf[i];
	c[1] = buf[i + 1];
	c[2] = buf[i + 2];
	if (c[0] == c[1] || c[0] == c[2] || c[1] == c[2])
		return (0);
	i += 3;
	if (buf[i] != '\n')
		return (0);
	*out_hdr = i + 1;
	return (1);
}

int	verify_input(char *buf)
{
	int		header_len;
	int		line_len;
	int		i;
	char	c[3];

	if (!buf || buf[0] == '\0')
		return (0);
	if (!parse_header(buf, &header_len, c))
		return (0);
	if (buf[header_len] == '\0')
		return (0);
	i = header_len;
	line_len = 0;
	while (buf[i + line_len] != '\n' && buf[i + line_len] != '\0')
		line_len++;
	if (line_len == 0)
		return (0);
	return (verify_map(buf, header_len, line_len, c));
}

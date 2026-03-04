/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:42:35 by joamoren          #+#    #+#             */
/*   Updated: 2026/02/04 17:04:50 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

int	get_file_size(char *path)
{
	int		fd;
	int		total_size;
	int		bytes;
	char	temp[4096];

	total_size = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	bytes = read(fd, temp, 4096);
	while (bytes > 0)
	{
		total_size += bytes;
		bytes = read(fd, temp, 4096);
	}
	close(fd);
	return (total_size);
}

char	*read_file(char *path)
{
	int		fd;
	int		total_size;
	char	*buf;
	ssize_t	ret;

	total_size = get_file_size(path);
	if (total_size < 0)
		return (NULL);
	buf = malloc(sizeof(char) * (total_size + 1));
	if (buf == NULL)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(buf);
		return (NULL);
	}
	ret = read(fd, buf, total_size);
	(void)ret;
	buf[total_size] = '\0';
	close(fd);
	return (buf);
}

void	parse_header(char *buf, t_values *dict, int *i)
{
	int	n;

	n = convert_to_number(&buf[0]);
	dict->size_n = n;
	*i = 0;
	while (buf[*i] >= '0' && buf[*i] <= '9')
		(*i)++;
	dict->empty = buf[*i];
	dict->obstacle = buf[*i + 1];
	dict->fill = buf[*i + 2];
	*i += 3;
	if (buf[*i] == '\n')
		(*i)++;
}

void	copy_rows(char *buf, char *dest, t_values *dict, int i)
{
	int	j;
	int	k;

	k = 0;
	while (buf[i] != '\0' && k < dict->size_n)
	{
		j = 0;
		while (j < dict->cols && buf[i + j] != '\n' && buf[i + j] != '\0')
		{
			dest[k * dict->cols + j] = buf[i + j];
			j++;
		}
		k++;
		i += j;
		if (buf[i] == '\n')
			i++;
	}
}

void	encode(char *buf, t_values *dict, char **dest)
{
	int	i;
	int	row_len;

	parse_header(buf, dict, &i);
	row_len = 0;
	while (buf[i + row_len] != '\n' && buf[i + row_len] != '\0')
		row_len++;
	dict->cols = row_len;
	*dest = malloc(sizeof(char) * (dict->size_n * row_len));
	copy_rows(buf, *dest, dict, i);
}
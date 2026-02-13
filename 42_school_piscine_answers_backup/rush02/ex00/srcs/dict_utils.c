/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftio.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:20:17 by joamoren          #+#    #+#             */
/*   Updated: 2026/02/01 09:20:17 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

char	*read_file(char *path)
{
	int		awnser_from_file;
	int		total_size;
	int		bytes;
	char	temp[4096];
	char	*buf;

	total_size = 0;
	awnser_from_file = open(path, 00);
	if (awnser_from_file < 0)
		return (NULL);
	bytes = read(awnser_from_file, temp, 4096);
	while (bytes > 0)
	{
		total_size = total_size + bytes;
		bytes = read(awnser_from_file, temp, 4096);
	}
	close(awnser_from_file);
	buf = malloc(sizeof(char) * (total_size + 1));
	if (buf == NULL)
		return (NULL);
	awnser_from_file = open(path, 00);
	read(awnser_from_file, buf, total_size);
	buf[total_size] = '\0';
	close(awnser_from_file);
	return (buf);
}

void	free_dict(t_dict *dict)
{
	int	i;

	if (dict == NULL)
	{
		return ;
	}
	i = 0;
	while (i < dict->size)
	{
		if (dict->entries[i].key != NULL)
		{
			free(dict->entries[i].key);
		}
		if (dict->entries[i].val != NULL)
		{
			free(dict->entries[i].val);
		}
		i++;
	}
	if (dict->entries != NULL)
	{
		free(dict->entries);
	}
	free(dict);
}

char	*get_value_by_dict(t_dict *dict, char *key)
{
	int	i;

	i = 0;
	while (i < dict->size)
	{
		if (ft_strcmp(dict->entries[i].key, key) == 0)
		{
			return (dict->entries[i].val);
		}
		i++;
	}
	return (NULL);
}

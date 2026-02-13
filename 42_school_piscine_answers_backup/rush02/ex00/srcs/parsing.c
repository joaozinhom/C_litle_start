/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftparse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:20:04 by joamoren          #+#    #+#             */
/*   Updated: 2026/02/01 09:20:04 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

t_dict	*init_dict_memory(void)
{
	t_dict	*dict;

	dict = malloc(sizeof(t_dict));
	if (dict == NULL)
	{
		return (NULL);
	}
	dict->entries = malloc(sizeof(t_dict_entry) * 5000);
	if (dict->entries == NULL)
	{
		free(dict);
		return (NULL);
	}
	return (dict);
}

char	*get_next_line_ptr(char *current_line)
{
	char	*ptr;

	ptr = ft_strchr(current_line, '\n');
	if (ptr != NULL)
	{
		*ptr = '\0';
		return (ptr + 1);
	}
	return (NULL);
}

void	process_dict_content(t_dict *dict, char *current_line)
{
	char	*next_line_ptr;
	int		entry_count;

	entry_count = 0;
	while (current_line != NULL && *current_line != '\0')
	{
		next_line_ptr = get_next_line_ptr(current_line);
		if (parse_line(current_line, &dict->entries[entry_count]) == 1)
		{
			entry_count = entry_count + 1;
		}
		current_line = next_line_ptr;
	}
	dict->size = entry_count;
}

t_dict	*parse_dict(char *full_content)
{
	t_dict	*dict;

	if (full_content == NULL)
	{
		return (NULL);
	}
	dict = init_dict_memory();
	if (dict == NULL)
	{
		return (NULL);
	}
	process_dict_content(dict, full_content);
	return (dict);
}

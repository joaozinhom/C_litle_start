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

char	*str_trim(char *str)
{
	int	i;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	i = ft_strlen(str) - 1;
	if (i < 0)
	{
		return (str);
	}
	while (i >= 0 && (((str[i] == ' '
					|| str[i] >= 0) && (str[i] <= 32 || str[i] == 127))))
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}

int	parse_line(char *line, t_dict_entry *entry)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != ':')
	{
		i++;
	}
	if (line[i] != ':')
	{
		return (0);
	}
	line[i] = '\0';
	entry->key = ft_strdup(str_trim(line));
	if (entry->key == NULL)
	{
		return (0);
	}
	entry->val = ft_strdup(str_trim(&line[i + 1]));
	if (entry->val == NULL)
	{
		free(entry->key);
		return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcheck_input_in_dict.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:22:31 by joamoren          #+#    #+#             */
/*   Updated: 2026/02/01 09:47:02 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

int	count_zeros(char *str)
{
	int	count;
	int	i;

	if (str[0] != '1')
		return (-1);
	count = 0;
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] != '0')
			return (-1);
		count++;
		i++;
	}
	return (count);
}

int	get_max_power_of_ten(t_dict *dict)
{
	int	i;
	int	max_zeros;
	int	current_zeros;

	max_zeros = 0;
	i = 0;
	while (i < dict->size)
	{
		current_zeros = count_zeros(dict->entries[i].key);
		if (current_zeros > max_zeros)
		{
			max_zeros = current_zeros;
		}
		i++;
	}
	return (max_zeros);
}

int	is_number_valid_for_dict(char *number, t_dict *dict)
{
	int	num_len;
	int	max_zeros;
	int	max_supported_len;

	num_len = ft_strlen(number);
	max_zeros = get_max_power_of_ten(dict);
	max_supported_len = max_zeros + 3;
	if (num_len > max_supported_len)
	{
		return (0);
	}
	return (1);
}

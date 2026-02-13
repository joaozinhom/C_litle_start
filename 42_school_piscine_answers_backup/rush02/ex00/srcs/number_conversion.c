/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftconvert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:20:20 by joamoren          #+#    #+#             */
/*   Updated: 2026/02/01 09:20:20 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

char	*generate_power_of_ten(int zeros)
{
	char	*key;
	int		i;

	if (zeros <= 0)
		return (NULL);
	key = malloc(sizeof(char) * (zeros + 2));
	if (key == NULL)
		return (NULL);
	key[0] = '1';
	i = 1;
	while (i <= zeros)
	{
		key[i] = '0';
		i++;
	}
	key[i] = '\0';
	return (key);
}

int	get_triplet_value(char *str, int len)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (i < len)
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n);
}

void	convert_triplet(t_dict *dict, int n, int *is_space)
{
	convert_hundreds(dict, &n, is_space);
	if (n >= 10 && n <= 19)
	{
		convert_teens(dict, n, is_space);
	}
	else
	{
		convert_tens(dict, &n, is_space);
		convert_units(dict, n, is_space);
	}
}

int	get_chunk_size(int len)
{
	if (len % 3 == 0)
		return (3);
	return (len % 3);
}

void	process_triplet(char **nbr, int *len, t_dict *dict, int *is_space)
{
	int		chunk;
	int		triplet_num;
	char	*power_of_ten;

	chunk = get_chunk_size(*len);
	triplet_num = get_triplet_value(*nbr, chunk);
	if (triplet_num > 0)
	{
		convert_triplet(dict, triplet_num, is_space);
		power_of_ten = generate_power_of_ten(*len - chunk);
		if (power_of_ten)
		{
			print_word(get_value_by_dict(dict, power_of_ten), is_space);
			free(power_of_ten);
		}
	}
	*nbr += chunk;
	*len -= chunk;
}

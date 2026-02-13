/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:20:20 by joamoren          #+#    #+#             */
/*   Updated: 2026/02/01 10:06:34 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

void	convert_hundreds(t_dict *dict, int *n, int *is_space)
{
	char	key[3];

	if (*n >= 100)
	{
		key[0] = (*n / 100) + '0';
		key[1] = '\0';
		print_word(get_value_by_dict(dict, key), is_space);
		print_word(get_value_by_dict(dict, "100"), is_space);
		*n %= 100;
	}
}

void	convert_tens(t_dict *dict, int *n, int *is_space)
{
	char	key[3];

	if (*n >= 20)
	{
		key[0] = (*n / 10) + '0';
		key[1] = '0';
		key[2] = '\0';
		print_word(get_value_by_dict(dict, key), is_space);
		*n %= 10;
	}
}

void	convert_teens(t_dict *dict, int n, int *is_space)
{
	char	key[3];

	key[0] = '1';
	key[1] = (n % 10) + '0';
	key[2] = '\0';
	print_word(get_value_by_dict(dict, key), is_space);
}

void	convert_units(t_dict *dict, int n, int *is_space)
{
	char	key[2];

	if (n > 0)
	{
		key[0] = n + '0';
		key[1] = '\0';
		print_word(get_value_by_dict(dict, key), is_space);
	}
}

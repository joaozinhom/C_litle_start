/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftconvert_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:20:20 by joamoren          #+#    #+#             */
/*   Updated: 2026/02/01 10:21:52 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

void	convert_number(char *nbr, t_dict *dict)
{
	int		len;
	int		is_space;

	is_space = 1;
	len = ft_strlen(nbr);
	if (len == 1 && nbr[0] == '0')
	{
		print_word(get_value_by_dict(dict, "0"), &is_space);
		return ;
	}
	while (len > 0)
	{
		process_triplet(&nbr, &len, dict, &is_space);
	}
}

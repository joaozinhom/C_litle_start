/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftinput_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:28:54 by joamoren          #+#    #+#             */
/*   Updated: 2026/02/01 09:36:03 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_word(char *word, int *is_space)
{
	if (word == NULL)
		return ;
	if (*is_space == 0)
		write(1, " ", 1);
	ft_putstr(word);
	*is_space = 0;
}

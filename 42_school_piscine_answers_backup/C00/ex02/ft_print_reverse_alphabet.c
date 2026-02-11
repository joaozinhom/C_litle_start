/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:52:27 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/14 13:29:43 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	ch;

	ch = 'z';
	while (ch != '`')
	{
		write(1, &ch, 1);
		ch--;
	}
}

/*
int main(void)
{
    ft_print_reverse_alphabet();
    return 0;
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:59:49 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/14 13:34:16 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	c;
	int		n;

	n = 0;
	while (n <= 9)
	{
		c = '0' + n;
		write(1, &c, 1);
		n++;
	}
}

/*
int	main()
{
	ft_print_numbers();
	return 0;
}
*/
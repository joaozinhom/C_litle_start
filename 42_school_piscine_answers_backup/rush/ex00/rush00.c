/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:52:02 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/18 14:21:19 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c);

void	verify(int x, int y, int actual_x, int actual_y)
{
	if (((actual_y == 1) && (actual_x == 1))
		|| ((actual_y == 1) && (actual_x == x))
		|| ((actual_y == y) && (actual_x == 1))
		|| ((actual_y == y) && (actual_x == x)))
	{
		ft_putchar('o');
	}
	else if ((actual_y != 1) && (actual_y != y)
		&& (actual_x != 1) && (actual_x != x))
	{
		ft_putchar(' ');
	}
	else if ((actual_y != 1) && (actual_y != y)
		&& (actual_x == 1) || (actual_x == x))
	{
		ft_putchar('|');
	}
	else
	{
		ft_putchar('-');
	}
}

void	rush(int x, int y)
{
	int	actual_x;
	int	actual_y;

	if (x <= 0 || y <= 0 || x > 190 || y > 2147483647)
	{
		write(1, "Please input a valid non negative int!\n", 40);
		return ;
	}
	actual_y = 1;
	while (actual_y <= y)
	{
		actual_x = 1;
		while (actual_x <= x)
		{
			verify(x, y, actual_x, actual_y);
			actual_x++;
		}
		ft_putchar('\n');
		actual_y++;
	}
}

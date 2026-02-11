/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:38:09 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/24 16:36:11 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str);
int		solve(int matrix[16], int tips[16], int pos);

int	main(int argc, char **argv)
{
	int	tips[16];
	int	matrix[16];
	int	i;
	int	j;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}

	i = 0;
	while (i < 16)
		matrix[i++] = 0;

	i = 0;
	j = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= '1' && argv[1][i] <= '4')
		{
			if (j >= 16) 
			{
				write(1, "Error\n", 6);
				return (1);
			}
			tips[j++] = argv[1][i] - '0';
		}
		else if (argv[1][i] != ' ')
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}

	if (j != 16)
	{
		write(1, "Error\n", 6);
		return (1);
	}

	if (solve(matrix, tips, 0))
	{
		i = 0;
		while (i < 16)
		{
			char c = matrix[i] + '0';
			write(1, &c, 1);
			if (i % 4 == 3)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
			i++;
		}
	}
	else
		write(1, "Error\n", 6);

	return (0);
}
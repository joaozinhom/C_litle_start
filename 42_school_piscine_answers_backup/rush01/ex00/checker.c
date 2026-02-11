/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:24:55 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/24 17:06:36 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void cut(int *src, int *dest, int start, int jump, int rev)
{
	int step;

	if (rev == 1)
	{
		step = -jump;
	}
	else
	{
		step = jump;
	}

	int i = 0;
	int current = start;

	while (i < 4)
	{
		dest[i] = src[current];
		current = current + step;
		i++;
	}
}
int check(int line[4], int tip)
{
	int i = 0;
	int actual_big_digit = line[0];
	int actual_maxviex = 1;

	while (i < 4)
	{
		if (line[i] > actual_big_digit)
		{
			actual_big_digit = line[i];
			actual_maxviex++;
		}
		i++;
	}
	return (actual_maxviex == tip);
}

int check_matrix(int matrix[16], int tip[16])
{
	int cut_dest[4] = {0};

	// TOP-DOWN
	cut(matrix, cut_dest, 0, 4, 0);
	if (!check(cut_dest, tip[0]))
		return 0;
	cut(matrix, cut_dest, 1, 4, 0);
	if (!check(cut_dest, tip[1]))
		return 0;
	cut(matrix, cut_dest, 2, 4, 0);
	if (!check(cut_dest, tip[2]))
		return 0;
	cut(matrix, cut_dest, 3, 4, 0);
	if (!check(cut_dest, tip[3]))
		return 0;

	// BOTTOM-UP
	cut(matrix, cut_dest, 12, 4, 1);
	if (!check(cut_dest, tip[4]))
		return 0;
	cut(matrix, cut_dest, 13, 4, 1);
	if (!check(cut_dest, tip[5]))
		return 0;
	cut(matrix, cut_dest, 14, 4, 1);
	if (!check(cut_dest, tip[6]))
		return 0;
	cut(matrix, cut_dest, 15, 4, 1);
	if (!check(cut_dest, tip[7]))
		return 0;

	// LEFT-RIGHT
	cut(matrix, cut_dest, 0, 1, 0);
	if (!check(cut_dest, tip[8]))
		return 0;
	cut(matrix, cut_dest, 4, 1, 0);
	if (!check(cut_dest, tip[9]))
		return 0;
	cut(matrix, cut_dest, 8, 1, 0);
	if (!check(cut_dest, tip[10]))
		return 0;
	cut(matrix, cut_dest, 12, 1, 0);
	if (!check(cut_dest, tip[11]))
		return 0;

	// RIGHT-LEFT
	cut(matrix, cut_dest, 3, 1, 1);
	if (!check(cut_dest, tip[12]))
		return 0;
	cut(matrix, cut_dest, 7, 1, 1);
	if (!check(cut_dest, tip[13]))
		return 0;
	cut(matrix, cut_dest, 11, 1, 1);
	if (!check(cut_dest, tip[14]))
		return 0;
	cut(matrix, cut_dest, 15, 1, 1);
	if (!check(cut_dest, tip[15]))
		return 0;

	return 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:25:02 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/24 16:39:22 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void cut(int *src, int *dest, int start, int jump, int rev);
int	check(int line[4], int tip);
int	check_matrix(int matrix[16], int tip[16]);

int	isSafe(int matrix[16], int row, int col, int num)
{
	int i = 0;
	while (i < 4)
	{
		if (matrix[row * 4 + i] == num)
			return 0;
		if (matrix[i * 4 + col] == num)
			return 0;
		i++;
	}
	return 1;
}

int solve(int matrix[16], int tips[16], int pos)
{
	if (pos == 16)
	{
		return check_matrix(matrix, tips);
	}

	int num = 1;
	while (num <= 4)
	{
		if (isSafe(matrix, pos / 4, pos % 4, num))
		{
			matrix[pos] = num;

			if (solve(matrix, tips, pos + 1))
				return 1;

			matrix[pos] = 0;
		}
		num++;
	}
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:10:57 by joamoren          #+#    #+#             */
/*   Updated: 2026/02/04 11:28:04 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

t_square	square_inicialize(t_square sqr)
{
	sqr.size = 0;
	sqr.max_i = 0;
	sqr.max_j = 0;
	return (sqr);
}

static int	calc_cell(int **cp, int i, int j)
{
	if (i == 0 || j == 0)
		return (1);
	return (1 + min3(cp[i][j - 1], cp[i - 1][j], cp[i - 1][j - 1]));
}

static void	update_square(int val, t_square *sqr, int i, int j)
{
	if (val > sqr->size)
	{
		sqr->size = val;
		sqr->max_i = i;
		sqr->max_j = j;
	}
}

t_square	square_info(char **str, t_values values)
{
	int			i;
	int			j;
	t_square	square;
	int			**cp;

	cp = matrix_alloc(values.cols);
	square = square_inicialize(square);
	i = 0;
	while (i < values.cols)
	{
		j = 0;
		while (j < values.cols)
		{
			if (str[i][j] == values.obstacle)
				cp[i][j] = 0;
			else
				cp[i][j] = calc_cell(cp, i, j);
			update_square(cp[i][j], &square, i, j);
			j++;
		}
		i++;
	}
	matrix_free(cp, values.cols);
	return (square);
}

char	**new_square(char **str, t_values values)
{
	int			i;
	int			j;
	t_square	sqr;

	sqr = square_info(str, values);
	i = sqr.max_i - (sqr.size - 1);
	while (i <= sqr.max_i)
	{
		j = sqr.max_j - (sqr.size - 1);
		while (j <= sqr.max_j)
		{
			str[i][j] = values.fill;
			j++;
		}
		i++;
	}
	return (str);
}

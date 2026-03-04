/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:39:44 by joamoren          #+#    #+#             */
/*   Updated: 2026/02/04 17:27:07 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

void	print_matrix(char **matrix_array, int rows, int cols)
{
	int		i;
	int		j;
	ssize_t	ret;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			ret = write(1, &matrix_array[i][j], 1);
			(void)ret;
			j++;
		}
		ret = write(1, "\n", 1);
		(void)ret;
		i++;
	}
}

int	**matrix_alloc(int size)
{
	int	i;
	int	**cp;

	cp = malloc(sizeof(int *) * size);
	i = 0;
	while (i < size)
	{
		cp[i] = malloc(sizeof(int) * size);
		i++;
	}
	return (cp);
}

int	check_char(char c, t_values *dict)
{
	if (c == dict->empty || c == dict->fill || c == dict->obstacle)
		return (1);
	return (0);
}

void	matrix_free(int **cp, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(cp[i]);
		i++;
	}
	free(cp);
}
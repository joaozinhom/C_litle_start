/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:13:23 by joamoren          #+#    #+#             */
/*   Updated: 2026/02/04 19:03:34 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

static char	**build_matrix(char *dest, int rows, int cols, t_values dict)
{
	char	**matrix;
	int		i;

	matrix = malloc(rows * sizeof(char *));
	i = 0;
	while (i < rows)
	{
		matrix[i] = dest + i * cols;
		i++;
	}
	if (rows != cols || rows != dict.size_n || cols != dict.size_n)
		matrix = NULL;
	return (matrix);
}

static void	process(char *buffer)
{
	t_values	dict;
	char		*dest;
	char		**matrix;

	dest = NULL;
	encode(buffer, &dict, &dest);
	matrix = build_matrix(dest, dict.size_n, dict.cols, dict);
	if (!matrix)
	{
		ft_putstr("map error\n");
		free(matrix);
		free(dest);
		return ;
	}
	new_square(matrix, dict);
	print_matrix(matrix, dict.size_n, dict.cols);
	free(matrix);
	free(dest);
}

void	run_argvs(int argc, char **argv)
{
	char	*buffer;
	int		i;

	i = 1;
	while (i < argc)
	{
		buffer = read_file(argv[i]);
		if (!buffer || !verify_input(buffer))
		{
			ft_putstr("map error\n");
			if (buffer)
				free(buffer);
		}
		else
		{
			process(buffer);
			free(buffer);
			if (i < argc - 1)
				ft_putstr("\n");
		}
		i++;
	}
}

int	run_stdin(void)
{
	char	*buffer;

	buffer = read_stdin();
	if (!buffer || !verify_input(buffer))
	{
		ft_putstr("map error\n");
		if (buffer)
			free(buffer);
		return (0);
	}
	process(buffer);
	free(buffer);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		if (run_stdin() == 1)
			return (0);
		else
			return (1);
	}
	run_argvs(argc, argv);
	return (0);
}

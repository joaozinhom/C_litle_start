/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:19:50 by joamoren          #+#    #+#             */
/*   Updated: 2026/02/01 09:19:50 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

t_dict	*load_dictionary(char *path)
{
	char	*content;
	t_dict	*dict;

	content = read_file(path);
	if (content == NULL)
	{
		return (NULL);
	}
	dict = parse_dict(content);
	free(content);
	if (!dict)
	{
		return (NULL);
	}
	return (dict);
}

int	process_rush(char *number, char *dict_path)
{
	t_dict	*dict;
	char	*clean_num;

	dict = load_dictionary(dict_path);
	if (dict == NULL)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	clean_num = normalize_number(number);
	if (!is_number_valid_for_dict(clean_num, dict))
	{
		free_dict(dict);
		ft_putstr("Dict Error\n");
		return (0);
	}
	convert_number(clean_num, dict);
	write(1, "\n", 1);
	free_dict(dict);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*dict_path;
	char	*number;

	if (argc < 2 || argc > 3)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	dict_path = "numbers.dict";
	number = argv[1];
	if (argc == 3)
	{
		dict_path = argv[1];
		number = argv[2];
	}
	if (!is_valid_number(number))
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (process_rush(number, dict_path));
}

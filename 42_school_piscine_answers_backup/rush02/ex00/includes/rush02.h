/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:20:30 by joamoren          #+#    #+#             */
/*   Updated: 2026/02/01 09:20:30 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../includes/rush02.h"

typedef struct s_dict_entry
{
	char	*key;
	char	*val;
}	t_dict_entry;

typedef struct s_dict
{
	t_dict_entry	*entries;
	int				size;
}	t_dict;

void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *src);
int		is_valid_number(char *str);
char	*normalize_number(char *str);
char	*read_file(char *path);
t_dict	*parse_dict(char *content);
int		parse_line(char *line, t_dict_entry *entry);
char	*str_trim(char *str);
char	*get_value_by_dict(t_dict *dict, char *key);
void	convert_triplet(t_dict *dict, int n, int *first);
void	print_word(char *word, int *first);
int		count_zeros(char *str);
int		get_max_power_of_ten(t_dict *dict);
int		is_number_valid_for_dict(char *number, t_dict *dict);
void	free_dict(t_dict *dict);

void	convert_hundreds(t_dict *dict, int *n, int *is_space);
void	convert_tens(t_dict *dict, int *n, int *is_space);
void	convert_teens(t_dict *dict, int n, int *is_space);
void	convert_units(t_dict *dict, int n, int *is_space);

char	*generate_power_of_ten(int zeros);
int		get_triplet_value(char *str, int len);
void	convert_triplet(t_dict *dict, int n, int *is_space);
int		get_chunk_size(int len);
void	process_triplet(char **nbr, int *len, t_dict *dict, int *is_space);

void	convert_number(char *nbr, t_dict *dict);

#endif
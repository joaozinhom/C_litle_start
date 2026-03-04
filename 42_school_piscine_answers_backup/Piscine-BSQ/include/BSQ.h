/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSQ.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:54:48 by joamoren          #+#    #+#             */
/*   Updated: 2026/02/04 17:06:24 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_values
{
	int		size_n;
	int		cols;
	char	empty;
	char	obstacle;
	char	fill;
}	t_values;

typedef struct s_square
{
	int	size;
	int	max_i;
	int	max_j;
}	t_square;

int			convert_to_number(char *s);
int			**matrix_alloc(int size);
char		**new_square(char **str, t_values values);
int			ft_isprint(char a);
int			ft_isdigit(char a);
int			min3(int a, int b, int c);
int			verify_input(char *buf);
char		*read_file(char *path);
char		*read_stdin(void);
void		encode(char *buf, t_values *dict, char **dest);
void		print_matrix(char **matrix_array, int rows, int cols);
char		**check_buffer(char **buf, t_values *dict);
t_square	square_info(char **str, t_values values);
t_square	square_inicialize(t_square sqr);
int			min3(int a, int b, int c);
int			convert_to_number(char *str);
void		ft_putstr(char *str);
void		matrix_free(int **cp, int size);
void		*ft_memcpy(void *dest, const void *src, int n);
#endif
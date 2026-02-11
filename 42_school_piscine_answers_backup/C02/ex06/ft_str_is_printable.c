/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:57:21 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/17 13:11:52 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;
	int	p;
	int	final;

	final = 1;
	i = 0;
	while (str[i] != '\0')
	{
		p = (int)str[i];
		if (!((str[i] >= 32 && str[i] <= 126)))
		{
			final = 0;
		}
		i++;
	}
	return (final);
}
/*
int main()
{
	char *something_alphabetic = "\n";
	char *something_non_alphabetic = "abcghij[`aBCZ";
	char *something_non_really_empty = "";
	int algo1 = ft_str_is_printable(something_alphabetic);
	int algo2 = ft_str_is_printable(something_non_alphabetic);
	int algo3 = ft_str_is_printable(something_non_really_empty);
	printf("%d", algo1);
	printf("%d", algo2);
	printf("%d", algo3);
}
*/
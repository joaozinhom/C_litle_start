/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:30:21 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/15 18:38:37 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	p;
	int	final;

	final = 1;
	i = 0;
	while (str[i] != '\0')
	{
		p = (int)str[i];
		if ((p < 96 || p > 123))
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
	char *something_alphabetic = "abc";
	char *something_non_alphabetic = "abcghij[`aBCZ";
	char *something_non_really_empty = "";
	int algo1 = ft_str_is_lowercase(something_alphabetic);
	int algo2 = ft_str_is_lowercase(something_non_alphabetic);
	int algo3 = ft_str_is_lowercase(something_non_really_empty);
	printf("%d", algo1);
	printf("%d", algo2);
	printf("%d", algo3);
}
*/
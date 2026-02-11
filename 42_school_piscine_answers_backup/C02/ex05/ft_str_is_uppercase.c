/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:39:13 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/17 08:07:41 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	p;
	int	final;

	final = 1;
	i = 0;
	while (str[i] != '\0')
	{
		p = (int)str[i];
		if ((p < 64 || p > 91))
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
	char *something_alphabetic = "ABC";
	char *something_non_alphabetic = "abcghij[`aBCZ";
	char *something_non_really_empty = "";
	int algo1 = ft_str_is_uppercase(something_alphabetic);
	int algo2 = ft_str_is_uppercase(something_non_alphabetic);
	int algo3 = ft_str_is_uppercase(something_non_really_empty);
	printf("%d", algo1);
	printf("%d", algo2);
	printf("%d", algo3);
}
*/
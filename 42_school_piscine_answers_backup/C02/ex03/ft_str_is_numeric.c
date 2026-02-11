/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:46:21 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/15 18:29:16 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	p;
	int	final;

	final = 1;
	i = 0;
	while (str[i] != '\0')
	{
		p = (int)str[i];
		if ((p < 47 || p > 58))
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
	char *something_alphabetic = "234389";
	char *something_non_alphabetic = "abcghij[`aBCZ";
	int algo1 = ft_str_is_numeric(something_alphabetic);
	int algo2 = ft_str_is_numeric(something_non_alphabetic);
	printf("%d", algo1);
	printf("%d", algo2);
}
*/
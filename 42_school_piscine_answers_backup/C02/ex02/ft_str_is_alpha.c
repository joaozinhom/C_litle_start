/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:46:21 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/15 18:24:23 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	p;
	int	final;

	final = 1;
	i = 0;
	while (str[i] != '\0')
	{
		p = (int)str[i];
		if ((p < 65 || p > 90) && (p < 97 || p > 122))
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
	char *something_alphabetic = "a";
	char *something_non_alphabetic = "abcghij[`aBCZ";
	int algo1 = ft_str_is_alpha(something_alphabetic);
	int algo2 = ft_str_is_alpha(something_non_alphabetic);
	printf("%d", algo1);
	printf("%d", algo2);
}
*/
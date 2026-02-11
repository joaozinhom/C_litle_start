/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:14:06 by joamoren          #+#    #+#             */
/*   Updated: 2026/01/15 09:53:24 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
int main(){
	int a = 5;
	int b = 2;
	int a_divided_b = 0;
	int rest_division_a_per_b = 0;
	ft_div_mod(a, b,&a_divided_b,&rest_division_a_per_b);
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", a_divided_b);
	printf("%d\n", rest_division_a_per_b);

}
*/
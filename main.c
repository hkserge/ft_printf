/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:27:26 by khelegbe          #+#    #+#             */
/*   Updated: 2021/02/11 15:58:16 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	myprf = 0;
	int	prf = 0;

	myprf = ft_printf("_%10.4d %d %d_\n", -23, 42, 87);
	prf = printf("_%10.4d %d %d_\n", -23, 42, 87);

	printf("Myprf = %d\n", myprf);
	printf("prf = %d\n", prf);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:27:26 by khelegbe          #+#    #+#             */
/*   Updated: 2021/02/20 01:15:11 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	myprf = 0;
	int	prf = 0;
	// char *s = "_%30.10s_\n";

	// myprf = ft_printf(s, "Bonjour");
	// prf = printf(s, "Bonjour");

	char *s = "%-5.5c, %-0-0-10.5d, %15.30s, %x, %p, %X_\n";

	myprf = ft_printf(s, 'H', 42, "Bonjour", 320, s, 320);
	prf = printf(s, 'H', 42, "Bonjour", 320, s, 320);
	printf(myprf == prf ? "ok\n" : "myprf = %d\nprf = %d\n", myprf, prf);

	return (0);
}

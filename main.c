/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:27:26 by khelegbe          #+#    #+#             */
/*   Updated: 2021/03/18 15:04:32 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	myprf = 0;
	int	prf = 0;
	char *s = "Bonjour";

	int		i = 8;
	int		j = 153;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	c = 'a';
	char	*n = "abcdefghijklmnop";

	myprf = ft_printf("6pointeur 1 %012p pointeur 2 %012p\n\n", &c, &c);
	prf = printf("6pointeur 1 %012p pointeur 2 %012p\n\n", &c, &c);

	myprf += ft_printf("%i, %-10.5d, %d, %d, %d, %s, %c, %d, %u, %x, %X, %010.3s\n", i, j, k, l, m, n, c, c, j, j, j, s);
	prf += printf("%i, %-10.5d, %d, %d, %d, %s, %c, %d, %u, %x, %X, %010.3s\n", i, j, k, l, m, n, c, c, j, j, j, s);
	printf(myprf == prf ? "ok\n" : "myprf = %d\nprf = %d\n", myprf, prf);
	// system("leaks a.out");
	return (0);
}

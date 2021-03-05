/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:27:26 by khelegbe          #+#    #+#             */
/*   Updated: 2021/03/05 16:04:40 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	myprf = 0;
	int	prf = 0;
	char *s = "_%5.0x_\n";

	myprf = ft_printf(s, 0, "Bonjour", 320, s, 320);
	prf = printf(s, 0, "Bonjour", 320, s, 320);
	printf(myprf == prf ? "ok\n" : "myprf = %d\nprf = %d\n", myprf, prf);

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 01:15:09 by khelegbe          #+#    #+#             */
/*   Updated: 2021/02/08 01:18:46 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_error(char *str, int i, t_prec *prec)
{
	int	j;
	int size;

	j = i;
	size = 0;
	while (str[j] != '%')
		j--;
	while (j <= i)
	{
		ft_putchar(str[j]);
		j++;
		size++;
	}
	if (prec)
	{
		free(prec);
		prec = 0;
	}
	return (size);
}

t_prec		*ft_init_prec(void)
{
	t_prec *prec;

	prec = malloc(sizeof(t_prec));
	if (!prec)
		return (0);
	prec->minus = 0;
	prec->precision = -1;
	prec->width = 0;
	prec->zero = 0;
	return (prec);
}

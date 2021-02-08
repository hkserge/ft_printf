/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:43:27 by khelegbe          #+#    #+#             */
/*   Updated: 2021/02/08 16:27:05 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_treat_prec(va_list arg, t_prec *prec)
{
	int		out;

	out = prec->width;
	if (prec->minus)
	{
		ft_putchar(va_arg(arg, int));
		while (prec->width-- - 1)
			ft_putchar(' ');
	}
	else
	{
		while (prec->width-- - 1)
			ft_putchar(' ');
		ft_putchar(va_arg(arg, int));
	}
	return (out);
}

int			ft_exec_c(va_list arg, int is_percent, t_prec *prec)
{
	int		out;

	out = 1;
	if (is_percent)
	{
		ft_putchar('%');
		if (prec)
		{
			free(prec);
			prec = 0;
		}
		return (out);
	}
	else
	{
		if (prec)
		{
			out = ft_treat_prec(arg, prec);
			free(prec);
			prec = 0;
		}
		else
		{
			ft_putchar(va_arg(arg, int));
		}
	}
	return (out);
}

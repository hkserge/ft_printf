/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:43:27 by khelegbe          #+#    #+#             */
/*   Updated: 2021/03/09 13:18:03 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_percent(t_prec *prec)
{
	int total;

	total = 0;
	if (prec->minus)
	{
		total += ft_print_strnb(1, "%");
		if (!prec->zero)
			total += ft_print_charnb(prec->width - 1, ' ');
		else
			total += ft_print_charnb(prec->width - 1, '0');
	}
	else
	{
		if (!prec->zero)
			total += ft_print_charnb(prec->width - 1, ' ');
		else
			total += ft_print_charnb(prec->width - 1, '0');
		total += ft_print_strnb(1, "%");
	}
	return (total);
}

static int	ft_treat_prec(va_list arg, t_prec *prec)
{
	int		out;
	int		i;

	out = prec->width;
	i = prec->width - 1;
	if (prec->minus)
	{
		ft_putchar(va_arg(arg, int));
		while (i-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while (i-- > 0)
			ft_putchar(' ');
		ft_putchar(va_arg(arg, int));
	}
	return (out);
}

int			ft_exec_c(va_list arg, int is_percent, t_prec **prec)
{
	int		out;

	out = 1;
	if (is_percent)
	{
		if (*prec)
		{
			out = ft_is_percent(*prec);
			free(*prec);
		}
		else
			ft_putchar('%');
		return (out);
	}
	else
	{
		if (*prec)
		{
			out = ft_treat_prec(arg, *prec);
			free(*prec);
		}
		else
			ft_putchar(va_arg(arg, int));
	}
	return (out);
}

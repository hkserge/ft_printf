/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 23:48:52 by khelegbe          #+#    #+#             */
/*   Updated: 2021/02/20 03:29:10 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_out_is_null(t_prec *prec, char *out, int len)
{
	int		nb_space;

	nb_space = prec->width;
	if (prec->precision >= len)
		if (prec->width > len)
			nb_space = prec->width - len;
	if (prec->minus)
	{
		if (prec->precision >= len)
			ft_putstr(out);
		ft_print_charnb(nb_space, ' ');
	}
	else
	{
		ft_print_charnb(nb_space, ' ');
		if (prec->precision >= len)
			ft_putstr(out);
	}
	if (prec->precision < len)
		return (nb_space);
	return (nb_space + len);
}

static int	ft_space_nb(t_prec *prec, int len)
{
	int		nb_space;

	nb_space = 0;
	if (prec->width > len)
		nb_space = prec->width - len;
	if (prec->precision < len && prec->precision != -1)
		nb_space += len - prec->precision;
	return (nb_space);
}

static int	ft_treat_prec(t_prec *prec, char *out, int is_null)
{
	int		nb_space;
	int		len;
	int		total;
	int		to_print;

	total = 0;
	len = (int)ft_strlen(out);
	if (prec->precision < len && prec->precision != -1)
		to_print = prec->precision;
	to_print = len;
	if (is_null)
		return (ft_out_is_null(prec, out, len));
	nb_space = ft_space_nb(prec, len);
	if (prec->minus)
	{
		total += ft_print_strnb(to_print, out);
		total += ft_print_charnb(nb_space, ' ');
	}
	else
	{
		total += ft_print_charnb(nb_space, ' ');
		total += ft_print_strnb(to_print, out);
	}
	return (total);
}

int			ft_exec_s(va_list arg, t_prec **prec)
{
	char	*out;
	int		len;
	int		is_null;

	out = va_arg(arg, char*);
	is_null = 0;
	if (!out)
	{
		is_null = 1;
		out = "(null)";
	}
	if (*prec)
	{
		len = ft_treat_prec(*prec, out, is_null);
		free(*prec);
		*prec = 0;
	}
	else
	{
		ft_putstr(out);
		len = (int)ft_strlen(out);
	}
	return (len);
}

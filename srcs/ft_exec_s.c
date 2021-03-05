/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 23:48:52 by khelegbe          #+#    #+#             */
/*   Updated: 2021/03/05 16:15:50 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_minus(t_prec *prec, int nb_space, int to_print, char *out)
{
	int total;

	total = 0;
	if (prec->minus)
	{
		total += ft_print_strnb(to_print, out);
		if (!prec->zero)
			total += ft_print_charnb(nb_space, ' ');
		else
			total += ft_print_charnb(nb_space, '0');
	}
	else
	{
		if (!prec->zero)
			total += ft_print_charnb(nb_space, ' ');
		else
			total += ft_print_charnb(nb_space, '0');
		total += ft_print_strnb(to_print, out);
	}
	return (total);
}

static int	ft_space_nb(t_prec *prec, int len)
{
	int		nb_space;
	int		prec_space_nb;

	nb_space = 0;
	prec_space_nb = 0;
	if (prec->width > prec->precision && len
	< prec->precision && prec->precision != -1)
		prec_space_nb = prec->precision - len;
	nb_space = prec->width - len + prec_space_nb;
	if (prec->width > prec->precision && prec->precision != -1)
		nb_space = prec->width - prec->precision + prec_space_nb;
	return (nb_space);
}

static int	ft_treat_prec(t_prec *prec, char *out)
{
	int		nb_space;
	int		len;
	int		to_print;

	len = (int)ft_strlen(out);
	to_print = len;
	if (prec->precision < len && prec->precision != -1)
		to_print = prec->precision;
	nb_space = ft_space_nb(prec, len);
	return (ft_is_minus(prec, nb_space, to_print, out));
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
		len = ft_treat_prec(*prec, out);
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

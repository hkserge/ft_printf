/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_d_i_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 22:43:34 by khelegbe          #+#    #+#             */
/*   Updated: 2021/03/16 16:20:44 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_is_minus(t_prec *prec, int space_nb, int nb_zeros, char *str)
{
	int		is_null;
	int		printed;

	printed = 0;
	is_null = ft_strncmp(str, "0", 2);
	if (str[0] == '-')
		printed += ft_print_charnb(1, '-');
	if (prec->precision)
		printed += ft_print_charnb(nb_zeros, '0');
	if (prec->precision != 0 || (prec->precision == 0 && is_null))
	{
		ft_putstr(str + (str[0] == '-'));
		printed += ft_strlen(str + (str[0] == '-'));
	}
	printed += ft_print_charnb(space_nb +
	(prec->precision == 0 && !is_null), ' ');
	return (printed);
}

static int		ft_no_minus(t_prec *prec, int space_nb, int nb_zeros, char *str)
{
	int		printed;

	printed = 0;
	if (prec->zero && prec->precision == -1)
	{
		if (str[0] == '-')
			printed += ft_print_charnb(1, '-');
		printed += ft_print_charnb(space_nb, '0');
	}
	else
	{
		printed += ft_print_charnb(space_nb +
		(prec->precision == 0 && !ft_strncmp(str, "0", 2)), ' ');
		if (str[0] == '-')
			printed += ft_print_charnb(1, '-');
	}
	if (prec->precision)
		printed += ft_print_charnb(nb_zeros, '0');
	if (prec->precision != 0 || (prec->precision == 0 &&
	ft_strncmp(str, "0", 2)))
	{
		ft_putstr(str + (str[0] == '-'));
		printed += ft_strlen(str + (str[0] == '-'));
	}
	return (printed);
}

static int		ft_get_prec_prec(char *str, t_prec *prec)
{
	int		space_nb;
	int		nb_zeros;
	int		len;
	int		total;

	total = 0;
	len = (int)ft_strlen(str);
	nb_zeros = 0;
	space_nb = 0;
	if (str[0] == '0')
		len = 0;
	if ((int)ft_strlen(str + (str[0] == '-')) < prec->precision)
		nb_zeros = prec->precision - (int)ft_strlen(str) + (str[0] == '-');
	if (prec->width >= len + nb_zeros)
		space_nb = prec->width - len - nb_zeros - (str[0] == '0');
	if (prec->minus)
		total = ft_is_minus(prec, space_nb, nb_zeros, str);
	else
		total = ft_no_minus(prec, space_nb, nb_zeros, str);
	return (total);
}

int				ft_exec_d_i_u(va_list arg, int is_unsigned, t_prec **prec)
{
	char	*out;
	int		len;

	len = 0;
	if (is_unsigned)
		out = ft_utoa(va_arg(arg, unsigned int));
	else
		out = ft_itoa(va_arg(arg, int));
	if (*prec)
	{
		len = ft_get_prec_prec(out, *prec);
		free(*prec);
		*prec = NULL;
	}
	else
	{
		ft_putstr(out);
		len = (int)ft_strlen(out);
	}
	if (out)
		free(out);
	return (len);
}

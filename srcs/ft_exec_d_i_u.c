/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_d_i_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 22:43:34 by khelegbe          #+#    #+#             */
/*   Updated: 2021/02/18 18:29:50 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_get_prec_prec(char *str, t_prec *prec)
{
	int		space_nb;
	int		nb_zeros;
	int		len;

	len = (int)ft_strlen(str);
	nb_zeros = 0;
	space_nb = 0;
	if (prec->precision > -1 && (int)ft_strlen(str) <= prec->precision)
		nb_zeros = prec->precision - (int)ft_strlen(str) + (str[0] == '-');
	if (prec->width >= len + nb_zeros)
		space_nb = prec->width - len - nb_zeros;
	if (prec->minus)
	{
		if (str[0] == '-')
			ft_print_charnb(1, '-');
		if (prec->precision)
			ft_print_charnb(nb_zeros, '0');
		ft_putstr(str + (str[0] == '-'));
		ft_print_charnb(space_nb, ' ');
	}
	else
	{
		ft_print_charnb(space_nb, ' ');
		if (str[0] == '-')
			ft_print_charnb(1, '-');
		if (prec->precision)
			ft_print_charnb(nb_zeros, '0');
		ft_putstr(str + (str[0] == '-'));
	}
	return (space_nb + nb_zeros + (int)ft_strlen(str));
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

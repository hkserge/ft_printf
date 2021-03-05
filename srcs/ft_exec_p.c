/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 23:15:34 by khelegbe          #+#    #+#             */
/*   Updated: 2021/03/03 20:35:34 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_is_minus(t_prec *prec, int space_nb, int nb_zeros, char *str)
{
	if (str[0] == '-')
		ft_print_charnb(1, '-');
	if (prec->precision)
		ft_print_charnb(nb_zeros, '0');
	if (prec->precision != 0)
		ft_putstr(str + (str[0] == '-'));
	ft_print_charnb(space_nb + (prec->precision == 0), ' ');
}

static void		ft_no_minus(t_prec *prec, int space_nb, int nb_zeros, char *str)
{
	if (prec->zero && prec->precision == -1)
	{
		ft_putstr("0x");
		ft_print_charnb(space_nb, '0');
	}
	else
	{
		ft_print_charnb(space_nb, ' ');
		ft_putstr("0x");
	}
	if (prec->precision)
		ft_print_charnb(nb_zeros, '0');
	if (prec->precision != 0)
		ft_putstr(str + (str[0] == '-'));
}

static int		ft_get_prec_prec(char *str, t_prec *prec)
{
	int		space_nb;
	int		nb_zeros;
	int		len;

	len = (int)ft_strlen(str);
	nb_zeros = 0;
	space_nb = 0;
	if (prec->precision > -1 && (int)ft_strlen(str) < prec->precision)
		nb_zeros = prec->precision - (int)ft_strlen(str);
	if (prec->width >= len + nb_zeros)
		space_nb = prec->width - len - nb_zeros - (str[0] == '0') - 2;
	if (prec->minus)
	{
		ft_is_minus(prec, space_nb, nb_zeros, str);
	}
	else
	{
		ft_no_minus(prec, space_nb, nb_zeros, str);
	}
	return (space_nb + nb_zeros + (int)ft_strlen(str));
}

int		ft_exec_p(va_list arg, t_prec **prec)
{
	long int			out;
	char				*address;
	int					len;

	out = ((long int)va_arg(arg, long int));
	address = ft_convert_hex(out, "0123456789abcdef");
	len = (int)ft_strlen(address) + 2;
	if (*prec)
	{
		len = ft_get_prec_prec(address, *prec);
		free(*prec);
		*prec = 0;
		if (address)
			free(address);
	}
	else
	{
		ft_putstr("0x");
		ft_putstr(address);
		if (address)
			free(address);
	}
	return (len + 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 23:15:34 by khelegbe          #+#    #+#             */
/*   Updated: 2021/03/12 11:30:04 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_is_minus(t_prec *prec, int space_nb, int nb_zeros, char *str)
{
	ft_putstr("0x");
	ft_print_charnb(nb_zeros, '0');
	if (prec->precision != 0 && str != NULL)
		ft_putstr(str);
	ft_print_charnb(space_nb, ' ');
}

static void		ft_no_minus(t_prec *prec, int space_nb, int nb_zeros, char *str)
{
	if (prec->zero && prec->precision == -1)
	{
		ft_putstr("0x");
		ft_print_charnb(nb_zeros, '0');
	}
	else
	{
		ft_print_charnb(space_nb, ' ');
		ft_putstr("0x");
		ft_print_charnb(nb_zeros, '0');
	}
	if (prec->precision != 0 && str != NULL)
		ft_putstr(str);
}

static int		ft_get_prec_prec(char *str, t_prec *prec)
{
	int		space_nb;
	int		nb_zeros;
	int		len;
	int		out_is_null;

	out_is_null = ft_strncmp(str, "0", 2);
	len = (int)ft_strlen(str) + 2 - (out_is_null == 0 && prec->precision == 0);
	nb_zeros = 0;
	space_nb = 0;
	if (prec->precision > -1 && len < prec->precision)
		nb_zeros = prec->precision - (int)ft_strlen(str);
	if (prec->precision == -1 && prec->zero)
		nb_zeros = prec->width - len;
	if (prec->width > len + nb_zeros)
		space_nb = prec->width - (len + nb_zeros);
	if (prec->minus)
		ft_is_minus(prec, space_nb, nb_zeros, str);
	else
		ft_no_minus(prec, space_nb, nb_zeros, str);
	if (nb_zeros < 0)
		nb_zeros = 0;
	return (space_nb + nb_zeros + len);
}

int				ft_exec_p(va_list arg, t_prec **prec)
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
	return (len);
}

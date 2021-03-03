/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 23:15:34 by khelegbe          #+#    #+#             */
/*   Updated: 2021/03/03 17:32:37 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_minus(t_prec *prec, int nb_space, int to_print, char *address)
{
	int total;

	total = 0;
	if (prec->minus)
	{
		ft_putstr("0x");
		total += ft_print_strnb(to_print, address);
		if (!prec->zero)
			total += ft_print_charnb(nb_space - 2, ' ');
		else
			total += ft_print_charnb(nb_space - 2, '0');
	}
	else
	{
		if (!prec->zero)
		{
			total += ft_print_charnb(nb_space - 2, ' ');
			ft_putstr("0x");
		}
		else
		{
			ft_putstr("0x");
			total += ft_print_charnb(nb_space - 2, '0');
		}
		total += ft_print_strnb(to_print, address);
	}
	return (total);
}

static int	ft_space_nb(t_prec *prec, int len)
{
	int		nb_space;
	int		prec_space_nb;

	nb_space = 0;
	prec_space_nb = 0;
	if (prec->width > prec->precision && len < prec->precision && prec->precision != -1)
		prec_space_nb = prec->precision - len;
	nb_space = prec->width - len + prec_space_nb;
	if (prec->width > prec->precision && prec->precision != -1)
		nb_space = prec->width - prec->precision + prec_space_nb;
	return (nb_space);
}

static int	ft_treat_prec(t_prec *prec, char *address)
{
	int		nb_space;
	int		len;
	int		to_print;

	len = (int)ft_strlen(address);
	to_print = len;
	if (prec->precision < len && prec->precision != -1)
		to_print = prec->precision;
	nb_space = ft_space_nb(prec, len);
	return (ft_is_minus(prec, nb_space, to_print, address));
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
		len = ft_treat_prec(*prec, address);
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

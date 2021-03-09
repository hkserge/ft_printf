/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 05:13:07 by khelegbe          #+#    #+#             */
/*   Updated: 2021/03/09 04:44:15 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_is_minus(t_prec *prec, int space_nb, int nb_zeros, char *str)
{
	int		out_is_null;

	out_is_null = ft_strncmp(str, "0", 2);
	ft_print_charnb(nb_zeros, '0');
	if (!(prec->precision == 0 && out_is_null == 0))
		ft_putstr(str);
	ft_print_charnb(space_nb, ' ');
}

static void		ft_no_minus(t_prec *prec, int space_nb, int nb_zeros, char *str)
{
	int		out_is_null;

	out_is_null = ft_strncmp(str, "0", 2);
	if (prec->zero && prec->precision == -1)
	{
		ft_print_charnb(nb_zeros, '0');
	}
	else
	{
		ft_print_charnb(space_nb, ' ');
		ft_print_charnb(nb_zeros, '0');
	}
	if (prec->precision == 0 && out_is_null == 0)
		return ;
	else
		ft_putstr(str);
}

static int		ft_get_prec_prec(char *str, t_prec *prec)
{
	int		space_nb;
	int		nb_zeros;
	int		len;
	int		out_is_null;

	out_is_null = ft_strncmp(str, "0", 2);
	len = (int)ft_strlen(str);
	if (prec->precision == 0 && out_is_null == 0)
		len = 0;
	nb_zeros = 0;
	space_nb = 0;
	if (prec->precision > -1 && len < prec->precision)
		nb_zeros = prec->precision - (int)ft_strlen(str);
	if (prec->precision == -1 && prec->zero && prec->width >= len)
		nb_zeros = prec->width - len;
	if (prec->width > len + nb_zeros)
		space_nb = prec->width - (len + nb_zeros);
	if (prec->minus)
	{
		ft_is_minus(prec, space_nb, nb_zeros, str);
	}
	else
	{
		ft_no_minus(prec, space_nb, nb_zeros, str);
	}
	return (space_nb + nb_zeros + len);
}

int				ft_exec_x(va_list arg, int is_caps, t_prec **prec)
{
	char			*out;
	// char			*temp;
	int				len;
	int		out_is_null;
	long			var;

	// temp = ft_utoa(va_arg(arg, unsigned int));
	var = (unsigned int)va_arg(arg, unsigned int);
	if (is_caps)
		out = ft_convert_hex(var, "0123456789ABCDEF");
	else
		out = ft_convert_hex(var, "0123456789abcdef");
	out_is_null = ft_strncmp(out, "0", 2);
	if (*prec)
	{
		len = ft_get_prec_prec(out, *prec);
		free(*prec);
	}
	else
	{
		ft_putstr(out);
		len = (int)ft_strlen(out);
	}
	// if (temp)
	// 	free(temp);
	free(out);
	return (len);
}

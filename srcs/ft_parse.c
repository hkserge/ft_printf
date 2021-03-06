/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 20:51:53 by khelegbe          #+#    #+#             */
/*   Updated: 2021/03/09 13:16:03 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_get_star_arg(va_list arg, char *str)
{
	while (*str == '-' || *str == '0')
		str++;
	if (str[0] == '*')
		return (va_arg(arg, int));
	return (ft_atoi(str));
}

static void		ft_gprec2(t_prec *prec, va_list arg, char *str, int j)
{
	prec->width = ft_get_star_arg(arg, str + j);
	if (prec->width < 0)
	{
		prec->minus = 1;
		prec->width *= -1;
	}
}

static t_prec	*ft_get_precision(t_prec *prec, va_list arg, char *str, int *i)
{
	int		j;

	j = 0;
	ft_init_prec(&prec);
	while (str[j] == '-' || str[j] == '0')
	{
		if (str[j] == '-')
			prec->minus = 1;
		if (str[j] == '0' && prec->minus == 0)
			prec->zero = 1;
		j++;
	}
	ft_gprec2(prec, arg, str, j);
	while (ft_isdigit(str[j]) || str[j] == '*' || str[j] == '-')
		j++;
	if (str[j] == '.')
		prec->precision = ft_get_star_arg(arg, str + ++j);
	if (prec->precision < -1)
		prec->precision = -1;
	while (ft_isdigit(str[j]) || str[j] == '*')
		j++;
	*i += j;
	return (prec);
}

static int		ft_treat_args(char *str, va_list arg, t_prec **prec, int *j)
{
	int		i;
	int		len;
	char	c;

	i = *j;
	len = 0;
	c = str[i];
	if (str[i] == 'c' || str[i] == '%')
		len += ft_exec_c(arg, str[i] == '%', prec);
	else if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u')
		len += ft_exec_d_i_u(arg, str[i] == 'u', prec);
	else if (str[i] == 's')
		len += ft_exec_s(arg, prec);
	else if (str[i] == 'p')
		len += ft_exec_p(arg, prec);
	else if (str[i] == 'x' || str[i] == 'X')
		len += ft_exec_x(arg, str[i] == 'X', prec);
	else
		len += ft_print_error(str, i, prec);
	return (len);
}

int				ft_parse(char *str, va_list arg, t_prec *prec)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str[i] && i < (int)ft_strlen(str))
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_strchr("cspdiuxX%-+0123456789.*", str[i]) && str[i])
			{
				if (ft_strchr("-+0123456789.*", str[i]))
					prec = ft_get_precision(prec, arg, str + i, &i);
				len += ft_treat_args(str, arg, &prec, &i);
				i++;
			}
		}
		else
			len += ft_print_char(str[i], &i);
	}
	return (len);
}

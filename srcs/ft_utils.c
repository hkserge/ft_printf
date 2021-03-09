/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 01:15:09 by khelegbe          #+#    #+#             */
/*   Updated: 2021/03/09 13:17:17 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_char(char c, int *i)
{
	*i += 1;
	ft_putchar(c);
	return (1);
}

int			ft_print_strnb(int nb, char *s)
{
	int		i;

	i = 0;
	while (s[i] && i < nb)
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int			ft_print_charnb(int nb, char c)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

int			ft_print_error(char *str, int i, t_prec **prec)
{
	int		j;
	int		size;

	j = i;
	size = 0;
	while (str[j] != '%')
		j--;
	while (j <= i)
	{
		if (str[j] == '.' && ft_atoi(str + j + 1) < 0)
		{
			ft_putchar('.');
			ft_putchar('0');
			j += 1;
			size += 2;
		}
		ft_putchar(str[j]);
		j++;
		size++;
	}
	if (*prec)
		free(*prec);
	return (size);
}

void		ft_init_prec(t_prec **prec)
{
	*prec = malloc(sizeof(t_prec));
	if (!*prec)
		return ;
	(*prec)->minus = 0;
	(*prec)->precision = -1;
	(*prec)->width = 0;
	(*prec)->zero = 0;
}

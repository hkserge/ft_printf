/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:06:22 by khelegbe          #+#    #+#             */
/*   Updated: 2021/02/11 14:38:14 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct	s_precision
{
	int		minus;
	int		zero;
	int		width;
	int		precision;
}				t_prec;

int				ft_printf(const char *str, ...);
int				ft_parse(char *str, va_list arg, t_prec *prec);
int				ft_exec_c(va_list arg, int is_percent, t_prec **prec);
int				ft_exec_d_i_u(va_list arg, int is_unsigned, t_prec **prec);
int				ft_exec_s(va_list arg);
int				ft_exec_p(va_list arg);
int				ft_exec_x(va_list arg, int is_caps);

char			*ft_convert_hex(long int var, char *base_to);
int				ft_print_error(char *str, int i, t_prec **prec);
void			ft_init_prec(t_prec **prec);
int				ft_print_charnb(int nb, char c);

#endif

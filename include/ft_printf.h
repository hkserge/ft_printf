/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:06:22 by khelegbe          #+#    #+#             */
/*   Updated: 2021/02/02 23:49:32 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		ft_parse(char *str, va_list arg);
int		ft_exec_arg(char *str, va_list arg, int *i);
int		ft_exec_c(va_list arg);
int		ft_exec_d_i_u(va_list arg, int is_unsigned);
int		ft_exec_s(va_list arg);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:22:40 by khelegbe          #+#    #+#             */
/*   Updated: 2021/02/05 17:28:38 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_digits(long int nb)
{
	int		len;

	len = 0;
	if (nb <= 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(long int n)
{
	char		*str;
	long int	nbr;
	int			len;

	nbr = n;
	str = 0;
	len = ft_count_digits(nbr);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	while (nbr)
	{
		str[--len] = '0' + nbr % 10;
		nbr = nbr / 10;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:24:15 by yufonten          #+#    #+#             */
/*   Updated: 2023/11/02 12:18:35 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_nbr(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static char	*ft_itoa(int n)
{
	char	*r;
	int		i;

	i = 0;
	i = ft_count_nbr(n);
	r = malloc(sizeof(char) * (i + 1));
	if (!r)
		return (NULL);
	r[i] = '\0';
	i--;
	while (i >= 0)
	{
		if (i == 0 && n < 0)
			r[i] = '-';
		else
		{
			r[i] = ft_abs(n % 10) + 48;
			n = n / 10;
		}
		i--;
	}
	return (r);
}

int	ft_printnbr(int nb)
{
	int		len_print;
	char	*nbr;

	len_print = 0;
	nbr = ft_itoa(nb);
	len_print = ft_printstr(nbr);
	free(nbr);
	return (len_print);
}

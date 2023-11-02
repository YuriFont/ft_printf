/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:25:03 by yufonten          #+#    #+#             */
/*   Updated: 2023/11/02 12:44:03 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_unsitoa(unsigned int n)
{
	int		i;
	char	*r;

	i = 0;
	i = ft_count(n);
	r = malloc(sizeof(char) * (i + 1));
	if (!r)
		return (NULL);
	r[i] = '\0';
	while (n != 0)
	{
		r[i - 1] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (r);
}

int	ft_print_unsint(unsigned int n)
{
	int		len_print;
	char	*aux;

	len_print = 0;
	if (n == 0)
		len_print += ft_printchar(n);
	else
	{
		aux = ft_unsitoa(n);
		len_print += ft_printstr(aux);
		free(aux);
	}
	return (len_print);
}

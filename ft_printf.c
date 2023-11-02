/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:30:48 by yufonten          #+#    #+#             */
/*   Updated: 2023/11/02 12:14:21 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char type)
{
	int	len_format;

	len_format = 0;
	if (type == 'c')
		len_format = ft_printchar(va_arg(args, int));
	else if (type == 's')
		len_format = ft_printstr(va_arg(args, char *));
	else if (type == 'p')
		len_format = ft_printptr(va_arg(args, unsigned long long));
	else if (type == 'd' || type == 'i')
		len_format = ft_printnbr(va_arg(args, int));
	return (len_format);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len_printf;
	va_list	args;

	i = 0;
	len_printf = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			len_printf += ft_formats(args, s[i + 1]);
			i++;
		}
		else
			len_printf += ft_printchar(s[i]);
		i++;
	}
	va_end(args);
	return (len_printf);
}
int	main(void)
{
	char	n = 'y';
	ft_printf("%c\n", n);
}

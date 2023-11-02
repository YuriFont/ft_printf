/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:30:48 by yufonten          #+#    #+#             */
/*   Updated: 2023/11/02 16:18:04 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats(va_list args, const char type)
{
	int	len_print;

	len_print = 0;
	if (type == 'c')
		len_print += ft_printchar(va_arg(args, int));
	else if (type == 's')
		len_print += ft_printstr(va_arg(args, char *));
	else if (type == 'p')
		len_print += ft_printptr(va_arg(args, unsigned long long));
	else if (type == 'd' || type == 'i')
		len_print += ft_printnbr(va_arg(args, int));
	else if (type == 'u')
		len_print += ft_print_unsint(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		len_print += ft_printhex(va_arg(args, unsigned int), type);
	else if (type == '%')
		len_print += ft_printchar('%');
	else
	{
		len_print += ft_printchar('%');
		len_print += ft_printchar(type);
	}
	return (len_print);
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
	char	test1 = 'y';
	char	test2[4] = "yuri";
	void	*test3 = &test2;
	int	test4 = 18;
	int	test5 = 3;
	unsigned int	test6 = 4294967295;
	unsigned int	test78 = 45;
	int	test;
	test = ft_printf("%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%\n%rhkdjsdad", test1, test2, test3, test4, test5, test6, test78, test78);
	ft_printf("%d\n", test);
}

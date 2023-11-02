/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:55:15 by yufonten          #+#    #+#             */
/*   Updated: 2023/11/02 12:38:51 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printchar(char c);
int	ft_printstr(const char *s);
int	ft_printnbr(int nb);
int	ft_printptr(unsigned long long ptr);
int	ft_print_unsint(unsigned int n);

#endif

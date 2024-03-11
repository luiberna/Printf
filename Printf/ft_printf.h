/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:50:48 by luiberna          #+#    #+#             */
/*   Updated: 2023/10/18 14:20:53 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h> //macros
# include <stdarg.h> //variadic
# include <stdio.h>  //printf
# include <stdlib.h> //malloc
# include <unistd.h> //write

int	ft_printf(const char *s, ...);
int	ft_putchar(char c);
int	ft_puthexnbr(unsigned long int n, int c);
int	ft_putnbr(long long int n);
int	ft_putptr(unsigned long int n);
int	ft_putstr(char *s);
int	ft_putunsigned(unsigned int n);

#endif
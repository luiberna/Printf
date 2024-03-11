/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:22:10 by luiberna          #+#    #+#             */
/*   Updated: 2023/10/18 14:08:22 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexnbr(unsigned long int n, int c)
{
	char	*str;

	if (c == 'l')
		str = "0123456789abcdef";
	else if (c == 'u')
		str = "0123456789ABCDEF";
	if (n < 16)
		return (ft_putchar(str[n]));
	return (ft_puthexnbr(n / 16, c) + ft_putchar(str[n % 16]));
}
/*
int	main(void)
{
	printf("\n%d\n", ft_puthexnbr(362, 'u'));
}
*/
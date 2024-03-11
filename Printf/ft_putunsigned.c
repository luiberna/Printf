/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:50:00 by luiberna          #+#    #+#             */
/*   Updated: 2023/10/16 16:29:06 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	size_t	i;
	char	r;

	i = 0;
	if (n >= 10)
	{
		i = i + ft_putunsigned(n / 10);
	}
	r = n % 10 + '0';
	write(1, &r, 1);
	i++;
	return (i);
}
/*
int	main(void)
{
	printf("\n%d\n", ft_putunsigned(56));
	printf("%u", 56);
}
*/
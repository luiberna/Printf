/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:50:55 by luiberna          #+#    #+#             */
/*   Updated: 2023/10/16 14:50:55 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long int n)
{
	size_t	i;
	char	r;

	i = 0;
	if (n < 0)
	{
		i = i + write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		i = i + ft_putnbr(n / 10);
	}
	r = n % 10 + '0';
	write(1, &r, 1);
	i++;
	return (i);
}
/*
int	main(void)
{
	printf("\n%d\n", ft_putnbr(-124));
}
*/
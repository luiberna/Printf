/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:50:10 by luiberna          #+#    #+#             */
/*   Updated: 2023/10/18 14:20:01 by luiberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long int n)
{
	if (!n)
		return (ft_putstr("(nil)"));
	else
		return (ft_putstr("0x") + ft_puthexnbr(n, 'l'));
}

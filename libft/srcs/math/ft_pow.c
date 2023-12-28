/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:28:17 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/24 20:52:24 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <math.h>
** SYNOPSIS: power function
**
** DESCRIPTION:
** 		The pow() function computes the value of base raised to the power of
** exponent.
*/

#include "libft.h"

long double	ft_pow(long double n, unsigned int pow)
{
	if (pow != 0)
	{
		return (n * ft_pow(n, pow - 1));
	}
	else
	{
		return (1);
	}
}

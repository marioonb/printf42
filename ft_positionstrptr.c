/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_positionstrptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:13:17 by mbelorge          #+#    #+#             */
/*   Updated: 2020/01/29 16:32:48 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_positionstr(char *str, int taille, int pos)
{
	int	a;

	a = 0;
	if (pos == 1)
	{
		a += ft_putstr_return(str);
		while (taille-- > 0)
			a += ft_putchar_return(' ');
	}
	else
	{
		while (taille-- > 0)
		{
			if (pos == 0)
				a += ft_putchar_return(' ');
			if (pos == 2)
				a += ft_putchar_return('0');
		}
		a += ft_putstr_return(str);
	}
	return (a);
}

int		ft_position_onlyonechar(char c, int taille, int pos)
{
	int	a;

	a = 0;
	if (pos == 1)
	{
		a += ft_putchar_return(c);
		while (taille-- > 0)
			a += ft_putchar_return(' ');
	}
	else if (pos == 0 || pos == 2)
	{
		while (taille-- > 0)
		{
			if (pos == 0)
				a += ft_putchar_return(' ');
			if (pos == 2)
				a += ft_putchar_return('0');
		}
		a += ft_putchar_return(c);
	}
	return (a);
}

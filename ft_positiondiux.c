/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_positiondiux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:13:17 by mbelorge          #+#    #+#             */
/*   Updated: 2020/02/14 13:36:28 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_position0(char *str, int taille, int min, int max)
{
	int	a;

	a = 0;
	if (min == -1)
		min = 0;
	if (min > (int)ft_strlen(str))
		taille = max - min;
	if (str[0] == '-' && min >= (int)ft_strlen(str))
		taille = taille - 1;
	while (taille-- > 0)
		a += ft_putchar_return(' ');
	while ((min > (int)ft_strlen(str) && str[0] != '-' && (int)ft_strlen > 0)
			|| (min >= (int)ft_strlen(str) && str[0] == '-'))
	{
		if (str[0] == '-')
		{
			a += ft_putchar_return('-');
			str++;
		}
		a += ft_putchar_return('0');
		min--;
	}
	a += ft_putstr_return(str);
	return (a);
}

int		ft_position1(char *str, int taille, int min, int max)
{
	int	a;

	a = 0;
	if (min == -1)
		min = 0;
	if (min > (int)ft_strlen(str))
		taille = max - min;
	while (min > (int)ft_strlen(str) ||
		(min == (int)ft_strlen(str) && str[0] == '-'))
	{
		if (str[0] == '-')
		{
			a += ft_putchar_return('-');
			str++;
			taille--;
		}
		a += ft_putchar_return('0');
		min--;
	}
	a += ft_putstr_return(str);
	while (taille-- > 0)
		a += ft_putchar_return(' ');
	return (a);
}

int		ft_position2(char *str, int taille)
{
	int	a;

	a = 0;
	if (str[0] == '-')
	{
		a += ft_putchar_return('-');
		str++;
	}
	while (taille-- > 0)
		a += ft_putchar_return('0');
	a += ft_putstr_return(str);
	return (a);
}

int		ft_position4(char *str, int taille, int min, int max)
{
	int	a;

	min = 0;
	a = 0;
	if (str[0] == '-')
		taille = taille - 1;
	while (taille-- > 0 && taille > max)
		a += ft_putchar_return(' ');
	while (max-- > (int)ft_strlen(str))
	{
		if (str[0] == '-')
		{
			a += ft_putchar_return('-');
			str++;
			max--;
		}
		a += ft_putchar_return('0');
	}
	a += ft_putstr_return(str);
	return (a);
}

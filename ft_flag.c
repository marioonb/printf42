/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:13:17 by mbelorge          #+#    #+#             */
/*   Updated: 2020/02/14 13:39:09 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_flag_zero(char *str, va_list *arg, int pos)
{
	int			nombre;
	int			a;
	t_struct	z;
	int			min;

	nombre = 0;
	min = -1;
	a = 0;
	if (pos != 1)
		pos = 2;
	str++;
	while (str[0] == '0')
		str++;
	if (str[0] == '-')
	{
		pos = 1;
		str++;
	}
	z.min = min;
	z.pos = pos;
	z.nb = nombre;
	a += ft_flag_zero_suite(str, arg, z, 0);
	return (a);
}

int				ft_flag_zero_suite(char *str, va_list *arg, t_struct z, int a)
{
	int			nombre;

	if (str[0] == '*')
	{
		str++;
		nombre = va_arg(*arg, int);
		if (nombre < 0)
		{
			nombre = nombre * -1;
			z.pos = 1;
		}
		z.nb = nombre;
	}
	if (ft_isalpha(str[0]))
		a += ft_conversiontype(str, arg, z);
	else if (ft_isdigit(str[0]))
		a += ft_flag_numerique(str, arg, z.pos);
	if (str[0] == '.')
	{
		str++;
		a += ft_flag_point(str, arg, z.nb, z.pos);
	}
	return (a);
}

int				ft_flag_numerique(char *str, va_list *arg, int pos)
{
	int			nombre;
	char		*temp;
	int			a;
	t_struct	z;
	char		*nb;

	z.min = -1;
	a = 0;
	if (pos == 2)
		z.min = 0;
	temp = str;
	while (ft_isdigit(temp[a++]))
		str++;
	nb = malloc(sizeof(char) * (a + 1));
	ft_strncpy(nb, temp, a);
	nombre = ft_atoi(nb);
	z.nb = nombre;
	z.pos = pos;
	a = 0;
	if (str[0] == '.')
		a += ft_flag_point(str + 1, arg, nombre, pos);
	else
		a += ft_conversiontype(str, arg, z);
	free(nb);
	return (a);
}

int				ft_flag_point(char *str, va_list *arg, int nombre, int pos)
{
	int			i;
	char		*temp;
	int			a;
	t_struct	z;

	z.nb = nombre;
	z.pos = pos;
	temp = str;
	i = 0;
	z.min = 0;
	a = 0;
	if (pos == 2)
		z.pos = 3;
	if (temp[i] == '*')
	{
		z.min = va_arg(*arg, int);
		str++;
		if (z.min < 0 && str[0] != 's' && z.pos == 3 && z.nb > 0)
		{
			z.min = -1;
			z.pos = 4;
		}
	}
	a += ft_flag_point_suite(str, arg, z, 0);
	return (a);
}

int				ft_flag_point_suite(char *str, va_list *arg, t_struct z, int a)
{
	char		*temp;
	char		*nb;

	temp = str;
	if (ft_isdigit(str[0]))
	{
		while (ft_isdigit(temp[a++]))
			str++;
		nb = malloc(sizeof(char) * (a + 1));
		ft_strncpy(nb, temp, a);
		z.min = ft_atoi(nb);
		free(nb);
	}
	a = 0;
	if (str[0] == '%')
	{
		if (z.pos == 3)
			z.pos = 2;
		a += ft_position_onlyonechar(str[0], z.nb - 1, z.pos);
	}
	else if (ft_isalpha(str[0]))
		a += ft_conversiontype(str, arg, z);
	else
		a += ft_conversiontype(str, arg, z);
	return (a);
}

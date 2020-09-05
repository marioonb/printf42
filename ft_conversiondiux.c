/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversiondiux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:13:38 by mbelorge          #+#    #+#             */
/*   Updated: 2020/02/14 13:37:06 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int					ft_conversion_di(va_list *arg, int nb, int pos, int min)
{
	int				num;
	char			*s;
	int				taille;
	int				a;

	num = va_arg(*arg, int);
	a = 0;
	if (min == 0 && num == 0)
		s = ft_strdup("\0");
	else
		s = ft_itoa(num);
	taille = nb - (int)ft_strlen(s);
	if (pos == 0 || pos == 3)
		a += ft_position0(s, taille, min, nb);
	else if (pos == 1)
		a += ft_position1(s, taille, min, nb);
	else if (pos == 2)
		a += ft_position2(s, taille);
	else if (pos == 4)
		a += ft_position4(s, taille, min, nb);
	free(s);
	return (a);
}

int					ft_conversion_u(va_list *arg, t_struct z)
{
	unsigned int	nombre;
	char			*resultat;
	int				taille;
	int				a;

	a = 0;
	nombre = va_arg(*arg, unsigned int);
	if (z.min == 0 && nombre == 0)
		resultat = ft_strdup("\0");
	else
		resultat = ft_itoa_base_unsigned(nombre, 10);
	taille = z.nb - (int)ft_strlen(resultat);
	if (z.pos == 0 || z.pos == 3)
		a += ft_position0(resultat, taille, z.min, z.nb);
	else if (z.pos == 1)
		a += ft_position1(resultat, taille, z.min, z.nb);
	else if (z.pos == 2)
		a += ft_position2(resultat, taille);
	else if (z.pos == 4)
		a += ft_position4(resultat, taille, z.min, z.nb);
	free(resultat);
	return (a);
}

int					ft_conversion_x(char c, va_list *arg, t_struct z)
{
	unsigned int	nombre;
	char			*resultat;
	int				taille;

	nombre = va_arg(*arg, unsigned int);
	if (z.min == 0 && nombre == 0)
		resultat = ft_strdup("\0");
	else
		resultat = ft_itoa_base_unsigned(nombre, 16);
	nombre = 0;
	if (c == 'x')
		resultat = ft_strlowcase(resultat);
	else if (c == 'X')
		resultat = ft_strupcase(resultat);
	taille = z.nb - (int)ft_strlen(resultat);
	if (z.pos == 0 || z.pos == 3)
		nombre += ft_position0(resultat, taille, z.min, z.nb);
	else if (z.pos == 1)
		nombre += ft_position1(resultat, taille, z.min, z.nb);
	else if (z.pos == 2)
		nombre += ft_position2(resultat, taille);
	else if (z.pos == 4)
		nombre += ft_position4(resultat, taille, z.min, z.nb);
	free(resultat);
	return (nombre);
}

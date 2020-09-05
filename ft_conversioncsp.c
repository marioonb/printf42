/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversioncsp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:13:38 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/26 10:47:35 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int					ft_conversion_c(va_list *arg, int nb, int pos)
{
	char			c;
	int				taille;
	int				a;

	c = va_arg(*arg, int);
	a = 0;
	taille = nb - 1;
	a += ft_position_onlyonechar(c, taille, pos);
	return (a);
}

int					ft_conversion_p(va_list *arg, int nb, int pos, int min)
{
	char			*s;
	char			*x;
	int				taille;
	int				a;

	s = va_arg(*arg, char*);
	a = 0;
	if (s == NULL && nb >= 0 && min < 0)
		x = ft_strdup("0x0");
	else if (s == NULL)
		x = ft_strdup("0x");
	else
		x = itoa_base_pointeur(s);
	taille = nb - (int)ft_strlen(x);
	if (min > 0)
	{
		a += ft_putstr_return(x);
		while (min-- > 0)
			a += ft_putchar_return('0');
	}
	else
		a += ft_positionstr(x, taille, pos);
	free(x);
	return (a);
}

int					ft_conversion_s(va_list *arg, int nb, int pos, int min)
{
	char			*s;
	int				taille;
	char			*resultat;
	int				a;

	resultat = NULL;
	s = va_arg(*arg, char *);
	a = 0;
	if (s == NULL)
		s = "(null)";
	if (min == -1)
		min = (int)ft_strlen(s);
	if (pos == 2)
	{
		resultat = malloc(ft_strlen(s));
		ft_strncpy(resultat, s, min);
		taille = nb - (int)ft_strlen(resultat);
		a += ft_positionstr(resultat, taille, pos);
	}
	else if (pos == 1 || pos == 0)
		a += ft_conversion_s_suite(s, nb, pos, min);
	return (a);
}

int					ft_conversion_s_suite(char *s, int nb, int pos, int min)
{
	int			len;
	int			taille;
	int			a;
	char		*resultat;
	char		*x;

	resultat = NULL;
	a = 0;
	resultat = s;
	len = (int)ft_strlen(s);
	if (len > min)
	{
		x = ft_substr(s, 0, min);
		taille = nb - (int)ft_strlen(x);
		a += ft_positionstr(x, taille, pos);
		free(x);
	}
	else
	{
		taille = nb - (int)ft_strlen(resultat);
		a += ft_positionstr(resultat, taille, pos);
	}
	return (a);
}

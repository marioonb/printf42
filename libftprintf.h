/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:13:26 by mbelorge          #+#    #+#             */
/*   Updated: 2020/01/29 16:07:40 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFTPRINTF_H
# define _LIBFTPRINTF_H

# include "./libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>
# include <float.h>
# include <math.h>

typedef	struct	s_struct
{

	int			nb;
	int			min;
	int			pos;
}				t_struct;

int				ft_printf(const char *s, ...);
int				ft_printfrun (char *str, va_list *arg);
int				ft_appliflag(char *str, va_list *arg, int nb, int pos);
int				ft_search_flag_type(char *str, va_list *arg);
int				ft_conversiontype (char *str, va_list *arg, t_struct z);
int				ft_conversion_c (va_list *arg, int nb, int pos);
int				ft_conversion_s(va_list *arg, int nb, int pos, int min);
int				ft_conversion_s_suite(char *s, int nb, int pos, int min);
int				ft_conversion_p(va_list *arg, int nb, int pos, int min);
int				ft_conversion_di(va_list *arg, int nb, int pos, int min);
int				ft_conversion_x(char c, va_list *arg, t_struct z);
int				ft_conversion_u(va_list *arg, t_struct z);
int				ft_flag_zero(char *str, va_list *arg, int pos);
int				ft_flag_zero_suite(char *str, va_list *arg, t_struct z, int a);
int				ft_flag_numerique(char *str, va_list *arg, int pos);
int				ft_flag_point(char *str, va_list *arg, int nombre, int pos);
int				ft_flag_point_suite(char *str, va_list *arg, t_struct z, int a);
int				ft_positionstr (char *str, int taille, int pos);
int				ft_position_onlyonechar (char c, int taille, int pos);
int				ft_position0(char *str, int taille, int min, int max);
int				ft_position1(char *str, int taille, int min, int max);
int				ft_position2(char *str, int taille);
int				ft_position4(char *str, int taille, int min, int max);

#endif

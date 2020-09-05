/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:12:58 by mbelorge          #+#    #+#             */
/*   Updated: 2020/01/29 12:20:20 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_conversiontype(char *str, va_list *arg, t_struct z)
{
	char		c;
	int			a;

	a = 0;
	if (!ft_isalpha(str[0]) && str[0] != '%')
		return (-2000);
	if (str[0] == 'c')
		a += ft_conversion_c(arg, z.nb, z.pos);
	else if (str[0] == 's')
		a += ft_conversion_s(arg, z.nb, z.pos, z.min);
	else if (str[0] == 'p')
		a += ft_conversion_p(arg, z.nb, z.pos, z.min);
	else if (str[0] == 'd' || str[0] == 'i')
		a += ft_conversion_di(arg, z.nb, z.pos, z.min);
	else if (str[0] == 'x' || str[0] == 'X')
	{
		c = str[0];
		a += ft_conversion_x(c, arg, z);
	}
	else if (str[0] == 'u')
		a += ft_conversion_u(arg, z);
	else if (str[0] == '%')
		a += ft_position_onlyonechar(str[0], z.nb - 1, z.pos);
	return (a);
}

int				ft_appliflag(char *str, va_list *arg, int nb, int pos)
{
	int			a;
	int			min;
	t_struct	z;

	min = -1;
	a = 0;
	z.min = min;
	z.nb = nb;
	z.pos = pos;
	if (str[0] == '.')
	{
		str++;
		a += ft_flag_point(str, arg, nb, pos);
	}
	else if (ft_isalpha(str[0]))
		a += ft_conversiontype(&str[0], arg, z);
	else if (str[0] == '0' && !ft_isalpha(str[1]))
		a += ft_flag_zero(str, arg, pos);
	else if (ft_isdigit(str[0]))
		a += ft_flag_numerique(str, arg, pos);
	else if (str[0] == '%')
		a += ft_position_onlyonechar(str[0], 0, pos);
	return (a);
}

int				ft_search_flag_type(char *str, va_list *arg)
{
	int			pos;
	int			nb;
	int			a;

	a = 0;
	pos = 0;
	nb = 0;
	while (str[0] == '-')
	{
		pos = 1;
		str++;
	}
	if (str[0] == '*')
	{
		str++;
		nb = va_arg(*arg, int);
		if (nb < 0)
		{
			pos = 1;
			nb = nb * -1;
		}
	}
	a += ft_appliflag(str, arg, nb, pos);
	return (a);
}

int				ft_printfrun(char *str, va_list *arg)
{
	int			a;

	a = 0;
	while (*str)
	{
		if (*str != '%')
			a += ft_putchar_return(str[0]);
		else
		{
			str++;
			a += ft_search_flag_type(str, arg);
			if (a < 0)
				return (0);
			while (!ft_isalpha(*str) && *str != '%')
				str++;
		}
		str++;
	}
	return (a);
}

int				ft_printf(const char *s, ...)
{
	char		*str;
	va_list		arg;
	int			a;

	str = (char*)s;
	va_start(arg, s);
	a = 0;
	if (ft_strchr(s, '%') == NULL)
	{
		a += ft_putstr_return(str);
		return (a);
	}
	a += ft_printfrun(str, &arg);
	va_end(arg);
	return (a);
}

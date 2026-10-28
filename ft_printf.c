/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ges <jvan-ges@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:00:00 by jvan-ges          #+#    #+#             */
/*   Updated: 2026/10/28 18:00:00 by jvan-ges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_convert : lit le caractère après le '%' et appelle la bonne
** fonction de conversion en lui passant l'argument suivant de la va_list.
** Chaque fonction de conversion renvoie le nombre de caractères écrits,
** ce qui permet de construire la valeur de retour de ft_printf.
*/
static int	ft_convert(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (c == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_print_unbr(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), c));
	if (c == '%')
		return (ft_print_char('%'));
	return (ft_print_char('%') + ft_print_char(c));
}

/*
** ft_printf : parcourt la chaîne de format caractère par caractère.
** - caractère normal : écrit tel quel, compte +1
** - '%' suivi d'un caractère : dispatch vers ft_convert
** On accumule dans 'count' le total de caractères écrits,
** qui est la valeur de retour attendue (comme le vrai printf).
*/
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_convert(format[i + 1], args);
			i += 2;
		}
		else
		{
			count += ft_print_char(format[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}

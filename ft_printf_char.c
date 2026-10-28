/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ges <jvan-ges@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:00:00 by jvan-ges          #+#    #+#             */
/*   Updated: 2026/10/28 18:00:00 by jvan-ges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** strlen maison : les seules fonctions externes autorisées sont
** malloc, free, write et les macros va_*, donc pas de strlen de la libc
** (sauf en passant par la libft).
*/
static size_t	ft_strlen_pf(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

/*
** %c : %c passe par les "default argument promotions" des fonctions
** variadiques : un char est promu en int, d'où le va_arg(args, int)
** côté appelant. write renvoie 1, ce qui est notre compte.
*/
int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

/*
** %s : le vrai printf affiche "(null)" quand la chaîne est NULL
** (comportement glibc, utilisé en comparaison par les testeurs).
*/
int	ft_print_str(char *s)
{
	if (!s)
		s = "(null)";
	return (write(1, s, ft_strlen_pf(s)));
}

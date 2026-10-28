/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ges <jvan-ges@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:00:00 by jvan-ges          #+#    #+#             */
/*   Updated: 2026/10/28 18:00:00 by jvan-ges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Affichage récursif en base 16 (même principe que la base 10).
** 'base' pointe vers l'alphabet minuscule ou majuscule selon
** que la conversion demandée est %x ou %X.
*/
static int	ft_print_hex_rec(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_print_hex_rec(n / 16, base);
	count += ft_print_char(base[n % 16]);
	return (count);
}

/*
** %x / %X : un unsigned int tient dans un unsigned long,
** on réutilise donc la même fonction récursive.
*/
int	ft_print_hex(unsigned int n, char format)
{
	char	*base;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (ft_print_hex_rec(n, base));
}

/*
** %p : on caste le pointeur en unsigned long (type garanti assez grand
** pour contenir une adresse) et on affiche en hexa avec le préfixe "0x".
** Un pointeur NULL s'affiche "(nil)" avec la glibc.
*/
int	ft_print_ptr(void *ptr)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2)
		+ ft_print_hex_rec((unsigned long)ptr, "0123456789abcdef"));
}

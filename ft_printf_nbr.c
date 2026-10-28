/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ges <jvan-ges@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:00:00 by jvan-ges          #+#    #+#             */
/*   Updated: 2026/10/28 18:00:00 by jvan-ges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Affichage récursif d'un nombre positif en base 10 :
** on descend d'abord jusqu'au chiffre le plus à gauche (division par 10),
** puis on écrit les chiffres en remontant la pile d'appels.
** Chaque appel ajoute 1 au compte total.
*/
static int	ft_print_digits(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_digits(n / 10);
	count += ft_print_char(n % 10 + '0');
	return (count);
}

/*
** %d / %i : on convertit l'int en long pour gérer INT_MIN en toute
** sécurité (-INT_MIN déborde sur un int, pas sur un long),
** puis on affiche le signe avant la valeur absolue.
*/
int	ft_print_nbr(int n)
{
	int		count;
	long	nb;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = -nb;
	}
	count += ft_print_digits((unsigned int)nb);
	return (count);
}

/*
** %u : même logique que %d, sans la gestion du signe puisque
** le type est unsigned int.
*/
int	ft_print_unbr(unsigned int n)
{
	return (ft_print_digits(n));
}

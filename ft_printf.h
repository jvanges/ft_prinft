/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ges <jvan-ges@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:00:00 by jvan-ges          #+#    #+#             */
/*   Updated: 2026/10/28 18:00:00 by jvan-ges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

/* Fonction principale */
int	ft_printf(const char *format, ...);

/* Fonctions de conversion : chacune renvoie le nombre de caractères écrits */
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_nbr(int n);
int	ft_print_unbr(unsigned int n);
int	ft_print_hex(unsigned int n, char format);
int	ft_print_ptr(void *ptr);

#endif

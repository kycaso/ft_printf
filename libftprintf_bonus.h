/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelda-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:44:51 by fbelda-h          #+#    #+#             */
/*   Updated: 2021/07/12 16:50:56 by fbelda-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_BONUS_H
# define LIBFTPRINTF_BONUS_H

# include <stdarg.h>
# include "libft/libft.h"
# include "unistd.h"
# include "stdlib.h"
# include <stdio.h>

typedef struct s_word
{
	int			width;
	char		flag;
	int			sign;
	int			pre;
	int			preval;
	char		type;
}	t_word;
int		ft_printf(const char *s, ...);
int		next_char(char *s, int i);
int		piecer(va_list *argptr, char *s, int i);
void	smaker(t_word **text, char *s, va_list *argptr);
int		pather(t_word **text, va_list *argptr);
int		chars(t_word **text, int p);
int		strings(t_word **text, va_list *argptr);
int		ent_logar(int base, int n);
void	asterisk(va_list *argptr, t_word **text);
int		final_s(char *s, t_word **text);
char	*mono_char(char c, int len);
char	*itoa_aux(int n, int sign, long unsigned int nb, int b);
char	*itoa_aux2(int n, int sign, long unsigned int nb, int b);
char	*i_b(t_word **text, long unsigned int nb, int b, int t);
int		numbers(t_word **text, char *s);
int		numbers2(t_word **text, char *s);
char	*pre(t_word **text, char *s);
char	*zerosigned(char *s1, char *s2);
int		pointers(t_word **text, long unsigned int n);

#endif

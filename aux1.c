/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelda-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:44:34 by fbelda-h          #+#    #+#             */
/*   Updated: 2021/07/07 13:31:24 by fbelda-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ent_logar(int b, int n)
{
	int	log;

	if (n <= 0)
		return (0);
	log = 1;
	while (n / b > 0)
	{
		n /= b;
		log++;
	}
	return (log - 1);
}

void	asterisk(va_list *argptr, t_word **text)
{
	int	n;

	n = va_arg(*argptr, int);
	if ((*text)->pre == 1)
	{
		(*text)->preval = n;
		if ((*text)->type == 's' && n < 0)
			(*text)->pre = n;
	}
	else
	{
		(*text)->width = n;
		if (n < 0)
		{
			(*text)->width = -n;
			(*text)->flag = '-';
		}
	}
}

int	chars(t_word **text, int p)
{
	char	c;
	int		i;
	char	ca;

	if ((*text)->flag == '0')
		ca = '0';
	else
		ca = ' ';
	c = p;
	i = 0;
	if ((*text)->flag == '-')
	{
		write(1, &c, 1);
		while (i++ < (*text)->width - 1)
			write(1, " ", 1);
	}
	else
	{
		while (i++ < (*text)->width - 1)
			write(1, &ca, 1);
		write(1, &c, 1);
	}
	if ((*text)->width != 0)
		return ((*text)->width);
	return (1);
}

int	strings(t_word **text, va_list *argptr)
{
	char	*s;
	char	*s2;

	s = ft_strdup(va_arg(*argptr, char *));
	if (!s)
	{
		free (s);
		s = ft_strdup("(null)");
	}
	s2 = NULL;
	if ((*text)->pre == 1 && (*text)->preval < ft_strlen(s))
	{
		if ((*text)->width >= (*text)->preval)
			(*text)->width -= (*text)->preval;
		s2 = ft_substr(s, 0, (*text)->preval);
		free (s);
		s = ft_strdup(s2);
		free (s2);
	}
	else if ((*text)->width > ft_strlen(s))
		(*text)->width -= ft_strlen(s);
	else if ((*text)->width <= ft_strlen(s))
		(*text)->width = 0;
	return (final_s(s, text));
}

int	final_s(char *s, t_word **text)
{
	int		i;
	char	*aux;
	char	*spaces;

	spaces = NULL;
	if ((*text)->width != 0)
	{
		spaces = mono_char(' ', (*text)->width);
		if ((*text)->flag == '-')
			aux = ft_strjoin(s, spaces);
		else
			aux = ft_strjoin(spaces, s);
	}
	else
		aux = ft_strdup(s);
	i = -1;
	while (aux[++i] != '\0')
		write(1, &aux[i], 1);
	free (s);
	free (aux);
	if (spaces)
		free (spaces);
	return (i);
}

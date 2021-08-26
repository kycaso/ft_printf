/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelda-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:24:37 by fbelda-h          #+#    #+#             */
/*   Updated: 2021/07/07 14:24:39 by fbelda-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	numbers(t_word **text, char *s)
{
	if ((*text)->pre == 1 && s[0] == '0' && (*text)->preval >= 0)
	{
		free (s);
		s = mono_char(' ', 0);
	}
	if ((*text)->preval > ft_strlen(s))
		(*text)->preval -= ft_strlen(s);
	else
		(*text)->preval = 0;
	if ((*text)->preval != 0)
		s = pre(text, s);
	if ((*text)->width > ft_strlen(s))
		(*text)->width -= ft_strlen(s);
	else
		(*text)->width = 0;
	if ((*text)->pre == 1 && (*text)->flag == '0')
		(*text)->flag = 0;
	return (numbers2(text, s));
}

int	numbers2(t_word **text, char *s)
{
	int		i;
	char	*aux;
	char	*holes;

	if ((*text)->flag == '0')
		holes = mono_char('0', (*text)->width);
	else
		holes = mono_char(' ', (*text)->width);
	if ((*text)->flag == '-' && (*text)->width != 0)
		aux = ft_strjoin(s, holes);
	else if ((*text)->flag == '0' && (*text)->sign != 0)
		aux = zerosigned(s, holes);
	else if ((*text)->width != 0)
		aux = ft_strjoin(holes, s);
	else
		aux = ft_strdup(s);
	i = -1;
	while (aux[++i] != '\0')
		write(1, &aux[i], 1);
	free (aux);
	free (s);
	free (holes);
	return (i);
}

char	*zerosigned(char *s1, char *s2)
{
	char	*sol;
	int		i;
	int		j;

	sol = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	if (!sol)
		return (NULL);
	sol[i] = '-';
	i++;
	j = 0;
	while (s2[j] != '\0')
		sol[i++] = s2[j++];
	j = 1;
	while (s1[j] != '\0')
	{
		sol[i] = s1[j];
		i++;
		j++;
	}
	sol[i] = '\0';
	return (sol);
}

char	*pre(t_word **text, char *s)
{
	int		i;
	int		j;
	char	*s2;

	s2 = (char *)malloc(ft_strlen(s) + (*text)->preval + 1 + (*text)->sign);
	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	if ((*text)->sign == 1 )
		s2[i++] = s[j++];
	(*text)->preval += (*text)->sign;
	while (i - (*text)->sign < (*text)->preval)
	{
		s2[i] = '0';
		i++;
	}
	while (s[j] != '\0')
		s2[i++] = s[j++];
	s2[i] = '\0';
	free (s);
	return (s2);
}

int	pointers(t_word **text, long unsigned int n)
{
	char	*num;
	char	*p;

	num = i_b(text, n, 16, 0);
	p = ft_strjoin("0x\0", num);
	free (num);
	return (numbers(text, p));
}

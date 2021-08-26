/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelda-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:30:46 by fbelda-h          #+#    #+#             */
/*   Updated: 2021/07/07 13:32:54 by fbelda-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*mono_char(char c, int len)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*itoa_aux(int n, int sign, long unsigned int nb, int b)
{
	char	*s;
	int		i;
	char	*p;

	p = "0123456789abcdef";
	s = malloc(n + sign + 1);
	if (!s)
		return (NULL);
	if (sign == 1)
		s[0] = '-';
	i = n + sign - 1;
	while (i >= sign)
	{
		s[i] = p[nb % b];
		nb = nb / b;
		i--;
	}
	s[n + sign] = '\0';
	return (s);
}

char	*itoa_aux2(int n, int sign, long unsigned int nb, int b)
{
	char	*s;
	int		i;
	char	*p;

	p = "0123456789ABCDEF";
	s = malloc(n + sign + 1);
	if (!s)
		return (NULL);
	if (sign == 1)
		s[0] = '-';
	i = n + sign - 1;
	while (i >= sign)
	{
		s[i] = p[nb % b];
		nb = nb / b;
		i--;
	}
	s[n + sign] = '\0';
	return (s);
}

char	*i_b(t_word **text, long unsigned int n, int b, int t)
{
	long unsigned int	nb;
	long unsigned int	nb2;

	nb = n;
	nb2 = n;
	if ((*text)->type == 'i' || (*text)->type == 'd')
	{
		if ((int)n < 0)
			(*text)->sign = 1;
		return (ft_itoa((int)n));
	}
	n = 1;
	while (nb2 > (long unsigned int)b - 1)
	{
		nb2 = nb2 / b;
		n++;
	}
	if (t == 0)
		return (itoa_aux(n, (*text)->sign, nb, b));
	return (itoa_aux2(n, (*text)->sign, nb, b));
}

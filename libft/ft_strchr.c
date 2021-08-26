/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelda-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:33:24 by fbelda-h          #+#    #+#             */
/*   Updated: 2021/04/25 19:01:12 by fbelda-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	l;
	int		i;

	l = c;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == l)
			return ((char *)&s[i++]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelda-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:38:56 by fbelda-h          #+#    #+#             */
/*   Updated: 2021/03/19 20:24:13 by fbelda-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	l;

	if (ft_strlen(s1) > ft_strlen(s2))
		l = ft_strlen(s1) + 1;
	else
		l = ft_strlen(s2) + 1;
	i = 0;
	while (i < n && i < l)
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		else if ((unsigned char)s2[i] < (unsigned char)s1[i])
			return (1);
		i++;
	}
	return (0);
}

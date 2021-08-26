/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelda-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:19:54 by fbelda-h          #+#    #+#             */
/*   Updated: 2021/03/13 20:18:21 by fbelda-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*old;
	t_list	*new;

	ret = ft_lstnew(f(lst->content));
	if (!lst || !ret)
		return (NULL);
	old = lst->next;
	new = ret;
	while (old)
	{
		new->next = ft_lstnew(f(old->content));
		if (!(new->next))
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		new = new->next;
		old = old->next;
	}
	return (ret);
}

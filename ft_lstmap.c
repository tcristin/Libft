/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcristin <tcristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:01:24 by tcristin          #+#    #+#             */
/*   Updated: 2021/10/23 17:51:33 by tcristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur;
	t_list	*begin;

	if (!f || !lst)
		return (NULL);
	begin = ft_lstnew(f(lst->content));
	if (!begin)
		return (NULL);
	lst = lst->next;
	cur = 0;
	while (lst)
	{
		cur = ft_lstnew(f(lst->content));
		if (!cur)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		ft_lstadd_back(&begin, cur);
		lst = lst->next;
	}
	return (begin);
}

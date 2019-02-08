/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:23:09 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/16 11:23:40 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*first;
	t_list	*cour;

	if (!(lst))
		return (NULL);
	tmp = f(lst);
	if ((cour = ft_lstnew(tmp->content, tmp->content_size)) == NULL)
		return (NULL);
	first = cour;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if ((cour->next = ft_lstnew(tmp->content, tmp->content_size)) == NULL)
			return (NULL);
		cour = cour->next;
		lst = lst->next;
	}
	return (first);
}

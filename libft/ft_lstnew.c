/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:55:00 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/14 15:05:45 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*tmp;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		if (!(tmp = (void *)malloc(content_size)))
			return (0);
		new->content = tmp;
		ft_memcpy(tmp, content, content_size);
		new->content_size = content_size;
	}
	else
	{
		(void)content_size;
		new->content_size = 0;
		new->content = NULL;
	}
	new->next = NULL;
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:38:45 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/14 15:47:17 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*supr;

	while (*alst != NULL)
	{
		supr = (*alst);
		del((*alst)->content, (*alst)->content_size);
		(*alst) = (*alst)->next;
		free(supr);
		supr = NULL;
	}
}

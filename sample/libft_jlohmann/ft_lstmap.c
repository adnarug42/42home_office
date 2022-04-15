/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlohmann <jlohmann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:36:30 by jlohmann          #+#    #+#             */
/*   Updated: 2022/04/12 00:17:52 by jlohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*next_node;

	if (lst && f)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
			return (NULL);
		if (lst->next)
		{
			next_node = ft_lstmap(lst->next, f, del);
			if (!next_node)
			{
				ft_lstdelone(new_node, del);
				return (NULL);
			}
			ft_lstadd_front(&next_node, new_node);
		}
		return (new_node);
	}
	return (NULL);
}

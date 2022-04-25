/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:25:16 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/21 16:33:22 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list			node;

	node.next = (t_list *) malloc(sizeof(t_list));
	if (node.next == NULL)
		return (NULL);
	node.next -> content = content;
	node.next -> next = NULL;
	return (node.next);
}

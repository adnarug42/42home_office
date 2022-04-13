/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:10:00 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/13 18:53:00 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void (*f)(void *), void (*del)(void *))
{
	t_list				*new_lst;
	t_list				*new_lst_start;
	t_list				*new_list_end;
	
	while (lst != NULL)
	{
		f(lst -> content);
			while (new_lst != NULL)
			{
				new_lst = malloc (ft_lstsize(lst) * sizeof(t_list));
				if (new_lst == NULL)
					del (new_lst);
				new_lst = lst;
				lst = lst -> next;
				new_lst = new_lst -> next;
			}
	}
	return (new_lst);
}
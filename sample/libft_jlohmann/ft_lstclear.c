/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlohmann <jlohmann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:54:25 by jlohmann          #+#    #+#             */
/*   Updated: 2022/04/11 14:46:46 by jlohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst && del)
	{
		if ((*lst)->next)
			ft_lstclear(&((*lst)->next), del);
		ft_lstdelone(*lst, del);
	}
	*lst = NULL;
}

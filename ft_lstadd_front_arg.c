/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:29:44 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/27 16:36:50 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"

void	ft_lstadd_front_arg(lst_arg **lst, lst_arg *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new -> next = *lst;
	*lst = new;
}

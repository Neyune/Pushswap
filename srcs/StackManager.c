/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackManager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:55:41 by ereali            #+#    #+#             */
/*   Updated: 2021/07/21 00:57:38 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	Createchain(t_list **root, int *lst, int lstlen)
{
	int	i;

	i = 0;
	while (i < lstlen)
	{
		ft_lstadd_back(root, ft_lstnew(lst[i]));
		i++;
	}
}

t_list	*StackGeneration(int lstlen, int *lst)
{
	t_list	*a;

	a = NULL;
	Createchain(&a, lst, lstlen);
	free(lst);
	return (a);
}

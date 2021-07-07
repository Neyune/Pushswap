/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:56:17 by ereali            #+#    #+#             */
/*   Updated: 2021/07/06 13:40:08 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	Sort3(int *lst, int len)
{
	if (len == 2)
		ft_putstr_fd("sa\n", 1);
	// cas4 https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
	else if ((lst[0] < lst[2]) && (lst[2] < lst[1]))
		ft_putstr_fd("sa\nra\n", 1);
	// cas 1
	else if ((lst[1] < lst[0]) && (lst[0] < lst[2]))
		ft_putstr_fd("sa\n", 1);
	// cas 5
	else if ((lst[1] < lst[2]) && (lst[2] < lst[0]))
		ft_putstr_fd("rra\n", 1);
	// cas 3
	else if ((lst[2] < lst[0]) && (lst[0] < lst[1]))
		ft_putstr_fd("ra\n", 1);
	// cas 2
	else if ((lst[2] < lst[1]) && (lst[1] < lst[0]))
		ft_putstr_fd("sa\nrra\n", 1);
	if (len != 2)
		free(lst);
	exit(EXIT_SUCCESS);
}

void	Shortsort(t_list **root)
{
	   t_list	*tmp;
	   // int		len;
	   int		smallest;
	   // int		seclowest;
	   tmp = (*root);
	   smallest	= tmp->value;
	   while (tmp)
	   {
		if (tmp->value < smallest)
		{
			smallest = tmp->value;
		}
	   	tmp = tmp->next;
	   }
}

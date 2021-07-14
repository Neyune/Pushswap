/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortAll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:54:58 by ereali            #+#    #+#             */
/*   Updated: 2021/07/14 19:54:35 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

void	Find_position(t_list *stack, t_list **root)
{
	   t_list	*tmp;
	   t_list	*other;

	   tmp = stack;
	   other = (*root);
	   tmp->finalpos = 0;
	   while (other)
	   {
		    if (other->value < tmp->value)
				tmp->finalpos = (tmp->finalpos + 1);
	     other = other->next;
	 	}
}

void	Setposition(t_list **root)
{
	t_list	*tmp;
	int i;
	int size;

	i = 0;
	tmp = (*root);
	size = ft_lstsize(tmp);
	while (i < size)
	{
		Find_position(tmp , root);
		tmp = tmp->next;
		i++;
	}
}

int		Checkra(t_list **root)
{
	t_list	*tmp;

	if (!root)
		return (-1);
	tmp = (*root);
	while (tmp && ((tmp->finalpos) & 1) == 1)
	{
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (1);
	return (0);
}

void	ft_order(t_list **a, t_list **b)
{
	t_list	*tmp;
	unsigned int i;
	unsigned int len;

	tmp = (*a);
	len = ft_lstsize(*a);
	i = 0;

	while (!Chainissort(tmp))
	{
		len = ft_lstsize(tmp);
		while (len-- && tmp)
		{
			 if ((tmp->finalpos & (1 << i)) == 0)
				PushB(b, a);
			else
				Rotate(a);
			if (Checkra(a) == 1)
					break;
			tmp = (*a);
		}
		PushAllToA(a, b);
		tmp = (*a)	;
		i++;
		Needra(a);
	}
	freelst(a);
	exit(EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortAll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:54:58 by ereali            #+#    #+#             */
/*   Updated: 2021/07/09 06:34:50 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	Find_position(t_list *stack, t_list **root)
{
	   t_list	*tmp;
	   t_list	*other;
	   // t_list	*nextsmall;

	   tmp = stack;
	   // nextsmall = tmp;
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

int		Checkrra(t_list **root, unsigned int mask)
{
	t_list	*tmp;

	if (!root || mask < 0b10000000000000000000000000000000)
		return (-1);
	tmp = (*root);
	while (tmp && ((tmp->finalpos) & mask))
	{
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (1);
	if (!((tmp->finalpos) & mask))
		return (0);
	return (0);
}

int		Chainissort(t_list **a)
{
	t_list	*tmp;

	if (!a)
		return (-1);
	tmp = (*a);
	while (!(tmp->next) && (tmp->next->finalpos == (tmp->finalpos + 1)))
			tmp = tmp->next;

	if (tmp == NULL)
		return (1);
	else
		return (0);

}

void PushAllToA(t_list **a, t_list **b)
{
	if (!b)
		return ;
	while ((*b))
		PushA(a, b);
}
void	ft_order(t_list **a, t_list **b)
{
	t_list	*tmp;
	unsigned int mask;
	unsigned int len;

	tmp = (*a);
	len = ft_lstsize(tmp);
	mask = 0x0001;
	while (!Chainissort(a) || mask < 0b10000000000000000000000000000000)
	{
		while (len-- && tmp)
		{
			if ((tmp->finalpos) & mask)
			{
				if (Checkrra(a, mask))
						break;
				Rotate(a);
			}
			else
				PushB(b, a);
		printf("On en est ICI : %d\n", tmp->finalpos);
			tmp = (*a);
		printf("On en est là : %d\n", tmp->finalpos);
		}
		printf("----------------------------B1-----------------------------------\n");
		PrintfChain(b);
		PushAllToA(a, b);
		printf("----------------------------B2-----------------------------------\n");
		PrintfChain(b);
		printf("----------------------------A2-----------------------------------\n");
		PrintfChain(a);
		if (Chainissort(a))
			exit(EXIT_SUCCESS);
		// if ()
			mask = mask >> 1;
	}
}

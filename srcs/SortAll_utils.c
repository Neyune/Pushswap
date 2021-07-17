/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortAll_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:46:36 by ereali            #+#    #+#             */
/*   Updated: 2021/07/17 20:20:30 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	Chainissort(t_list *a)
{
	t_list	*tmp;

	if (!a)
		return (-1);
	tmp = a;
	while ((tmp->next) && (tmp->next->finalpos == (tmp->finalpos + 1)))
		tmp = tmp->next;
	if (tmp->next == NULL)
		return (1);
	else
		return (0);
}

int	Chain_is_sort_to_n(t_list **a, unsigned int n)
{
	t_list	*tmp;

	tmp = (*a);
	if (!a)
		return (-1);
	if (tmp->finalpos == n)
		return (1);
	while ((tmp->next) && (tmp->next->finalpos == (tmp->finalpos + 1))
		&& (tmp->next->finalpos != n))
		tmp = tmp->next;
	if ((tmp->finalpos == n - 1)
		&& (tmp->next->finalpos == (tmp->finalpos + 1)))
		return (1);
	else
		return (0);
}

void	Do_ra(t_list **a, unsigned int i, unsigned int size)
{
	if ((size - i) < i || i == size - i)
	{
		while (size > i)
		{
			ReverseRotate(a);
			size--;
		}
	}
	else if (i < (size - i))
	{
		while (i > 0)
		{
			Rotate(a);
			i--;
		}
	}
}

void	Needra(t_list **a)
{
	t_list			*tmp;
	unsigned int	i;
	unsigned int	size;

	i = 1;
	size = ft_lstsize(*a);
	tmp = (*a);
	if (Chain_is_sort_to_n(a, (size - 1)))
	{
		while (tmp->finalpos != (size - 1))
		{
			tmp = tmp->next;
			i++;
		}
	}
	tmp = tmp->next;
	if (!Chainissort(tmp))
		return ;
	Do_ra(a, i, size);
	freelst(a);
	exit(EXIT_SUCCESS);
}

void	PushAllToA(t_list **a, t_list **b)
{
	if (!b)
		return ;
	while ((*b))
		PushA(a, b);
}

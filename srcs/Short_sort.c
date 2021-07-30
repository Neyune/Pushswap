/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:56:17 by ereali            #+#    #+#             */
/*   Updated: 2021/07/29 18:49:26 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	Sort3(int *lst, int len)
{
	if (len == 2)
		ft_putstr_fd("sa\n", 1);
	else if ((lst[0] < lst[2]) && (lst[2] < lst[1]))
		ft_putstr_fd("sa\nra\n", 1);
	else if ((lst[1] < lst[0]) && (lst[0] < lst[2]))
		ft_putstr_fd("sa\n", 1);
	else if ((lst[1] < lst[2]) && (lst[2] < lst[0]))
		ft_putstr_fd("ra\n", 1);
	else if ((lst[2] < lst[0]) && (lst[0] < lst[1]))
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("sa\nrra\n", 1);
	free(lst);
	exit(EXIT_SUCCESS);
}

void	Sort3Chain(t_list **a)
{
	t_list	*tmp;

	tmp = (*a);
	if ((tmp->finalpos < tmp->next->next->finalpos)
		&& (tmp->next->next->finalpos < tmp->next->finalpos))
	{
		Swap(a);
		Rotate(a);
	}
	else if ((tmp->next->finalpos < tmp->finalpos)
		&& (tmp->finalpos < tmp->next->next->finalpos))
		Swap(a);
	else if ((tmp->next->finalpos < tmp->next->next->finalpos)
		&& (tmp->next->next->finalpos < tmp->finalpos))
		ReverseRotate(a);
	else if ((tmp->next->next->finalpos < tmp->finalpos)
		&& (tmp->finalpos < tmp->next->finalpos))
		Rotate(a);
	else if ((tmp->next->next->finalpos < tmp->next->finalpos)
		&& (tmp->next->finalpos < tmp->finalpos))
	{
		Swap(a);
		ReverseRotate(a);
	}
}

void	CheckB(t_list **b, unsigned int maxpos)
{
	t_list	*tmp;

	tmp = (*b);
	if (ft_lstsize(tmp) != 2)
		return ;
	if (tmp->next)
	{
		if (tmp->next->finalpos == 0)
			SwapB(b);
		if (tmp->finalpos == maxpos - 1)
			SwapB(b);
	}
}

void	sort5(t_list **a, t_list **b)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_lstsize(*a);
	while (i != len - 3)
	{
		PushB(b, a);
		i++;
	}
	i = len;
	Sort3Chain(a);
	CheckB(b, len);
	while ((*b) != NULL)
	{
		if ((*a)->finalpos == ((*b)->finalpos + 1) || ((*b)->finalpos == i + 1)
			|| ((*b)->finalpos == 0 && i == len - 1))
			PushA(a, b);
		else
		{
			i = (*a)->finalpos;
			Rotate(a);
		}
	}
	Needra(a);
}

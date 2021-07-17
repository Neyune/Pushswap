/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:56:17 by ereali            #+#    #+#             */
/*   Updated: 2021/07/17 21:20:42 by ereali           ###   ########.fr       */
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
		ft_putstr_fd("rra\n", 1);
	else if ((lst[2] < lst[0]) && (lst[0] < lst[1]))
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("sa\nrra\n", 1);
	if (lst)
		free(lst);
	exit(EXIT_SUCCESS);
}

void	Sort3Chain(t_list **a, unsigned int len)
{
	t_list	*tmp;

	tmp = (*a);
	if (len != 3)
		return ;
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
	else
	{
		Swap(a);
		ReverseRotate(a);
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
	i = len ;
	Sort3Chain(a, ft_lstsize(*a));
	while ((*b) != NULL)
	{
		if ((*a)->finalpos == ((*b)->finalpos + 1) || ((*b)->finalpos == i + 1))
			PushA(a, b);
		else
		{
			i = (*a)->finalpos;
			Rotate(a);
		}
	}
	Needra(a);
	freelst(a);
	exit(EXIT_SUCCESS);
}

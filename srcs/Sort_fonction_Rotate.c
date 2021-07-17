/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_fonction_Rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:43:56 by ereali            #+#    #+#             */
/*   Updated: 2021/07/17 20:47:47 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	Rotate(t_list **stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	tmp = (*stack);
	(*stack) = tmp->next;
	ft_lstadd_back(stack, tmp);
	ft_putstr_fd("ra\n", 1);
}

void	RotateAll(t_list **stackA, t_list **stackB)
{
	if ((!stackA) || (!stackB))
		return ;
	Rotate(stackA);
	Rotate(stackB);
}

void	ReverseRotate(t_list **stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	tmp = SecondToLast(stack);
	ft_lstadd_front(stack, GetLastStack(stack));
	tmp->next = NULL;
	ft_putstr_fd("rra\n", 1);
}

void	ReverseRotateAll(t_list **stackA, t_list **stackB)
{
	if ((!stackA) || (!stackB))
		return ;
	ReverseRotate(stackA);
	ReverseRotate(stackB);
}

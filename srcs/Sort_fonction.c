/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_fonction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:25:46 by ereali            #+#    #+#             */
/*   Updated: 2021/07/07 16:02:18 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	Swap(t_list **stack)
{
	int first;
	t_list *tmp;

	tmp = (*stack);
	first = tmp->value;
	(*stack)->value = tmp->next->value;
	tmp = tmp->next;
	tmp->value = first;
}

void	SwapAll(t_list **stackA, t_list **stackB)
{
		if ((!stackA) || (!stackB))
			return ;
		Swap(stackA);
		Swap(stackB);
}

void	Rotate(t_list **stack)
{
		t_list	*tmp;

		if (!stack)
				return ;
		tmp = (*stack);
		(*stack) = tmp->next;
		ft_lstadd_back(stack, tmp);
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
}

void	ReverseRotateAll(t_list **stackA, t_list **stackB)
{
		if ((!stackA) || (!stackB))
			return ;
		ReverseRotate(stackA);
		ReverseRotate(stackB);
}

void	Push(t_list **stack1, t_list **stack2)
{
		t_list	*tmp;

		tmp = (*stack2);
		(*stack2) = (*stack2)->next;
		ft_lstadd_front(stack1, tmp);
		
}

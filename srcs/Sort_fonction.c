/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_fonction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:25:46 by ereali            #+#    #+#             */
/*   Updated: 2021/07/13 22:39:20 by ereali           ###   ########.fr       */
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

void	PushA(t_list **stack1, t_list **stack2)
{
		t_list	*tmp;

		tmp = (*stack2);
		(*stack2) = (*stack2)->next;
		ft_lstadd_front(stack1, tmp);
		ft_putstr_fd("pa\n", 1);
}

void	PushB(t_list **stack1, t_list **stack2)
{
		t_list	*tmp;

		tmp = (*stack2);
		(*stack2) = (*stack2)->next;
		ft_lstadd_front(stack1, tmp);
		ft_putstr_fd("pb\n", 1);
		// 	printf("=================================A==============================\n");
		//
		// PrintfChain(stack2);
		// printf("=================================B==============================\n");
		//
		// PrintfChain(stack1);
		// 		printf("===============================================================\n");
}

// void PushB(t_list *a, t_list *b) {
// 	t_list	*tmp;
//
// 	printf("ici\n");
// 	if (a == NULL)
// 		return ;
// 	printf("coucou\n");
// 	tmp = a->next;
// 	a->next = b;
// 	a = tmp;
// 	printf("=================================A==============================\n");
// 	PrintfChain(&a);
// 	printf("=================================B==============================\n");
// 	PrintfChain(&b);
// }

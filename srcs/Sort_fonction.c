/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_fonction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:25:46 by ereali            #+#    #+#             */
/*   Updated: 2021/07/18 01:21:50 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	Swap(t_list **stack)
{
	unsigned int	i;
	int				first;
	t_list			*tmp;

	tmp = (*stack);
	first = tmp->value;
	i = tmp->finalpos;
	(*stack)->value = tmp->next->value;
	(*stack)->finalpos = tmp->next->finalpos;
	tmp = tmp->next;
	tmp->value = first;
	tmp->finalpos = i;
	ft_putstr_fd("sa\n", 1);
}

void	SwapB(t_list **stack)
{
	unsigned int	i;
	int				first;
	t_list			*tmp;

	tmp = (*stack);
	if (ft_lstsize(tmp) == 1)
		return ;
	first = tmp->value;
	i = tmp->finalpos;
	(*stack)->value = tmp->next->value;
	(*stack)->finalpos = tmp->next->finalpos;
	tmp = tmp->next;
	tmp->value = first;
	tmp->finalpos = i;
	ft_putstr_fd("sb\n", 1);
}

void	SwapAll(t_list **stackA, t_list **stackB)
{
	if ((!stackA) || (!stackB))
		return ;
	Swap(stackA);
	Swap(stackB);
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
}

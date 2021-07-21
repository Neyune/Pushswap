/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:31:13 by ereali            #+#    #+#             */
/*   Updated: 2021/07/21 01:07:35 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\n'
		|| c == '\r' || c == '\f')
		return (1);
	return (0);
}

t_list	*SecondToLast(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	while (tmp->next->next)
		tmp = tmp->next;
	return (tmp);
}

t_list	*GetLastStack(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

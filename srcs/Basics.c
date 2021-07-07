/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:31:13 by ereali            #+#    #+#             */
/*   Updated: 2021/07/07 14:24:40 by ereali           ###   ########.fr       */
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

int	ft_atof(char *str)
{
	int		sign;
	int		i;
	int		nb;

	sign = 1;
	i = 0;
	nb = 0;
	if (str[i] == '\0')
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + str[i] - '0';
		i++;
	}
	return (nb * sign);
}
t_list	*SecondToLast(t_list **stack)
{
	t_list	*tmp;

	tmp =(*stack);
	while (tmp->next->next)
		tmp = tmp->next;
	return (tmp);
}

t_list	*GetLastStack(t_list **stack)
{
	t_list	*tmp;

	tmp =(*stack);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

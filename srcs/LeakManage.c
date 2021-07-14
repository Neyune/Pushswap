/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LeakManage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:06:55 by ereali            #+#    #+#             */
/*   Updated: 2021/07/14 18:29:23 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freetab(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

void	ExitError(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(EXIT_FAILURE);
}

void	freelst(t_list **a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*a);
	while (tmp->next)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

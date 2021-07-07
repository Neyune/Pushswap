/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LeakManage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:06:55 by ereali            #+#    #+#             */
/*   Updated: 2021/07/07 14:26:34 by ereali           ###   ########.fr       */
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

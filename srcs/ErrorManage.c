/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorManage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:47:35 by ereali            #+#    #+#             */
/*   Updated: 2021/07/15 16:10:15 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	strisdigit(char *args)
{
	int	i;

	i = 1;
	while ((args[i] && ft_isdigit(args[i])) || (args[i] && ft_isspace(args[i]))
		|| ((args[i] == '-') && ft_isdigit(args[i + 1])))
		i++;
	if (args[i])
	{
		free(args);
		ExitError();
	}
}

int	lentab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	*atoitab(char **tab)
{
	int	*lst;
	int	i;

	i = 0;
	lst = (int *)malloc(sizeof (int) * lentab(tab));
	if (!lst)
		return (NULL);
	while (i < lentab(tab))
	{
		lst[i] = ft_atoi(tab[i]);
		i++;
	}
	i = 0;
	return (lst);
}

int	*ErrorGest(char *args)
{
	char	**tab;
	int		*lst;
	int		i;
	int		j;

	i = -1;
	strisdigit(args);
	tab = ft_split(args, ' ');
	lst = atoitab(tab);
	freetab(tab, (lentab(tab) - 1));
	while (i < (lentab(tab) - 2))
	{
		i++;
		j = i + 1;
		while (j < (lentab(tab) - 1) && (lst[j] != lst[i]))
			j++;
		if (lst[j] == lst[i])
		{
			free(lst);
			ExitError();
		}
	}
	return (lst);
}

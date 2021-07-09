/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorManage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:47:35 by ereali            #+#    #+#             */
/*   Updated: 2021/07/07 19:57:07 by ereali           ###   ########.fr       */
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

	// printf("%s\n", args);
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
	// while (i < lentab(tab))
	// {
	// 			printf("%d\n", lst[i]);
	// 			i++;
	// }
	return (lst);
}

int	*ErrorGest(char *args)
{
	char	**tab;
	int		*lst;
	int		i;
	int		j;

	i = -1;
	// printf("ARGC = %d\n", argc);
	strisdigit(args);
	tab = ft_split(args, ' ');
	lst = atoitab(tab);
	//printf("LenTab = %d\n", lentab(tab));
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorManage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:47:35 by ereali            #+#    #+#             */
/*   Updated: 2021/07/27 03:46:57 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	strisdigit(char *args)
{
	int	i;

	i = 1;
	while ((args[i] && ft_isdigit(args[i])) || (args[i] && ft_isspace(args[i]))
		|| ((args[i] == '-') && ft_isdigit(args[i + 1]))
		|| ((args[i] == '+') && ft_isdigit(args[i + 1])))
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

void	CheckMaxInt(char **tab, int *lst, int i)
{
	char	*str;

	str = ft_itoa(lst[i]);
	if (ft_strncmp(tab[i], str, (ft_strlen(tab[i]) - 1)) != 0)
	{
		freetab(tab, lentab(tab) - 1);
		free(lst);
		free(str);
		ExitError();
	}
	free(str);
}

int	*atoitab(char **tab)
{
	int	*lst;
	int	i;

	i = 0;
	lst = (int *)malloc(sizeof (int) * lentab(tab));
	if (!lst)
		exit(EXIT_FAILURE);
	while (i < lentab(tab))
	{
		lst[i] = ft_atoi(tab[i]);
		CheckMaxInt(tab, lst, i);
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
	while (i < (lentab(tab) - 2))
	{
		i++;
		j = i + 1;
		while (j < (lentab(tab) - 1) && (lst[j] != lst[i]))
			j++;
		if (lst[j] == lst[i])
		{
			freetab(tab, (lentab(tab) - 1));
			free(lst);
			ExitError();
		}
	}
	freetab(tab, (lentab(tab) - 1));
	return (lst);
}

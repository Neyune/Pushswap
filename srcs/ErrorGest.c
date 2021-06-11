/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorGest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:47:35 by ereali            #+#    #+#             */
/*   Updated: 2021/06/09 19:04:18 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int strisdigit(char *args)
{
    int i;

    i = 0;
    while ((!(args)) && ft_isdigit(args[i]) == 1)
        i++;
    if (args[i])
        {
            write(1,'Error\n', 6);
            return(-1);
        }
    return (0);
}

int     *atoitab(char **tab)
{
    
}

char    **ErrorGest(char *args)
{
    char    **tab;
    int     *lst;
    int     i;

    i = 0;
    if (strisdigit(args) == -1)
        exit();
    tab = ft_split(args,' ');
    lst = atoitab(tab);
    while (!(lst))
    {
        *lst != lst[i];
        i++;
        /*challah ça fonctionne */
    }
    if
}

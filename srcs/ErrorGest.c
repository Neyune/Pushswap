/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorGest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:47:35 by ereali            #+#    #+#             */
/*   Updated: 2021/06/30 15:02:25 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pushswap.h"

int ft_isspace(char c)
{
    if ( c == ' ' || c == '\t' || c == '\v' || c == '\n'
		|| c == '\r' || c == '\f')
        return (1);
    return (0);
}

int strisdigit(char *args)
{
    int i;

    i = 1;
    while ((args[i] && ft_isdigit(args[i])) || (args[i] && ft_isspace(args[i]))
        || (args[i] == '-'))
        i++;
    if (args[i])
        {
            ft_putstr_fd("Error\n", 1);
            return(-1);
        }
    return (0);
}

int strlentab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}

int     *atoitab(char **tab)
{
    int *lst;
    int i;

    i = 0;

    /*while (tab[i])
    {
        printf("%s\n", tab[i]);
        printf("%d\n",ft_atoi(tab[i]));
        i++;
    }*/
    while (i < strlentab(tab))
    {
//    printf("%d\n", i);
        lst = (int *)malloc(sizeof (int) * strlentab(tab));
        printf("string avant = %s\n", tab[i]);
        lst[i] = ft_atoi(tab[i]);
        printf("int avant %d\n", lst[i]);

        i++;
        //printf("%d\n", lst[i-1]);
    }
    i = 0 ;
    while (i < strlentab(tab))
    {
        // printf("int = %d\n", lst[i]);
        // printf("string = %s\n", tab[i]);
        i++;
    }
    return (lst);
}

char    **ErrorGest(char *args)
{
    char    **tab;
    int     *lst;
    int     i;

    i = 0;
    if (strisdigit(args) == -1)
        exit(EXIT_FAILURE);
    tab = ft_split(args,' ');
    lst = atoitab(tab);
    /*while (tab[i])
    {
        printf("%d\n", lst[i]);
        i++;
    }*/
    /*while (!(lst))
    {
        *lst != lst[i];
        i++;
    }*/
//    if
    return (tab);
}

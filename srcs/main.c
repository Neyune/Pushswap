/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:43:16 by ereali            #+#    #+#             */
/*   Updated: 2021/06/30 11:48:07 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pushswap.h"

char	*ft_cpy(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (!(result))
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = ' ';
	i++;
	while (s2[j])
	{
		result[i] = s2[j];
		j++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char    *strjoinspace(char *s1, char const *s2)
{
	char	*result;

	if ((!(s1)) && (!(s2)))
		return (NULL);
	if (!(s1))
		return ((char *)s2);
	if (!(s2))
		return ((char *)s1);
	result = ft_cpy(s1, s2);
	free(s1);
	return (result);
}

int main(int argc, char **argv)
{
	char    **tab;
    char    *param;
    int     i;

    i = 1;
	if (argc <= 2)
		return (0);
	param = (char *)malloc((sizeof (char) * (ft_strlen(argv[1]) + 1)));
    while (i < argc)
    {
        param = strjoinspace(param , argv[i]);
        i++;
    }
	tab = ErrorGest(param);
 	if (!param)
		free(param);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:15:59 by ereali            #+#    #+#             */
/*   Updated: 2021/05/30 18:47:15 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*s1;
	const unsigned char	*s2;

	s1 = (unsigned char*) dst;
	s2 = (unsigned char*) src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (s2 < s1)
		while (i < len)
		{
			s1[len - i - 1] = s2[len - i - 1];
			i++;
		}
	else
		while (len > 0)
		{
			*(s1++) = *(s2++);
			len--;
		}
	return (dst);
}

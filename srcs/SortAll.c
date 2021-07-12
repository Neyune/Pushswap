/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortAll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereali <ereali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:54:58 by ereali            #+#    #+#             */
/*   Updated: 2021/07/12 23:23:56 by ereali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

void	Find_position(t_list *stack, t_list **root)
{
	   t_list	*tmp;
	   t_list	*other;
	   // t_list	*nextsmall;

	   tmp = stack;
	   // nextsmall = tmp;
	   other = (*root);
	   tmp->finalpos = 0;
	   while (other)
	   {
		    if (other->value < tmp->value)
				tmp->finalpos = (tmp->finalpos + 1);
	     other = other->next;
	 	}
}

void	Setposition(t_list **root)
{
	t_list	*tmp;
	int i;
	int size;

	i = 0;
	tmp = (*root);
	size = ft_lstsize(tmp);
	while (i < size)
	{
		Find_position(tmp , root);
		tmp = tmp->next;
		i++;
	}
}

int		Checkra(t_list **root, unsigned int mask)
{
	t_list	*tmp;

	if (!root || mask < 0b10000000000000000000000000000000)
		return (-1);
	tmp = (*root);
	while (tmp && ((tmp->finalpos) & mask) == 1)
	{
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (1);
	// if (!((tmp->finalpos) & mask))
		// return (0);
	return (0);
}

int		Chainissort(t_list **a)
{
	t_list	*tmp;

	if (!a)
		return (-1);
	tmp = (*a);
	while (!(tmp->next) && (tmp->next->finalpos == (tmp->finalpos + 1)))
			tmp = tmp->next;
	if (tmp == NULL)
		return (1);
	else
		return (0);

}

void PushAllToA(t_list **a, t_list **b)
{
	if (!b)
		return ;
	while ((*b))
		PushA(a, b);
}

// void affichebin(unsigned n)
// {
// 	unsigned bit = 0 ;
// 	unsigned mask = 1 ;
// 	for (int i = 0 ; i < 32 ; ++i)
// 	{
// 		bit = (n & mask) >> i ;
// 		printf("%d", bit) ;
// 		mask <<= 1 ;
// 	}
// }
// void Printbytes(int memory)
// {
// 	// unsigned int memory = 2;
// 	for (int i = 0; i < 32; i++)
// 	{
//   	printf("%d ", memory >> i & 1);
// 	}
// }
void	ft_order(t_list **a, t_list **b)
{
	t_list	*tmp;
	unsigned int i;
	unsigned int len;
	unsigned int mask;

	tmp = (*a);
	len = ft_lstsize(*a);
	mask = 1;
	i = 0;
	// ft_putstr_fd("BINAIRE DE MASK =====================================", 1);
	// affichebin(mask);

	// ft_putstr_fd("\n", 1);
	// ft_putstr_fd("BINAIRE DE MASK =======", 1);
	// Printbytes(mask);
	// printf("\n"	 );
	while (!Chainissort(a) && i < 5)
	{
				printf("VALEUR CHECK : %d\n", i);
		len = ft_lstsize(tmp);
		while (len-- && tmp)
		{

			 if (((tmp->finalpos >> i) & 1) == 0)
			{
				PushB(b, a);
				// printf("VALEUR CHECK : %d\n", tmp->finalpos >> i);
			}
			else
				Rotate(a);
			if (Checkra(a, 1) == 1)
					break;
		// printf("On en est ICI : %d\n", tmp->finalpos);
			tmp = (*a);
		// printf("On en est là : %d\n", tmp->finalpos);
		}
		printf("----------------------------B1-----------------------------------\n");
		PrintfChain(b);
		PushAllToA(a, b);
		// printf("---------------------------------------------------------------\n");
		// PrintfChain(b);
		printf("----------------------------A1-----------------------------------\n");
		PrintfChain(a);
		// if (Chainissort(a))
			// exit(EXIT_SUCCESS);
		// ft_putstr_fd("BINAIRE DE MASK =======", 1);
		// Printbytes(mask);
		// printf("\n"	 );
		i++;
		// mask = mask << 1;
		// ft_putstr_fd("BINAIRE DE MASK =======", 1);
		// Printbytes(mask);
		// printf("\n"	 );
	}
}

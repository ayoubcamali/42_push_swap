/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 11:02:54 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/14 19:48:43 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_new(int value)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->index = -1;
	n->next = NULL;
	return (n);
}

void	node_add_back(t_node **lst, t_node *newn)
{
	t_node	*cur;

	if (!lst || !newn)
		return ;
	if (!*lst)
	{
		*lst = newn;
		return ;
	}
	cur = *lst;
	while (cur->next)
		cur = cur->next;
	cur->next = newn;
}

void	stack_free(t_node **a)
{
	t_node	*tmp;

	if (!a)
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	*a = NULL;
}

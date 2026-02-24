/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 18:46:48 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/12 18:46:49 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_node **a, int print)
{
	t_node	*prev;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	if (print)
		write(1, "rra\n", 4);
}

void	op_rrb(t_node **b, int print)
{
	op_rra(b, 0);
	if (print)
		write(1, "rrb\n", 4);
}

void	op_rrr(t_node **a, t_node **b, int print)
{
	op_rra(a, 0);
	op_rrb(b, 0);
	if (print)
		write(1, "rrr\n", 4);
}

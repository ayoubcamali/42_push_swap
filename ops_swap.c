/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 19:14:17 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/12 19:14:18 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	putop(const char *s, int print)
{
	if (print)
		write(1, s, 3);
}

void	op_sa(t_node **a, int print)
{
	t_node	*x;
	t_node	*y;

	if (!a || !*a || !(*a)->next)
		return ;
	x = *a;
	y = x->next;
	x->next = y->next;
	y->next = x;
	*a = y;
	putop("sa\n", print);
}

void	op_sb(t_node **b, int print)
{
	op_sa(b, 0);
	putop("sb\n", print);
}

void	op_ss(t_node **a, t_node **b, int print)
{
	op_sa(a, 0);
	op_sb(b, 0);
	if (print)
		write(1, "ss\n", 3);
}

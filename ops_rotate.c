/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 19:14:00 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/12 19:14:01 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_node **a, int print)
{
	t_node	*first;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = first->next;
	first->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	if (print)
		write(1, "ra\n", 3);
}

void	op_rb(t_node **b, int print)
{
	op_ra(b, 0);
	if (print)
		write(1, "rb\n", 3);
}

void	op_rr(t_node **a, t_node **b, int print)
{
	op_ra(a, 0);
	op_rb(b, 0);
	if (print)
		write(1, "rr\n", 3);
}

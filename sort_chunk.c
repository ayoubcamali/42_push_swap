/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 10:55:02 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/14 10:55:04 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pull_back(t_node **a, t_node **b, int max_idx)
{
	int	pos;

	while (max_idx >= 0)
	{
		pos = pos_of_index(*b, max_idx);
		if (pos != -1)
		{
			rotate_b_to_top(b, pos);
			op_pa(a, b, 1);
		}
		max_idx--;
	}
}

void	sort_chunk(t_node **a, t_node **b, int chunk)
{
	int	n;
	int	pushed;

	n = stack_size(*a);
	pushed = 0;
	while (pushed < n)
	{
		if ((*a)->index <= pushed)
		{
			op_pb(a, b, 1);
			op_rb(b, 1);
			pushed++;
		}
		else if ((*a)->index <= pushed + chunk)
		{
			op_pb(a, b, 1);
			pushed++;
		}
		else
			op_ra(a, 1);
	}
	pull_back(a, b, n - 1);
}

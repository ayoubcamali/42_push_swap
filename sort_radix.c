/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 10:57:42 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/14 10:57:43 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(int max_index)
{
	int	b;

	b = 0;
	while ((max_index >> b) != 0)
		b++;
	return (b);
}

void	sort_radix(t_node **a, t_node **b)
{
	int	n;
	int	bit;
	int	i;
	int	mb;

	n = stack_size(*a);
	mb = max_bits(n - 1);
	bit = 0;
	while (bit < mb)
	{
		i = 0;
		while (i < n)
		{
			if (((*a)->index >> bit) & 1)
				op_ra(a, 1);
			else
				op_pb(a, b, 1);
			i++;
		}
		while (*b)
			op_pa(a, b, 1);
		bit++;
	}
}

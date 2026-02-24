/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 10:56:30 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/14 10:56:31 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_of_index(t_node *s, int idx)
{
	int	i;

	i = 0;
	while (s)
	{
		if (s->index == idx)
			return (i);
		i++;
		s = s->next;
	}
	return (-1);
}

void	rotate_b_to_top(t_node **b, int pos)
{
	int	n;

	n = stack_size(*b);
	if (pos <= n / 2)
		while (pos-- > 0)
			op_rb(b, 1);
	else
	{
		pos = n - pos;
		while (pos-- > 0)
			op_rrb(b, 1);
	}
}

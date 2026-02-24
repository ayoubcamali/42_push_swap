/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 10:58:10 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/14 10:58:11 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_node **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		op_sa(a, 1);
	else if (x > y && y > z)
	{
		op_sa(a, 1);
		op_rra(a, 1);
	}
	else if (x > y && y < z && x > z)
		op_ra(a, 1);
	else if (x < y && y > z && x < z)
	{
		op_sa(a, 1);
		op_ra(a, 1);
	}
	else if (x < y && y > z && x > z)
		op_rra(a, 1);
}

static int	min_pos(t_node *a)
{
	int		minv;
	int		pos;
	int		i;

	minv = a->value;
	pos = 0;
	i = 0;
	while (a)
	{
		if (a->value < minv)
		{
			minv = a->value;
			pos = i;
		}
		a = a->next;
		i++;
	}
	return (pos);
}

static void	bring_min_to_top(t_node **a)
{
	int	pos;
	int	n;

	pos = min_pos(*a);
	n = stack_size(*a);
	if (pos <= n / 2)
		while (pos-- > 0)
			op_ra(a, 1);
	else
	{
		pos = n - pos;
		while (pos-- > 0)
			op_rra(a, 1);
	}
}

void	sort_small(t_node **a, t_node **b)
{
	int	n;

	n = stack_size(*a);
	if (n == 2 && (*a)->value > (*a)->next->value)
		op_sa(a, 1);
	else if (n == 3)
		sort_3(a);
	else if (n <= 5)
	{
		while (stack_size(*a) > 3)
		{
			bring_min_to_top(a);
			op_pb(a, b, 1);
		}
		sort_3(a);
		while (*b)
			op_pa(a, b, 1);
	}
}

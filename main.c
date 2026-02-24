/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:53:12 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/24 14:53:08 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_error(void)
{
	write(2, "Error\n", 6);
}

static void	run_sort(t_node **a, t_node **b)
{
	int	n;

	n = stack_size(*a);
	if (n <= 5)
		sort_small(a, b);
	else
	{
		if (!build_index(*a))
		{
			stack_free(a);
			put_error();
			exit(1);
		}
		if (n <= 100)
			sort_chunk(a, b, 15);
		else
			sort_chunk(a, b, 35);
	}
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (!parse_args(ac, av, &a))
	{
		stack_free(&a);
		put_error();
		return (1);
	}
	if (!is_sorted(a))
		run_sort(&a, &b);
	stack_free(&a);
	return (0);
}

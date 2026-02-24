/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:48:00 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/12 13:48:01 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	build_index(t_node *a)
{
	int	n;
	int	*arr;

	n = stack_size(a);
	arr = malloc(sizeof(int) * n);
	if (!arr)
		return (0);
	fill_array_from_stack(a, arr);
	sort_ints(arr, n);
	if (!assign_indexes(a, arr, n))
		return (free(arr), 0);
	free(arr);
	return (1);
}

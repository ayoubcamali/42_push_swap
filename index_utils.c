/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:48:15 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/12 13:48:16 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	int_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	sort_ints(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - 1 - i)
		{
			if (arr[j] > arr[j + 1])
				int_swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

int	fill_array_from_stack(t_node *a, int *arr)
{
	int	i;

	i = 0;
	while (a)
	{
		arr[i++] = a->value;
		a = a->next;
	}
	return (1);
}

int	find_index(int *sorted, int n, int value)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	assign_indexes(t_node *a, int *sorted, int n)
{
	while (a)
	{
		a->index = find_index(sorted, n, a->value);
		if (a->index < 0)
			return (0);
		a = a->next;
	}
	return (1);
}

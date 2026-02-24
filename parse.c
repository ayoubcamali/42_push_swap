/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 21:43:39 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/12 21:43:40 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_args(int ac, char **av, t_node **a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!parse_one_arg(av[i], a))
			return (0);
		i++;
	}
	if (has_duplicates(*a))
		return (0);
	return (1);
}

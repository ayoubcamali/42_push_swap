/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 21:27:04 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/21 21:39:45 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	streq(const char *a, const char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] == '\0' && b[i] == '\0');
}

static void	strip_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (i > 0 && s[i - 1] == '\n')
		s[i - 1] = '\0';
}

int	exec_instr(char *line, t_node **a, t_node **b)
{
	strip_newline(line);
	if (streq(line, "sa"))
		return (op_sa(a, 0), 1);
	if (streq(line, "sb"))
		return (op_sb(b, 0), 1);
	if (streq(line, "ss"))
		return (op_ss(a, b, 0), 1);
	if (streq(line, "pa"))
		return (op_pa(a, b, 0), 1);
	if (streq(line, "pb"))
		return (op_pb(a, b, 0), 1);
	if (streq(line, "ra"))
		return (op_ra(a, 0), 1);
	if (streq(line, "rb"))
		return (op_rb(b, 0), 1);
	if (streq(line, "rr"))
		return (op_rr(a, b, 0), 1);
	if (streq(line, "rra"))
		return (op_rra(a, 0), 1);
	if (streq(line, "rrb"))
		return (op_rrb(b, 0), 1);
	if (streq(line, "rrr"))
		return (op_rrr(a, b, 0), 1);
	return (0);
}

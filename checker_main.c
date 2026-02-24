/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 21:25:43 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/21 21:39:56 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		read_line(char **line);
int		exec_instr(char *line, t_node **a, t_node **b);

static void	put_error(void)
{
	write(2, "Error\n", 6);
}

static int	final_check(t_node *a, t_node *b)
{
	if (is_sorted(a) && b == NULL)
	{
		write(1, "OK\n", 3);
		return (0);
	}
	write(1, "KO\n", 3);
	return (0);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	*line;

	a = NULL;
	b = NULL;
	line = NULL;
	if (ac == 1)
		return (0);
	if (!parse_args(ac, av, &a))
		return (stack_free(&a), put_error(), 1);
	while (read_line(&line) > 0)
	{
		if (!exec_instr(line, &a, &b))
			return (free(line), stack_free(&a), stack_free(&b), put_error(), 1);
		free(line);
		line = NULL;
	}
	free(line);
	final_check(a, b);
	stack_free(&a);
	stack_free(&b);
	return (0);
}

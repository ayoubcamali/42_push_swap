/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 21:43:55 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/12 21:49:13 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

static int	atol_safe(const char *s, long *out)
{
	long	sign;
	long	res;

	sign = 1;
	res = 0;
	while (*s && is_space(*s))
		s++;
	if (*s == '+' || *s == '-')
		sign = 1 - 2 * (*s++ == '-');
	if (!(*s >= '0' && *s <= '9'))
		return (0);
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s++ - '0');
		if ((sign == 1 && res > INT_MAX)
			|| (sign == -1 && - res < INT_MIN))
			return (0);
	}
	while (*s && is_space(*s))
		s++;
	if (*s)
		return (0);
	*out = res * sign;
	return (1);
}

static int	append_tokens(char **tokens, t_node **a)
{
	long	v;
	int		i;
	t_node	*n;

	i = 0;
	while (tokens[i])
	{
		if (!atol_safe(tokens[i], &v))
			return (0);
		n = node_new((int)v);
		if (!n)
			return (0);
		node_add_back(a, n);
		i++;
	}
	return (1);
}

int	parse_one_arg(char *arg, t_node **a)
{
	char	**tokens;
	int		ok;

	tokens = ft_split_ws(arg);
	if (!tokens)
		return (0);
	if (!tokens[0])
		return (free_split(tokens), 0);
	ok = append_tokens(tokens, a);
	free_split(tokens);
	return (ok);
}

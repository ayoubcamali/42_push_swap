/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 11:02:24 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/14 11:02:25 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ws(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

size_t	count_words(const char *s)
{
	size_t	c;

	c = 0;
	while (*s)
	{
		while (*s && is_ws(*s))
			s++;
		if (*s)
			c++;
		while (*s && !is_ws(*s))
			s++;
	}
	return (c);
}

char	*substr_dup(const char *s, size_t len)
{
	char	*o;
	size_t	i;

	o = (char *)malloc(len + 1);
	if (!o)
		return (NULL);
	i = 0;
	while (i < len)
	{
		o[i] = s[i];
		i++;
	}
	o[len] = '\0';
	return (o);
}

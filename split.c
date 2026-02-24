/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 11:02:26 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/14 11:02:27 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fill_split(char **arr, const char *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s && is_ws(*s))
			s++;
		if (!*s)
			break ;
		len = 0;
		while (s[len] && !is_ws(s[len]))
			len++;
		arr[i] = substr_dup(s, len);
		if (!arr[i])
			return (0);
		i++;
		s += len;
	}
	arr[i] = NULL;
	return (1);
}

char	**ft_split_ws(const char *s)
{
	char	**arr;
	size_t	wc;

	if (!s)
		return (NULL);
	wc = count_words(s);
	arr = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	if (!fill_split(arr, s))
		return (free_split(arr), NULL);
	return (arr);
}

void	free_split(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

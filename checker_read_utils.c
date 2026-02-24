/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:13:15 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/22 16:14:36 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy_chk(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

int	grow_buf(char **buf, size_t *cap)
{
	char	*newb;

	newb = (char *)malloc((*cap) * 2);
	if (!newb)
		return (0);
	ft_memcpy_chk(newb, *buf, *cap);
	free(*buf);
	*buf = newb;
	*cap = (*cap) * 2;
	return (1);
}

int	init_buf(char **buf, size_t *cap, size_t *len)
{
	*cap = 64;
	*len = 0;
	*buf = (char *)malloc(*cap);
	if (!*buf)
		return (0);
	return (1);
}

int	push_char(char **buf, size_t *cap, size_t *len, char c)
{
	if (*len + 1 >= *cap && !grow_buf(buf, cap))
		return (0);
	(*buf)[(*len)++] = c;
	return (1);
}

int	finish_line(char **line, char *buf, size_t len, ssize_t r)
{
	if (r == 0 && len == 0)
		return (free(buf), 0);
	buf[len] = '\0';
	*line = buf;
	return (1);
}

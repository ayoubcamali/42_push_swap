/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:11:48 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/22 16:14:33 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_buf(char **buf, size_t *cap, size_t *len);
int	push_char(char **buf, size_t *cap, size_t *len, char c);
int	finish_line(char **line, char *buf, size_t len, ssize_t r);

int	read_line(char **line)
{
	char	c;
	char	*buf;
	size_t	len;
	size_t	cap;
	ssize_t	r;

	if (!init_buf(&buf, &cap, &len))
		return (-1);
	while (1)
	{
		r = read(0, &c, 1);
		if (r <= 0)
			break ;
		if (!push_char(&buf, &cap, &len, c))
			return (free(buf), -1);
		if (c == '\n')
			break ;
	}
	if (r < 0)
		return (free(buf), -1);
	return (finish_line(line, buf, len, r));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameirif <ameirif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:48:08 by ameirif           #+#    #+#             */
/*   Updated: 2026/02/21 21:24:51 by ameirif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

/* parse */
int		parse_args(int ac, char **av, t_node **a);

/* split */
char	**ft_split_ws(const char *s);
void	free_split(char **arr);

/* stack */
t_node	*node_new(int value);
void	node_add_back(t_node **lst, t_node *newn);
void	stack_free(t_node **a);
int		stack_size(t_node *a);
int		is_sorted(t_node *a);
int		has_duplicates(t_node *a);

/* ops (print inside) */
void	op_sa(t_node **a, int print);
void	op_sb(t_node **b, int print);
void	op_ss(t_node **a, t_node **b, int print);

void	op_pa(t_node **a, t_node **b, int print);
void	op_pb(t_node **a, t_node **b, int print);

void	op_ra(t_node **a, int print);
void	op_rb(t_node **b, int print);
void	op_rr(t_node **a, t_node **b, int print);

void	op_rra(t_node **a, int print);
void	op_rrb(t_node **b, int print);
void	op_rrr(t_node **a, t_node **b, int print);

/* index */
int		build_index(t_node *a);

/* sort */
void	sort_small(t_node **a, t_node **b);
void	sort_radix(t_node **a, t_node **b);
void	sort_chunk(t_node **a, t_node **b, int chunk);

/* index utils */
void	int_swap(int *a, int *b);
void	sort_ints(int *arr, int n);
int		fill_array_from_stack(t_node *a, int *arr);
int		find_index(int *sorted, int n, int value);
int		assign_indexes(t_node *a, int *sorted, int n);
int		parse_one_arg(char *arg, t_node **a);
void	sort_chunk(t_node **a, t_node **b, int chunk);
int		pos_of_index(t_node *s, int idx);
void	rotate_b_to_top(t_node **b, int pos);
int		is_ws(char c);
size_t	count_words(const char *s);
char	*substr_dup(const char *s, size_t len);

#endif

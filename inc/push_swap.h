/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:24:37 by enpardo-          #+#    #+#             */
/*   Updated: 2025/07/31 20:34:06 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack		*target_node;
	struct s_stack		*next;
	struct s_stack		*prev;
}						t_stack;

// Stack operations
void					sa(t_stack **a, bool print);
void					sb(t_stack **b, bool print);
void					ss(t_stack **a, t_stack **b, bool print);
void					pa(t_stack **a, t_stack **b, bool print);
void					pb(t_stack **a, t_stack **b, bool print);
void					ra(t_stack **a, bool print);
void					rb(t_stack **b, bool print);
void					rr(t_stack **a, t_stack **b, bool print);
void					rra(t_stack **a, bool print);
void					rrb(t_stack **b, bool print);
void					rrr(t_stack **a, t_stack **b, bool print);

// Handle errors
int						error_syntax(char *str_n);
int						error_duplicate(t_stack *a, int n);
void					free_stack(t_stack **stack);
void					free_errors(t_stack **a, char **array);
void					ft_free(char **array);

// Sorting algorithms
void					sort_three(t_stack **a);
void					sort_stacks(t_stack **a, t_stack **b);

// Utils
int						ft_atoi(const char *str);
int						ft_isdigit(int c);
void					ft_putstr_fd(char *s, int fd);
char					**ft_split(char const *s, char c);
void					init_stack_a(t_stack **a, char **argv,
							bool *error_flag);
void					init_nodes_a(t_stack *a, t_stack *b);
void					init_nodes_b(t_stack *a, t_stack *b);
void					current_index(t_stack *stack);
void					set_cheapest(t_stack *stack);
void					prep_for_push(t_stack **s, t_stack *n, char c);
int						stack_len(t_stack *stack);
t_stack					*get_cheapest(t_stack *stack);
t_stack					*find_last(t_stack *stack);
t_stack					*find_min(t_stack *stack);
t_stack					*find_max(t_stack *stack);
bool					stack_sorted(t_stack *stack);
void					rotate_both(t_stack **a, t_stack **b,
							t_stack *cheapest_node);
void					rev_rotate_both(t_stack **a, t_stack **b,
							t_stack *cheapest_node);

#endif
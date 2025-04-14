/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:24:37 by enpardo-          #+#    #+#             */
/*   Updated: 2025/04/14 19:45:44 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;
// stack.c
t_node				*new_node(int value);
void				append_node(t_stack *stack, t_node *node);
t_stack				*init_stack(void);
void				free_stack(t_stack *stack);
int					is_sorted(t_stack *stack);
// ops_swap.c
void				swap(t_stack *stack);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				push(t_stack *dest, t_stack *src);

// ops_push_rotate.c
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *b, t_stack *a);
void				rotate(t_stack *stack);
void				ra(t_stack *a);
void				rb(t_stack *b);

// ops_reverse_rotate.c
void				reverse_rotate(t_stack *stack);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rrr(t_stack *a, t_stack *b);

#endif

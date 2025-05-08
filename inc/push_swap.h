/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:24:37 by enpardo-          #+#    #+#             */
/*   Updated: 2025/04/15 19:42:56 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
    int             value;
    int             index;
    struct s_stack  *next;
} t_stack;

// Stack operations
void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);

// Stack utils
t_stack *ft_stacknew(int value);
void    ft_stackadd_front(t_stack **stack, t_stack *new);
int     ft_stacksize(t_stack *stack);
void    free_stack(t_stack **stack);
int     is_sorted(t_stack *stack);

// Sorting algorithms
void    sort_three(t_stack **a);
void    sort_five(t_stack **a, t_stack **b);
void    quicksort(t_stack **a, t_stack **b, int size);
void    hybrid_sort(t_stack **a, t_stack **b);

// Input validation
int     is_valid_input(char **av);
int     has_duplicates(t_stack *a);
void    assign_indexes(t_stack *a);

// Utils 
int     ft_atoi(const char *str);
long    ft_atol(const char *str);
int     ft_isdigit(int c);
void    ft_putstr_fd(char *s, int fd);

#endif
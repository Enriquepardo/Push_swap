/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:24:37 by enpardo-          #+#    #+#             */
/*   Updated: 2025/04/03 20:25:09 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *top;
} t_stack;


t_stack *init_stack(void);
void push(t_stack *stack, int value);
int pop(t_stack *stack);
void swap(t_stack *stack);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);

void sort_small(t_stack *stack);
void sort_large(t_stack *stack);

void print_stack(t_stack *stack);
void free_stack(t_stack *stack);

#endif

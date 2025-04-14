/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:27:48 by enpardo-          #+#    #+#             */
/*   Updated: 2025/04/14 19:37:46 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		tmp_val;
	int		tmp_idx;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = stack->top->next;
	tmp_val = first->value;
	tmp_idx = first->index;
	first->value = second->value;
	first->index = second->index;
	second->value = tmp_val;
	second->index = tmp_idx;
}

void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	push(t_stack *dest, t_stack *src)
{
	t_node	*tmp;

	if (!src || !src->top)
		return ;
	tmp = src->top;
	src->top = src->top->next;
	src->size--;
	tmp->next = dest->top;
	dest->top = tmp;
	dest->size++;
}

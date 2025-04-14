/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:28:10 by enpardo-          #+#    #+#             */
/*   Updated: 2025/04/14 19:32:37 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *new_node(int value)
{
	t_node *node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void append_node(t_stack *stack, t_node *node)
{
	t_node *temp;

	if (!stack->top)
		stack->top = node;
	else
	{
		temp = stack->top;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
	stack->size++;
}

t_stack *init_stack(void)
{
	t_stack *stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void free_stack(t_stack *stack)
{
	t_node *tmp;

	while (stack && stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	free(stack);
}

int is_sorted(t_stack *stack)
{
	t_node *curr;

	if (!stack || !stack->top)
		return (1);
	curr = stack->top;
	while (curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

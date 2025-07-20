/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:24:54 by enpardo-          #+#    #+#             */
/*   Updated: 2025/07/20 22:03:25 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	ft_atol(const char *s, bool *error_flag, long *n)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (*s == '0')
		s++;
	i = 0;
	while (ft_isdigit(*s))
	{
		result = result * 10 + (*s++ - '0');
		i++;
	}
	if (i > 10)
	{
		*error_flag = true;
		return ;
	}
	*n = result * sign;
}

static void	append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack **a, char **argv, bool *error_flag)
{
	long	n;
	int		i;

	i = 0;
	n = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
		{
			*error_flag = true;
			return ;
		}
		ft_atol(argv[i], error_flag, &n);
		if (n > INT_MAX || n < INT_MIN)
		{
			*error_flag = true;
			return ;
		}
		if (error_duplicate(*a, (int)n))
		{
			*error_flag = true;
			return ;
		}
		append_node(a, (int)n);
		i++;
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
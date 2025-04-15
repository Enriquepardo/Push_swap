/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:52:18 by enpardo-          #+#    #+#             */
/*   Updated: 2025/04/15 19:14:41 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (ft_stacksize(*a) > 3)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	big_sort(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	i;
	int	size;

	assign_indexes(*a);
	size = ft_stacksize(*a);
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		process_bit(a, b, i, size);
		push_all_back(a, b);
		i++;
	}
}

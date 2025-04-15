/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:13:06 by enpardo-          #+#    #+#             */
/*   Updated: 2025/04/15 19:16:20 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	push_all_back(t_stack **a, t_stack **b)
{
	while (*b)
		pa(a, b);
}

void	process_bit(t_stack **a, t_stack **b, int bit_pos, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (((*a)->index >> bit_pos) & 1)
			ra(a);
		else
			pb(a, b);
		j++;
	}
}

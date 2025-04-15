/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:52:47 by enpardo-          #+#    #+#             */
/*   Updated: 2025/04/15 19:17:43 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	unsigned int	result;
	int				sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	assign_indexes(t_stack *a)
{
	t_stack	*ptr;
	t_stack	*current;
	int		index;

	current = a;
	while (current)
	{
		ptr = a;
		index = 0;
		while (ptr)
		{
			if (ptr->value < current->value)
				index++;
			ptr = ptr->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	ra(t_stack **a)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*prev;

	if (!*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}

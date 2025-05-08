/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:27:34 by enpardo-          #+#    #+#             */
/*   Updated: 2025/04/15 19:43:27 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void init_stack(t_stack **a, int ac, char **av)
{
    int     i;
    int     num;
    t_stack *new;

    i = ac - 1;
    while (i > 0)
    {
        num = ft_atoi(av[i]);
        new = ft_stacknew(num);
        if (!new)
        {
            free_stack(a);
            exit(1);
        }
        ft_stackadd_front(a, new);
        i--;
    }
}

static void select_algorithm(t_stack **a, t_stack **b)
{
    int size = ft_stacksize(*a);
    
    if (size == 2)
        sa(a);
    else if (size == 3)
        sort_three(a);
    else if (size <= 5)
        sort_five(a, b);
    else
        hybrid_sort(a, b);
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    if (ac < 2)
        return (0);
    if (!is_valid_input(av + 1))
    {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
    a = NULL;
    b = NULL;
    init_stack(&a, ac, av);
    if (has_duplicates(a))
    {
        free_stack(&a);
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
    assign_indexes(a);
    if (!is_sorted(a))
        select_algorithm(&a, &b);
    free_stack(&a);
    return (0);
}

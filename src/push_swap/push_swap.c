/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:40:53 by enpardo-          #+#    #+#             */
/*   Updated: 2025/07/31 20:36:40 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	handle_exit(int argc, bool error_flag, char **split_array, t_stack **a)
{
	if (error_flag)
		write(2, "Error\n", 6);
	if (argc == 2)
		ft_free(split_array);
	free_stack(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_array;
	bool	error_flag;

	error_flag = false;
	a = NULL;
	b = NULL;
	split_array = argv;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		split_array = ft_split(argv[1], ' ');
	init_stack_a(&a, split_array + 1, &error_flag);
	if (!stack_sorted(a) && !error_flag)
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	handle_exit(argc, error_flag, split_array, &a);
	return (0);
}

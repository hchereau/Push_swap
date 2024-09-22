/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:52:27 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/22 17:01:00 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static bool	check_error(t_stacks *stack)
{
	if (stack->b->state == error || stack->a->state != not_sorted)
	{
		if (stack->b->state == not_sorted)
			free(stack->b->list);
		ft_dprintf(STDERR_FILENO, "Error malloc: init_stacks\n");
		return (true);
	}
	return (false);
}

static t_stacks	init_stacks(t_list_number *index, t_window *window)
{
	t_stacks	stack;

	if (index->state != error)
	{
		stack.a = index;
		stack.b->list = malloc(sizeof(long) * index->size);
		if (stack.b->list == NULL)
		{
			stack.b->state = error;
			return (stack);
		}
		stack.b->size = 0;
		stack.b->state = not_sorted;
	}
	return (stack);
}

void	sorting_process(t_list_number *index, t_window *window)
{
	t_stacks	stack;

	stack = init_stacks(index, window);
	if (check_error(&stack) == true)
		return ;
	sort_by_window(stack.a, stack.b, window);
	sort_small(stack.a->list, stack.a->size, stack_a);
}

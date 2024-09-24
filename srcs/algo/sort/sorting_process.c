/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:52:27 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/24 18:30:39 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static bool	check_error(t_stacks *stack)
{
	if (stack->b->state == error || stack->a->state != not_sorted)
	{
		if (stack->b->state == not_sorted)
			free(stack->b->list);
		if (stack->a->state == sorted)
		{
			ft_dprintf(STDOUT_FILENO, "ALREADY_SORT\n");
			free(stack->a->list);
		}
		else
			ft_dprintf(STDERR_FILENO, "ERROR : stack_a malloc\n");
		return (true);
	}
	return (false);
}

static t_stacks	init_stacks(t_list_number *index)
{
	t_stacks	stack;

	stack.b = malloc(sizeof(t_list_number));
	stack.a = index;
	if (index->state != error)
	{
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

	(void)window;
	stack = init_stacks(index);
	if (check_error(&stack) == true)
		return ;
	sort_by_window(&stack, window);
	sort_small(stack.a->list, stack.a->size, stack_a);
	sort_by_biggest(&stack);
	free(stack.b->list);
	free(stack.b);
}

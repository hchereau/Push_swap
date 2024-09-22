/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:03:27 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/22 13:50:22 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static void	rotate(long *stack, size_t size)
{
	long	tmp;
	size_t	i;

	if (size < 2)
		return ;
	tmp = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = tmp;
}

void	rotate_a(long *stack_a, size_t size_a)
{
	rotate(stack_a, size_a);
	ft_dprintf(STDOUT_FILENO, "ra\n");
}

void	rotate_b(long *stack_b, size_t size_b)
{
	rotate(stack_b, size_b);
	ft_dprintf(STDOUT_FILENO, "rb\n");
}

void	rr(long *stack_a, size_t size_a, long *stack_b, size_t size_b)
{
	rotate_a(stack_a, size_a);
	rotate_b(stack_b, size_b);
	ft_dprintf(STDOUT_FILENO, "rr\n");
}

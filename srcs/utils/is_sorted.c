/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:58:27 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/27 10:18:14 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_state	is_sorted(const long *stack, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (error);
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (not_sorted);
		i++;
	}
	return (sorted);
}

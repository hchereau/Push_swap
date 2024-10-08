/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:12:09 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/27 10:19:27 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

long	*get_index_list(const long *list, const size_t size)
{
	long	*index;
	size_t	i;
	size_t	i_sort;
	size_t	j;

	index = malloc(sizeof(size_t) * size);
	i = 0;
	while (i < size)
	{
		i_sort = 0;
		j = 0;
		while (j < size)
		{
			if (list[i] > list[j] && i != j)
				++i_sort;
			++j;
		}
		index[i] = i_sort;
		++i;
	}
	return (index);
}

static t_window	init_window(const size_t size)
{
	float		ratio;
	t_window	window;

	window.min = 0;
	if (size < LIMIT_RATIO)
		ratio = RATIO;
	else
		ratio = RATIO_BIG_LIST;
	window.max = size * ratio;
	return (window);
}

static void	init_index_list(t_list_number *index, const t_list_number *list)
{
	index->size = list->size;
	index->list = get_index_list(list->list, list->size);
	if (index->list == NULL)
	{
		index->state = error;
	}
	else
		index->state = not_sorted;
	free(list->list);
}

void	sort_numbers(t_list_number *list)
{
	t_list_number	index;
	t_window		window;

	if (list->state == error)
		ft_dprintf(STDERR_FILENO, "Error\n");
	else if (list->state == not_sorted)
	{
		init_index_list(&index, list);
		if (index.state == error)
		{
			ft_dprintf(STDERR_FILENO, "Error\n");
		}
		else
		{
			window = init_window(index.size);
			sorting_process(&index, &window);
		}
		free(index.list);
	}
	free(list);
}

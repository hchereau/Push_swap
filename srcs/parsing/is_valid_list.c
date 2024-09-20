/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:32:13 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/20 16:46:16 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_valid_string(const char *list)
{
	size_t	i;

	i = 0;
	if (list == NULL)
		return (false);
	while (list[i] != '\0')
	{
		if (list[i] != ' ' && list[i] != '-' && list[i] != '+'
			&& ft_isdigit(list[i]) == 0)
			return (false);
		++i;
	}
	return (true);
}

static bool	is_valid_numbers(const long *list, size_t size_list)
{
	size_t	i;

	i = 0;
	while (i < size_list)
	{
		if (list[i] < INT_MIN || list[i] > INT_MAX)
			return (false);
		++i;
	}
	return (true);
}

bool	is_valid_list(const char *string_list, const long *list,
	size_t size_list)
{
	bool	is_valid;

	is_valid = is_valid_string(string_list);
	if (is_valid == true)
	{
		is_valid = is_valid_numbers(list, size_list);
	}
	return (is_valid);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:32:13 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/21 17:02:56 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	is_duplicate_numbers(const long *list, size_t size_list)
{
	size_t	i;

	i = 1;
	while (i < size_list)
	{
		if (list[i] == list[0])
			return (false);
		++i;
	}
	return (true);
}

static bool	is_number_in_int(const long number)
{
	if (number < INT_MIN || number > INT_MAX)
		return (false);
	return (true);
}

static bool	is_valid_numbers(const long *list, size_t size_list)
{
	size_t	i;
	size_t	state;

	i = 0;
	state = true;
	while (i < size_list && state == true)
	{
		state = is_number_in_int(list[i])
			* is_duplicate_numbers(list + i, size_list - i);
		++i;
	}
	return (state);
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

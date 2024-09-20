/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:32:13 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/20 18:15:48 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_valid_char(const char c)
{
	return (c == '-' || c == '+' || c == ' ');
}

static bool	is_real_number(const char *str)
{
	size_t	i;

	i = 0;
	if (is_valid_char(str[i]) == true)
		++i;
	while (ft_isdigit(str[i]) == 1)
		++i;
	if (str[i] == ' ' || str[i] == '\0')
		return (true);
	return (false);
}

static bool	is_valid_string(const char *list)
{
	size_t	i;

	i = 0;
	if (list == NULL)
		return (false);
	while (list[i] != '\0')
	{
		if ((is_valid_char(list[i]) == false
			&& ft_isdigit(list[i]) == 0)
			|| is_real_number(list + i) == false)
			return (false);
		++i;
	}
	return (true);
}

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
			* is_duplicate_numbers(list + i, size_list);
		++i;
	}
	return (state);
}

bool	is_valid_list(const char *string_list, const long *list,
	size_t size_list)
{
	bool	is_valid;

	is_valid = is_valid_string(string_list);
	printf("is_valid = %d\n", is_valid);
	if (is_valid == true)
	{
		is_valid = is_valid_numbers(list, size_list);
	}
	return (is_valid);
}


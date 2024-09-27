/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:24:03 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/27 10:18:35 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char	*get_string_list(int ac, char **av)
{
	char	*string_list;
	char	*temp_string_list;
	int		i;

	i = 1;
	string_list = ft_strdup("");
	if (string_list == NULL)
		return (NULL);
	temp_string_list = string_list;
	while (i < ac)
	{
		string_list = ft_strjoin(string_list, av[i]);
		free(temp_string_list);
		temp_string_list = string_list;
		if (string_list == NULL)
			break ;
		string_list = ft_strjoin(string_list, " ");
		free(temp_string_list);
		temp_string_list = string_list;
		if (string_list == NULL)
			break ;
		++i;
	}
	return (string_list);
}

static size_t	get_list(long **list, char *str)
{
	char	**split;
	size_t	i_list;
	size_t	size_list;

	i_list = 0;
	size_list = count_words(str, ' ');
	split = ft_split(str, ' ');
	*list = malloc(sizeof(long) * size_list);
	if (*list != NULL && split != NULL)
	{
		while (*split)
		{
			(*list)[i_list] = ft_atol(*split);
			++i_list;
			++split;
		}
	}
	free_strs(split - i_list);
	return (i_list);
}

static t_list_state	get_numbers(size_t *list_size, long **list,
	char *string_list)
{
	t_list_state	state;

	*list_size = get_list(list, string_list);
	if (is_valid_list(string_list, *list, *list_size) == true)
	{
		state = not_sorted;
	}
	else
	{
		state = error;
		free(*list);
	}
	free(string_list);
	return (state);
}

t_list_number	*get_numbers_list(int ac, char **av)
{
	char			*string_list;
	t_list_number	*list;

	list = malloc(sizeof(t_list_number));
	list->state = error;
	if (ac < 2)
	{
		free(list);
		exit(1);
	}
	string_list = get_string_list(ac, av);
	if (string_list != NULL)
	{
		list->state = get_numbers(&list->size, &list->list, string_list);
	}
	if (list->state != error)
	{
		list->state = is_sorted(list->list, list->size);
		if (list->state == sorted)
			free(list->list);
	}
	return (list);
}

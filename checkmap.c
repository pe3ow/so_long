/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 03:45:15 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/30 07:05:52 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkmap(int fd)
{
	t_data	data;

	data.map = malloc(BUFFER_SIZE + 1);
	if (!data.map)
		return (0);
	data.end = read(fd, data.map, BUFFER_SIZE);
	data.map[data.end] = 0;
	if ((!checkmandatories(data)) && (!checkmandatories2(data)))
		return (0);
	if (!(checklen(data)))
		return (0);
	if (!(checkwall(data)))
		return (0);
	free(data.map);
	return (1);
}

int	checkmandatories(t_data data)
{
	data.i = 0;
	data.countcheck = 0;
	while (data.map[data.i++])
	{
		if (data.map[data.i] == 'E')
			data.countcheck += 1;
	}
	data.i = 0;
	while (data.map[data.i++])
	{
		if (data.map[data.i] == 'P')
			data.countcheck += 1;
	}
	data.i = 0;
	if (data.countcheck == 2)
		return (1);
	return (0);
}

int	checkmandatories2(t_data data)
{
	data.i = 0;
	data.countcheck = 0;
	while (data.map[data.i++])
	{
		if (data.map[data.i] == 'C')
		{
			data.countcheck += 1;
			break ;
		}
	}
	data.i = 0;
	while (data.map[data.i] == '0' || data.map[data.i] == '1'
		|| data.map[data.i] == 'C' || data.map[data.i] == '\n'
		|| data.map[data.i] == 'E' || data.map[data.i] == 'P')
		data.i++;
	data.i = 0;
	if (data.map[data.i] == 0 && data.countcheck == 1)
		return (1);
	return (0);
}

int	checklen(t_data data)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	data.parsed_map[j] = get_next_line(data.fd);
	while (data.parsed_map[j])
	{
		j++;
		data.parsed_map[j] = get_next_line(data.fd);
	}
	data.parsed_map[j] = NULL;
	while (ft_strlen(data.parsed_map[i]) == ft_strlen(data.parsed_map[i - 1])
		&& data.parsed_map[i])
	{
		if (ft_strlen(data.parsed_map[i]) != ft_strlen(data.parsed_map[i - 1]))
			return (0);
		i++;
	}
	if (ft_strlen(data.parsed_map[0]) <= i)
		return (0);
	return (1);
}

int	checkwall(t_data data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data.parsed_map[i + 1] != 0)
		i++;
	while (data.parsed_map[0][j])
	{
		if (data.parsed_map[0][j] == '1' && data.parsed_map[i][j] == '1')
			return (0);
		j++;
	}
	i = 0;
	while (data.parsed_map[i])
	{
		if (data.parsed_map[i][0] != '1'
			&& data.parsed_map[i][ft_strlen(data.parsed_map[i])] != '1')
			return (0);
		i++;
	}
	return (1);
}

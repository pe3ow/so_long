/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 03:45:15 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/31 09:42:20 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkmap(int fd, t_data *data)
{
	data->map = malloc(BUFFER_SIZE + 1);
	if (!data->map)
		return (0);
	data->end = read(fd, data->map, BUFFER_SIZE);
	if (data->end <= 0)
	{
		ft_printf("Error\n");
		clean_exit(data, 1);
	}
	data->map[data->end] = 0;
	data->parsed_map = ft_split(data->map, '\n');
	if ((!checkmandatories(data)) || (!checkmandatories2(data)))
	{
		ft_printf("Error\n");
		clean_exit(data, 1);
	}
	if (!checklen(data) || !checkwall(data))
	{
		ft_printf("Error\n");
		clean_exit(data, 1);
	}
	return (1);
}

int	checkmandatories(t_data *data)
{
	data->i = 0;
	data->countcheck = 0;
	if (!data->map)
		return (0);
	while (data->map[data->i])
	{
		if (data->map[data->i] == 'E')
			data->countcheck += 1;
		data->i ++;
	}
	data->i = 0;
	while (data->map[data->i])
	{
		if (data->map[data->i] == 'P')
			data->countcheck += 1;
		data->i++;
	}
	data->i = 0;
	if (data->countcheck == 2)
		return (1);
	return (0);
}

int	checkmandatories2(t_data *data)
{
	data->i = 0;
	data->countcheck = 0;
	if (!data->map)
		return (0);
	while (data->map[data->i] == '0' || data->map[data->i] == '1'
		|| data->map[data->i] == 'C' || data->map[data->i] == '\n'
		|| data->map[data->i] == 'E' || data->map[data->i] == 'P')
		data->i++;
	if (data->map[data->i] != 0)
	{
		data->i = 0;
		return (0);
	}
	data->i = 0;
	if (!lf_collectible(data))
		return (0);
	return (1);
}

int	checklen(t_data *data)
{
	if (!data->parsed_map || !data->parsed_map[0])
		return (0);
	data->end = ft_strlen(data->parsed_map[0]);
	data->i = 1;
	while (data->parsed_map[data->i])
	{
		if (ft_strlen(data->parsed_map[data->i]) != data->end)
			return (0);
		data->i++;
	}
	if (data->i == data->end)
		return (0);
	return (1);
}

int	checkwall(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!data->parsed_map)
		return (0);
	while (data->parsed_map[i])
		i++;
	i -= 1;
	while (data->parsed_map[0][j])
	{
		if (data->parsed_map[0][j] != '1' || data->parsed_map[i][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (data->parsed_map[i])
	{
		if (data->parsed_map[i][0] != '1'
			|| data->parsed_map[i][ft_strlen(data->parsed_map[i]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

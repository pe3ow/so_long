/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 07:05:41 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/31 08:28:51 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_texture(t_data *data, void **img)
{
	if (!data || !data->mlx || !img || !*img)
		return ;
	mlx_destroy_image(data->mlx, *img);
	*img = NULL;
}

static void	free_textures(t_data *data)
{
	if (!data || !data->mlx)
		return ;
	free_texture(data, &data->img_wall);
	free_texture(data, &data->img_floor);
	free_texture(data, &data->img_player);
	free_texture(data, &data->img_collectible);
	free_texture(data, &data->img_exit);
}

void	clean_exit(t_data *data, int code)
{
	close(data->fd);
	if (!data)
		exit(code);
	free_textures(data);
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	data->mlx = NULL;
	if (data->parsed_map)
	{
		data->ix = 0;
		while (data->parsed_map[data->ix])
		{
			free(data->parsed_map[data->ix]);
			data->parsed_map[data->ix++] = NULL;
		}
		free(data->parsed_map);
		data->parsed_map = NULL;
	}
	if (data->map)
	{
		free(data->map);
		data->map = NULL;
	}
	exit(code);
}

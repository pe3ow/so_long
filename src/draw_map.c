/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 05:51:33 by lbardet-          #+#    #+#             */
/*   Updated: 2025/11/08 09:45:58 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_data *data)
{
	int	width;
	int	height;

	height = 32;
	width = 32;
	if (data->count)
		free_textures(data);
	data->img_wall = mlx_xpm_file_to_image(data->mlx,
			"textures/wall.xpm", &width, &height);
	data->img_floor = mlx_xpm_file_to_image(data->mlx,
			"textures/floor.xpm", &width, &height);
	data->img_player = mlx_xpm_file_to_image(data->mlx,
			"textures/player.xpm", &width, &height);
	data->img_exit = mlx_xpm_file_to_image(data->mlx,
			"textures/exit.xpm", &width, &height);
	data->img_collectible = mlx_xpm_file_to_image(data->mlx,
			"textures/collectible.xpm", &width, &height);
	if (!data->img_wall || !data->img_floor || !data->img_player
		|| !data->img_exit || !data->img_collectible)
		clean_exit(data, 1);
}

void	draw_map(t_data *data)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	data->tile = 32;
	while (data->parsed_map[y])
	{
		x = 0;
		while (data->parsed_map[y][x])
		{
			c = data->parsed_map[y][x];
			if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
				put_image(data, x, y, c);
			x++;
		}
		y++;
	}
}

void	put_image(t_data *data, int x, int y, char c)
{
	int	tile;

	tile = 32;
	mlx_put_image_to_window(data->mlx, data->win, data->img_floor,
		x * data->tile, y * data->tile);
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img_wall,
			x * data->tile, y * data->tile);
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img_floor,
			x * data->tile, y * data->tile);
	if (c == 'P' && data->count == 0)
	{
		data->x = x;
		data->y = y;
		mlx_put_image_to_window(data->mlx, data->win, data->img_player,
			x * data->tile, y * data->tile);
	}
	if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img_collectible,
			x * data->tile, y * data->tile);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img_exit,
			x * data->tile, y * data->tile);
}

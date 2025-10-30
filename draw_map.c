/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 05:51:33 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/30 06:44:38 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_data *data)
{
	int	width;
	int	height;

	height = 32;
	width = 32;
	data->img_wall = mlx_xpm_file_to_image(data->mlx,
			"textures/wall.xpm", &width, &height);
	data->img_floor = mlx_xpm_file_to_image(data->mlx,
			"textures/floor.xpm", &width, &height);
	data->img_player = mlx_xpm_file_to_image(data->mlx,
			"textures/player.xpm", &width, &height);
	data->img_exit = mlx_xpm_file_to_image(data->mlx,
			"textures/exit.xpm", &width, &height);
	data->img_collectible = mlx_xpm_file_to_image(data->mlx,
			"textures/coin.xpm", &width, &height);
}

void	draw_map(t_data *data)
{
	int		y;
	int		x;
	int		tile;
	char	c;

	y = 0;
	tile = 32;
	while (data->parsed_map[y])
	{
		x = 0;
		while (data->parsed_map[y][x])
		{
			c = data->parsed_map[y][x];
			if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
				put_image(data, x, y, tile);
			x++;
		}
		y++;
	}
}

void	put_image(t_data *data, int x, int y, char c)
{
	int	tile;

	tile = 32;
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img_wall,
			x * tile, y * tile);
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img_floor,
			x * tile, y * tile);
	if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img_player,
			x * tile, y * tile);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img_collectible,
			x * tile, y * tile);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img_exit,
			x * tile, y * tile);
}

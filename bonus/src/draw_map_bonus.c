/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 05:51:33 by lbardet-          #+#    #+#             */
/*   Updated: 2025/11/08 09:49:44 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			"textures/bonus/player_down.xpm", &width, &height);
	data->img_ennemy = mlx_xpm_file_to_image(data->mlx,
			"textures/bonus/ennemy.xpm", &width, &height);
	data->img_exit = mlx_xpm_file_to_image(data->mlx,
			"textures/exit.xpm", &width, &height);
	data->img_collectible = mlx_xpm_file_to_image(data->mlx,
			"textures/collectible.xpm", &width, &height);
	if (!data->img_wall || !data->img_floor || !data->img_player
		|| !data->img_exit || !data->img_collectible)
		clean_exit(data, 1);
}

void	draw_map(t_data *data, int index)
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
			if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E'
				|| c == 'L')
			{
				data->c = c;
				put_image(data, x, y, index);
			}
			x++;
		}
		y++;
	}
	data->count_str = ft_strcat("Nombre de mouvements : ", data->count, data);
	mlx_string_put(data->mlx, data->win, 5, 379, 0xFFFFFF, data->count_str);
}

void	put_image(t_data *data, int x, int y, int index)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img_floor,
		x * data->tile, y * data->tile);
	if (data->c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img_wall,
			x * data->tile, y * data->tile);
	if (data->c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img_floor,
			x * data->tile, y * data->tile);
	if (data->c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img_collectible,
			x * data->tile, y * data->tile);
	if (data->c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img_exit,
			x * data->tile, y * data->tile);
	if (data->c == 'L')
		mlx_put_image_to_window(data->mlx, data->win, data->img_ennemy,
			x * data->tile, y * data->tile);
	ft_player(data, index, x, y);
}

void	ft_player(t_data *data, int index, int x, int y)
{
	if (data->c == 'P' && data->count == 0)
	{
		data->x = x;
		data->y = y;
		mlx_put_image_to_window(data->mlx, data->win, data->img_player,
			x * data->tile, y * data->tile);
	}
	mlx_destroy_image(data->mlx, data->img_player);
	if (index == 1)
		data->img_player = mlx_xpm_file_to_image(data->mlx,
				"textures/bonus/player_left.xpm", &x, &y);
	if (index == 2)
		data->img_player = mlx_xpm_file_to_image(data->mlx,
				"textures/bonus/player_right.xpm", &x, &y);
	if (index == 3)
		data->img_player = mlx_xpm_file_to_image(data->mlx,
				"textures/bonus/player_up.xpm", &x, &y);
	if (index == 4)
		data->img_player = mlx_xpm_file_to_image(data->mlx,
				"textures/bonus/player_down.xpm", &x, &y);
}

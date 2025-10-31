/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:57:18 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/31 08:20:35 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int key, t_data *data)
{
	data->key = key;
	if (data->key == 97 || data->key == 65361)
		left(data);
	if (data->key == 100 || data->key == 65363)
		right(data);
	if (data->key == 119 || data->key == 65362)
		up(data);
	if (data->key == 115 || data->key == 65364)
		down(data);
	if (data->key == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		free_tab(data);
		exit (0);
	}
	return (0);
}

int	left(t_data *data)
{
	if (data->parsed_map[data->y][data->x - 1] == '1')
		return (0);
	if (data->parsed_map[data->y][data->x] == 'C')
		data->parsed_map[data->y][data->x] = '0';
	data->x -= 1;
	data->count += 1;
	if (data->parsed_map[data->y][data->x] == 'E' && !lf_collectible(data))
		clean_exit(data, 0);
	ft_printf("Movements : %d\n", data->count);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img_player, data->x * data->tile, data->y * data->tile);
	return (0);
}

int	right(t_data *data)
{
	if (data->parsed_map[data->y][data->x + 1] == '1')
		return (0);
	if (data->parsed_map[data->y][data->x] == 'C')
		data->parsed_map[data->y][data->x] = '0';
	data->x += 1;
	data->count += 1;
	if (data->parsed_map[data->y][data->x] == 'E' && !lf_collectible(data))
		clean_exit(data, 0);
	ft_printf("Movements : %d\n", data->count);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img_player, data->x * data->tile, data->y * data->tile);
	return (0);
}

int	up(t_data *data)
{
	if (data->parsed_map[data->y - 1][data->x] == '1')
		return (0);
	if (data->parsed_map[data->y][data->x] == 'C')
		data->parsed_map[data->y][data->x] = '0';
	data->y -= 1;
	data->count += 1;
	if (data->parsed_map[data->y][data->x] == 'E' && !lf_collectible(data))
		clean_exit(data, 0);
	ft_printf("Movements : %d\n", data->count);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img_player, data->x * data->tile, data->y * data->tile);
	return (0);
}

int	down(t_data *data)
{
	if (data->parsed_map[data->y + 1][data->x] == '1')
		return (0);
	if (data->parsed_map[data->y][data->x] == 'C')
		data->parsed_map[data->y][data->x] = '0';
	data->y += 1;
	data->count += 1;
	if (data->parsed_map[data->y][data->x] == 'E' && !lf_collectible(data))
		clean_exit(data, 0);
	ft_printf("Movements : %d\n", data->count);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img_player, data->x * data->tile, data->y * data->tile);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:57:18 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/30 06:45:27 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int key, t_data *data)
{
	data->key = key;
	if (data->key == 97)
		left(data);
	if (data->key == 100)
		right(data);
	if (data->key == 119)
		up(data);
	if (data->key == 115)
		down(data);
	if (data->key == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
	}
	return (0);
}

int	left(t_data *data)
{
	if (data->x - (32 * 2) == 0)
		return (0);
	data->x -= 32;
	data->count += 1;
	ft_printf("Movements : %d\n", data->count);
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img_player, data->x, data->y);
	return (0);
}

int	right(t_data *data)
{
	if (data->x + (32 * 2) == 800)
		return (0);
	data->x += 32;
	data->count += 1;
	ft_printf("Movements : %d\n", data->count);
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img_player, data->x, data->y);
	return (0);
}

int	up(t_data *data)
{
	if (data->y - (32 * 2) == 0)
		return (0);
	data->y -= 32;
	data->count += 1;
	ft_printf("Movements : %d\n", data->count);
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img_player, data->x, data->y);
	return (0);
}

int	down(t_data *data)
{
	if (data->y + (32 * 2) == 600)
		return (0);
	data->y += 32;
	data->count += 1;
	ft_printf("Movements : %d\n", data->count);
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img_player, data->x, data->y);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 07:05:41 by lbardet-          #+#    #+#             */
/*   Updated: 2025/11/08 09:52:45 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	free_texture(t_data *data, void **img)
{
	if (!data || !data->mlx || !img || !*img)
		return ;
	mlx_destroy_image(data->mlx, *img);
	*img = NULL;
}

void	free_textures(t_data *data)
{
	if (!data || !data->mlx)
		return ;
	if (data->count_str)
		free(data->count_str);
	free_texture(data, &data->img_wall);
	free_texture(data, &data->img_floor);
	free_texture(data, &data->img_player);
	free_texture(data, &data->img_collectible);
	free_texture(data, &data->img_exit);
	free_texture(data, &data->img_ennemy);
}

void	clean_exit(t_data *data, int code)
{
	close(data->fd);
	if (!data)
		exit(0);
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	else
	{
		free(data);
		exit(0);
	}
	data->win = NULL;
	free_textures(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	data->mlx = NULL;
	if (data->parsed_map)
		free_tab(data->parsed_map);
	if (data->map)
	{
		free(data->map);
		data->map = NULL;
	}
	free(data);
	exit(code);
}

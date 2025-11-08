/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:12:54 by lbardet-          #+#    #+#             */
/*   Updated: 2025/11/08 09:56:57 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argc;
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
		return (free(data), 0);
	checkmap(data->fd, data);
	malloc_mlx(data);
	data->win = mlx_new_window(data->mlx, data->len_tab, data->i, "so_long");
	load_img(data);
	draw_map(data, 4);
	data->filled_map = ft_tabdup((const char **)data->parsed_map);
	floodfill(data->filled_map, data->x, data->y);
	if (!floodfill_check(data->filled_map, data))
	{
		ft_printf("Error\n");
		clean_exit(data, 1);
	}
	mlx_hook(data->win, 2, 1, handle_key, data);
	mlx_hook(data->win, 17, 0, handle_exit, data);
	mlx_loop(data->mlx);
	clean_exit(data, 1);
}

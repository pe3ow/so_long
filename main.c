/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:12:54 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/31 10:02:57 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argc;
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
		return (0);
	checkmap(data->fd, data);
	data->count = 0;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, ft_strlen(data->parsed_map[0]) * 32,
			data->i * 32, "so_long");
	draw_map(data);
	data->filled_map = ft_tabdup((const char **)data->parsed_map);
	floodfill(data->filled_map, data->x, data->y);
	if (!floodfill_check(data->filled_map))
	{
		free_tab(data);
		ft_printf("Error\n");
		clean_exit(data, 1);
	}
	free_tab(data);
	mlx_hook(data->win, 2, 1, handle_key, data);
	mlx_hook(data->win, 17, 0, handle_exit, data);
	mlx_loop(data->mlx);
	free_tab(data);
	return (0);
}

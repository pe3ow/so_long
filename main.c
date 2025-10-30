/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:12:54 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/30 07:06:07 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	(void)argv;
	data.fd = open(argv[1], O_RDONLY);
	if (data.fd <= 0)
		return (0);
	if ((!(checkmap(data.fd))))
	{
		ft_printf("Error\n");
		return (0);
	}
	close(data.fd);
	data.count = 0;
	data.mlx = mlx_init();
	if (!data.mlx)
		return (0);
	data.win = mlx_new_window(data.mlx, 800, 600, "so_long");
	data.x = 400;
	data.y = 300;
	load_img(&data);
	draw_map(&data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_loop(data.mlx);
	free_tab(data);
	return (0);
}

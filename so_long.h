/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:57:47 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/30 06:59:08 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include "minilibx-linux/mlx.h"
# include "ft_printf/ft_printf.h"
# include "Libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img_player;
	void	*img_wall;
	void	*img_floor;
	void	*img_exit;
	void	*img_collectible;
	int		x;
	int		y;
	int		count;
	int		img_width;
	int		img_height;
	int		key;
	int		fd;
	int		countcheck;
	int		i;
	int		end;
	char	*map;
	char	**parsed_map;
}	t_data;

int		handle_key(int key, t_data *data);
int		left(t_data *data);
int		right(t_data *data);
int		up(t_data *data);
int		down(t_data *data);
int		checkmap(int fd);
int		checkmandatories(t_data data);
int		checkmandatories2(t_data data);
int		checklen(t_data data);
int		checkwall(t_data data);
void	free_tab(t_data data);
void	load_img(t_data *data);
void	draw_map(t_data *data);
void	put_image(t_data *data, int x, int y, char c);

#endif
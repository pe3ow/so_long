/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:57:47 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/31 10:12:20 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include "minilibx-linux/mlx.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img_player;
	void		*img_wall;
	void		*img_floor;
	void		*img_exit;
	void		*img_collectible;
	int			tile;
	int			x;
	int			y;
	int			count;
	int			collectible;
	int			img_width;
	int			img_height;
	int			key;
	int			fd;
	int			countcheck;
	int			ix;
	ssize_t		i;
	ssize_t		end;
	char		*map;
	char		**parsed_map;
	char		**filled_map;
}	t_data;

int		handle_key(int key, t_data *data);
int		left(t_data *data);
int		right(t_data *data);
int		up(t_data *data);
int		down(t_data *data);
int		checkmap(int fd, t_data *data);
int		checkmandatories(t_data *data);
int		checkmandatories2(t_data *data);
int		checklen(t_data *data);
int		checkwall(t_data *data);
void	free_tab(t_data *data);
void	load_img(t_data *data);
void	draw_map(t_data *data);
void	put_image(t_data *data, int x, int y, char c);
char	**ft_split(char const *s, char c);
int		ft_strlen(char *str);
int		lf_collectible(t_data *data);
void	clean_exit(t_data *data, int code);
int		handle_exit(t_data *data);
void	floodfill(char	**filled_map, int x, int y);
char	**ft_tabdup(const char **s);
int		floodfill_check(char **filled_map);

#endif
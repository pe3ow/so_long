/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:57:47 by lbardet-          #+#    #+#             */
/*   Updated: 2025/11/08 09:53:43 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

# include "mlx.h"
# include "ft_printf.h"
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
	void		*img_ennemy;
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
	size_t		len_tab;
	ssize_t		i;
	ssize_t		end;
	char		c;
	char		*count_str;
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
void	free_tab(char **tab);
void	load_img(t_data *data);
void	draw_map(t_data *data, int index);
void	put_image(t_data *data, int x, int y, int index);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char *str);
int		lf_collectible(t_data *data);
void	clean_exit(t_data *data, int code);
int		handle_exit(t_data *data);
void	floodfill(char	**filled_map, int x, int y);
char	**ft_tabdup(const char **s);
int		floodfill_check(char **filled_map, t_data *data);
void	free_textures(t_data *data);
char	*ft_strcpy(char *src, char *dest);
void	free_tab2(char **tab);
size_t	ft_tablen(const char	**tab);
void	malloc_mlx(t_data *data);
void	ft_player(t_data *data, int index, int x, int y);
char	*ft_strcat(const char *str, int nb, t_data *data);
char	*dup_str(const char *s);
char	*ft_strcopy(const char *s1, char *s2);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:04:41 by lbardet-          #+#    #+#             */
/*   Updated: 2025/11/08 09:56:57 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_exit(t_data *data)
{
	clean_exit(data, 0);
	return (0);
}

void	free_tab2(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i ++;
	}
	free(tab);
	tab = NULL;
	exit (0);
}

size_t	ft_tablen(const char	**tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		exit (0);
	while (tab[i])
		i++;
	return (i);
}

void	malloc_mlx(t_data *data)
{
	data->i = ft_tablen((const char **)data->parsed_map) * 32;
	data->len_tab = ft_strlen(data->parsed_map[0]) * 32;
	data->count = 0;
	data->mlx = mlx_init();
	if (!data->mlx)
		exit (0);
}

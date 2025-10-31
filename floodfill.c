/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 08:07:14 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/31 10:02:43 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill(char **filled_map, int x, int y)
{
	if (!filled_map || y < 0 || x < 0)
		return ;
	if (!filled_map[y])
		return ;
	if (x >= ft_strlen(filled_map[y]))
		return ;
	if (filled_map[y][x] == '1' || filled_map[y][x] == 'V')
		return ;
	filled_map[y][x] = 'V';
	floodfill(filled_map, x + 1, y);
	floodfill(filled_map, x - 1, y);
	floodfill(filled_map, x, y + 1);
	floodfill(filled_map, x, y - 1);
}

int	floodfill_check(char **filled_map)
{
	int	i;
	int	j;

	if (!filled_map)
		return (0);
	j = 0;
	while (filled_map[j])
	{
		i = 0;
		while (filled_map[j][i])
		{
			if (filled_map[j][i] == 'C' || filled_map[j][i] == 'E')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

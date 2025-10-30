/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 05:11:11 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/30 06:43:39 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(t_data data)
{
	int	i;

	i = 0;
	while (data.parsed_map[i])
		i++;
	while (i != 0)
	{
		free(data.parsed_map[i]);
		i --;
	}
	free(data.parsed_map);
}

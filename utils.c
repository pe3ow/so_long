/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 05:11:11 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/31 09:47:20 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(t_data *data)
{
	int	i;

	i = 0;
	while (data->filled_map[i])
		i++;
	while (i != 0)
	{
		free(data->filled_map[i]);
		i --;
	}
	free(data->filled_map);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	lf_collectible(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->collectible = 0;
	while (data->parsed_map[j])
	{
		while (data->parsed_map[j][i])
		{
			if (data->parsed_map[j][i] == 'C')
				data->collectible += 1;
			i++;
		}
		i = 0;
		j++;
	}
	return (data->collectible);
}

int	handle_exit(t_data *data)
{
	clean_exit(data, 0);
	return (0);
}

char	**ft_tabdup(const char **s)
{
	char	**s2;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	j = 0;
	while (s[j])
		j++;
	s2 = malloc((j + 1) * sizeof(char *));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < j)
	{
		s2[i] = malloc(ft_strlen((char *)s[i]) + 1);
		if (!s2[i])
		{
			while (i-- > 0)
				free(s2[i]);
			free(s2);
			return (NULL);
		}
		k = 0;
		while (s[i][k])
		{
			s2[i][k] = s[i][k];
			k++;
		}
		s2[i][k] = '\0';
		i++;
	}
	s2[j] = NULL;
	return (s2);
}

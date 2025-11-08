/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 05:11:11 by lbardet-          #+#    #+#             */
/*   Updated: 2025/11/08 09:34:46 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_tab(char **tab)
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
}

size_t	ft_strlen(char *str)
{
	size_t	i;

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

char	*dup_str(const char *s)
{
	char	*d;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen((char *)s);
	d = malloc(len + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	**ft_tabdup(const char **s)
{
	char	**s2;
	size_t	i;
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	s2 = malloc((n + 1) * sizeof(char *));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < n)
	{
		s2[i] = dup_str(s[i]);
		if (!s2[i])
		{
			while (i > 0)
				free(s2[--i]);
			free(s2);
			return (NULL);
		}
		i++;
	}
	s2[n] = NULL;
	return (s2);
}

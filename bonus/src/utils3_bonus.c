/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 08:13:34 by lbardet-          #+#    #+#             */
/*   Updated: 2025/11/08 09:43:07 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	count_num(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_itoa(int n)
{
	int		num;
	char	*str;

	num = count_num(n);
	str = (char *)malloc(sizeof(char) * (num + 1));
	if (!str)
		return (NULL);
	str[num] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		num--;
		if (n > 0)
			str[num] = (n % 10) + '0';
		else
			str[num] = -(n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_strcopy(const char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

char	*ft_strcat(const char *str, int nb, t_data *data)
{
	char	*str2;
	char	*new_str;
	size_t	len;
	size_t	i;
	size_t	j;

	if (data->count_str)
		free(data->count_str);
	str2 = ft_itoa(nb);
	len = ft_strlen((char *)str) + ft_strlen(str2);
	new_str = malloc(len + 1);
	j = 0;
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	while (str2[j])
		new_str[i++] = str2[j++];
	new_str[i] = 0;
	free(str2);
	return (new_str);
}

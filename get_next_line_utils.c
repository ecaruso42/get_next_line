/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaruso <ecaruso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:03:42 by ecaruso           #+#    #+#             */
/*   Updated: 2023/02/16 16:45:36 by ecaruso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_get_line(char *backup)
{
	int		i;
	char	*str;

	if (!backup[i])
		return (NULL);
	while (!backup[i] && backup[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		str[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		str[i] = backup[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_backup(char *backup)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (backup[i])
		str[j++] = backup [i++];
	str[j] = '\0';
	free(backup);
	return (str);
}

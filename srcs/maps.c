/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:45:52 by htomas-d          #+#    #+#             */
/*   Updated: 2022/09/19 10:45:30 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

char	**ft_read_map(char *av)
{
	char	**mapstr;
	char	*line;
	char	*temp;
	char	*temp_map;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (NULL);
	temp_map = malloc(sizeof(char));
	temp_map[0] = '\0';
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = temp_map;
		temp_map = ft_strjoin(temp_map, line);
		free(line);
		free(temp);
	}
	mapstr = ft_split(temp_map, '\n');
	free (temp_map);
	close (fd);
	return (mapstr);
}

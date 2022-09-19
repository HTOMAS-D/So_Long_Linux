/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:35:26 by htomas-d          #+#    #+#             */
/*   Updated: 2022/09/19 10:49:03 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

void	map_error(t_win *win)
{
	if (win->mapstr)
		free(win->mapstr);
	ft_printf("\e[0;31mERROR\nINVALID MAP\n");
	exit(1);
}

int	check_file(char *file)
{
	int	i;

	i = 0;
	while (file[i + 1])
		i++;
	if (file[i] == 'r' && file[i - 1] == 'e'
		&& file[i - 2] == 'b' && file[i - 3] == '.'
		&& file[i - 4])
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_win	win;

	if (ac == 2 && check_file(av[1]))
	{
		win.mapstr = ft_read_map(av[1]);
		win.map = malloc(sizeof(t_map));
		win.img = malloc(sizeof(t_img));
		if (error_check(win.mapstr, win.map, &win))
		{
			game_win(&win);
			mlx_hook(win.win_ptr, 17, 0, exit_game, &win);
			mlx_key_hook(win.win_ptr, read_keys, &win);
			mlx_hook(win.win_ptr, 02, (1L << 0), cread_keys, &win);
			mlx_loop(win.mlx_ptr);
		}
		else
			map_error(&win);
	}
	else
	{
		ft_printf("\e[0;31mINVALID MAP FILE\n");
		exit(1);
	}
	return (0);
}

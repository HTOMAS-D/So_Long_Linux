/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:28:14 by htomas-d          #+#    #+#             */
/*   Updated: 2022/09/19 10:41:21 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

void	img_d(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	win->img->player = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/pato_d.xpm", &win->map->w, &win->map->h);
}

void	img_a(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	win->img->player = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/pato_a.xpm", &win->map->w, &win->map->h);
}

void	img_s(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	win->img->player = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/pato_s.xpm", &win->map->w, &win->map->h);
}

void	img_w(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	win->img->player = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/pato_w.xpm", &win->map->w, &win->map->h);
}

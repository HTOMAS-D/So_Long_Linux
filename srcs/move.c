#include "so_long.h"
#include "../mlx/mlx.h"

void	move_w(t_win *win)
{
	printf("\nw\n");
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	win->img->player = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/pato_w.xpm", &win->map->w, &win->map->h);
	if(win->mapstr[win->p_y - 1][win->p_x] != '1'
		&& win->mapstr[win->p_y - 1][win->p_x != 'E']
		|| !win->map->collect)
	{
		if(win->mapstr[win->p_y - 1][win->p_x] == 'C')
		{
			win->map->collect--;
			win->mapstr[win->p_y][win->p_x] = '0';
			win->p_y--;
			win->mapstr[win->p_y][win->p_x] = 'P';
		}
		else if(win->mapstr[win->p_y - 1][win->p_x] == '0')
		{
			win->mapstr[win->p_y][win->p_x] = '0';
			win->p_y--;
			win->mapstr[win->p_y][win->p_x] = 'P';
		}
		else
			win->over = 1;
		win->moves++;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
	}
	draw_img(win);
}

void	move_s(t_win *win)
{
	printf("\ns\n");
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	win->img->player = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/pato_s.xpm", &win->map->w, &win->map->h);
	if(win->mapstr[win->p_y + 1][win->p_x] != '1'
		&& win->mapstr[win->p_y + 1][win->p_x != 'E']
	       	|| !win->map->collect)
	{
		if(win->mapstr[win->p_y + 1][win->p_x] == 'C')
		{
			win->map->collect--;
		       	win->mapstr[win->p_y][win->p_x] = '0';
			win->p_y++;
			win->mapstr[win->p_y][win->p_x] = 'P';
		}
		else if(win->mapstr[win->p_y + 1][win->p_x] == '0')
		{
			win->mapstr[win->p_y][win->p_x] = '0';
			win->p_y++;
			win->mapstr[win->p_y][win->p_x] = 'P';
		}
		else
			win->over = 1;
		win->moves++;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
	}
//	printf("%d\n%d\n\n", win->p_x, win->p_y);
	draw_img(win);
//	printf("depis%d\n%d\n\n", win->p_x, win->p_y);
}

#include "so_long.h"
#include "../mlx/mlx.h"

void	free_map(char **mapstr)
{
	int	i;

	i = 0;
	while (mapstr[i])
	{
		free(mapstr[i]);
		i++;
	}
	free(mapstr);
}

int	exit_game(t_win *win)
{
	free_map(win->mapstr);
	mlx_destroy_image(win->mlx_ptr, win->img->wall);
	mlx_destroy_image(win->mlx_ptr, win->img->exit_o);
	mlx_destroy_image(win->mlx_ptr, win->img->exit_c);
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	mlx_destroy_image(win->mlx_ptr, win->img->collect);
	mlx_destroy_image(win->mlx_ptr, win->img->mid);
	free(win->mlx_ptr);
	exit(0);
}

int	read_keys(int keycode, t_win *win)
{
	if(keycode == K_ESC)
		exit_game(win);
	return(0);
}

int	cread_keys(int keycode, t_win *win)
{
	int counter;

	counter = win->moves;
	if(win->over)
		return (0);
	else if(keycode == K_W)
		move_w(win);
	else if(keycode == K_A)
		move_a(win);
	else if(keycode == K_S)
		move_s(win);
	else if(keycode == K_D)
		move_d(win);
	if(counter != win->moves)
		ft_printf("Moves: %d\n", win->moves);
	return (0);
}

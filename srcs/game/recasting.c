#include "../../includes/cub.h"
static void	init_screen(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	game->screen->img = mlx_new_image(game->mlx_ptr,
									  SCREEN_WIDTH,
									  SCREEN_HEIGHT);
	game->screen->adr = mlx_get_data_addr(game->screen->img,
										  &game->screen->bpp,
										  &game->screen->len,
										  &game->screen->endian);
}

int	recasting(t_game *game)
{
	int	x;

	init_screen(game);
	x = -1;
	while (++x < SCREEN_WIDTH)
	{

	}
	return (OK);
}
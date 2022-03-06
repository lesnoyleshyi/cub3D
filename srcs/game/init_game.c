#include "../../includes/cub.h"

static void	init_color(t_game *game, t_data *data)
{
	game->c_color = (data->ceilling->r * 256 + data->ceilling->g)
			* 256 + data->ceilling->b;
	game->f_color = (data->floor->r * 256 + data->floor->g)
			* 256 + data->floor->b;
}

t_game	*init_game(t_data *data)
{
	t_game	*game;

	game = (t_game *) malloc(sizeof (t_game));
	if (game == NULL)
		put_error(INVALID_MEMORY, ERR_MEMORY);
	init_mlx(game, data);
	init_color(game, data);
	game->map = data->map->map;
	return (game);
}
#include "../../includes/cub.h"

static void extract_data_from_map(t_game *game, t_map *map)
{
	char	sym;

	sym = map->player_side;
	game->map = map->map;
	game->player.x = (double) map->player_x + 0.5;
	game->player.y = (double) map->player_y + 0.5;
	game->dir.x = 0 + (sym == SIDE_W) - (sym == SIDE_E);
	game->dir.y = 0 + (sym == SIDE_N) - (sym == SIDE_S);
	game->plane.x = game->dir.y * -0.66;
	game->plane.y = game->dir.x * -0.66;
}

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
	extract_data_from_map(game, data->map);

	return (game);
}

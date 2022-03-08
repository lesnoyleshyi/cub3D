#include "../../includes/cub.h"

void	move_up(t_game *game)
{
	double	old_x;
	double	old_y;

	old_x = game->player.x;
	old_y = game->player.y;

}

int	execute_action(int key, t_game *game)
{
	if (game)
		;
	printf("Key - %d\n", key);
	if (key == KEY_ESC)
		exit_ok(key);
	else if (key == KEY_W || key == KEY_UP)
		move_up(game);

	return (OK);
}

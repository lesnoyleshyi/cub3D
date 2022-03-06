#include "../../includes/cub.h"

int	execute_action(int key, t_game *game)
{
	if (game)
		;
	printf("Key - %d\n", key);
	if (key == KEY_ESC)
		exit_ok(key);

	return (OK);
}

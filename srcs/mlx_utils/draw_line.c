#include "../../includes/cub.h"

void	draw_pixel(t_tex *scr, t_icoord pos, int color)
{
	if (pos.x >= 0 && pos.y >= 0
		&& pos.x < SCREEN_WIDTH && pos.y < SCREEN_HEIGHT)
		*(int *)(scr->adr + (scr->len * pos.y) + (scr->bpp * pos.x / 8)) = color;
}

int get_tex_color(t_tex *tex, t_icoord pos)
{
	if (pos.x >= 0 && pos.y >= 0
		&& pos.x < TEX_WIDTH && pos.y < TEX_HEIGHT)
		return (*(int *) (tex->adr + (tex->len * pos.y) \
		+ (tex->bpp * pos.x / 8)));
	return (0x0);
}

void	draw_line(t_game *game, t_icoord pos, int end)
{
	int			i;
	t_icoord	pos_pix;

	i = -1;
	pos_pix.x = pos.x;
	while (++i < pos.y)
	{
		pos_pix.y = i;
		draw_pixel(&game->screen, pos_pix, game->c_color);
	}
	i = end - 1;
	while (++i < SCREEN_HEIGHT)
	{
		pos_pix.y = i;
		draw_pixel(&game->screen, pos_pix, game->f_color);
	}
}

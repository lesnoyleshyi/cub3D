#include "../../includes/cub.h"

static int	get_pixel(t_tex *tex, int x, int y)
{
	int	*color;

	color = (void *) tex->adr + (y * tex->len) + (x * tex->bpp / 8);
	return (*color);
}

static void	put_pixel(t_tex *img, int x, int y, int color)
{
	char	*dst;

	dst = img->adr + (y * img->len) + (x * img->bpp / 8);
	*(int *)dst = color;
}

static void put_texture_pixel(t_game *game, int x, int y)
{
	int		color;
	t_param param;

	param = game->params;
	param.tex.y = (int) (param.tex_pos) & (TEX_HEIGHT - 1);
	param.tex_pos += param.step_len;
	if (param.side == E_HORIZONTAL && param.step.y < 0)
		color = get_pixel(&game->texture[E_WEST], param.tex.x, param.tex.y);
	else if (param.side == E_HORIZONTAL && param.step.y >= 0)
		color = get_pixel(&game->texture[E_EAST], param.tex.x, param.tex.y);
	else if (param.side == E_VERTICAL && param.step.x < 0)
		color = get_pixel(&game->texture[E_NORTH], param.tex.x, param.tex.y);
	else
		color = get_pixel(&game->texture[E_SOUTH], param.tex.x, param.tex.y);
	put_pixel(&game->screen, x, y, color);
}

void	draw_line(t_game *game, int x)
{
	int	y;

	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		if (y < game->params.draw_start)
			put_pixel(&game->screen, x, y, game->c_color);
		else if (y >= game->params.draw_start && y < game->params.draw_end)
			put_texture_pixel(game, x, y);
		else
			put_pixel(&game->screen, x, y, game->f_color);
	}
}

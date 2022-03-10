#include "../includes/cub.h"

void	print_string_array(char **arr)
{
	while (*arr)
		printf("%s\n", *(arr++));
}

void	print_data(t_data *data)
{
	printf("   --- DATA START ---   \n");
	printf("path_north - %s\n", data->path_north);
	printf("path_south - %s\n", data->path_south);
	printf("path_west - %s\n", data->path_west);
	printf("path_east - %s\n", data->path_east);
	printf("color F - %d %d %d\n", data->floor->r, data->floor->g, data->floor->b);
	printf("color C - %d %d %d\n", data->ceilling->r, data->ceilling->g, data->ceilling->b);
	printf("   --- MAP START ---   \n");
	printf("wight - %d\n", data->map->width);
	printf("height - %d\n", data->map->height);
	printf("player side - %c\n", data->map->player_side);
	printf("player x - %d\n", data->map->player_x);
	printf("player y - %d\n", data->map->player_y);
	print_string_array(data->map->map);
	printf("   --- MAP END ---   \n");
	printf("   --- DATA END ---   \n");
}

void	print(char *mes)
{
	printf("%s\n", mes);
}

void	print_param(t_param param)
{
	printf("--- OK --- param.camera_x = %f\n", param.camera_x);
	printf("--- OK --- param.ray_dir x = %f y = %f\n", param.ray_dir.x, param.ray_dir.y);
	printf("--- NORM --- param.map x = %d y = %d\n", param.map.x, param.map.y);
	printf("--- OK --- param.del_dist x = %f y = %f\n", param.del_dist.x, param.del_dist.y);
	printf("--- OK --- param.step x = %d y = %d\n", param.step.x, param.step.y);
	printf("param.tex_height = %d\n", param.tex_height);
	printf("param.draw_start = %d\n", param.draw_start);
	printf("param.draw_end = %d\n", param.draw_end);
	printf("param.side = %d\n", param.side);
	printf("param.wall_x = %f\n", param.wall_x);
	printf("param.tex_pos = %f\n", param.tex_pos);
	printf("param.step_len = %f\n", param.step_len);
	printf("param.dist_to_hit = %f\n", param.dist_to_hit);
	printf("param.side_dist x = %f y = %f\n", param.side_dist.x, param.side_dist.y);
	printf("param.tex x = %d y = %d\n", param.tex.x, param.tex.y);
	exit(0);
}
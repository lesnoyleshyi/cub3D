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
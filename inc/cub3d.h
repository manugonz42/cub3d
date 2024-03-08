#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "structs.h"
# include "defines.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <math.h>

//-----------------PARS---------------------------------------
// CHECK_WALLS_UTILS
int		check_first_or_last_row(char *line, t_game *game);
int		check_empty_map_line(char *line);
void	check_first_or_last_clmns(t_game *game);
void	n_of_rows(t_game *game);
void	n_of_cols(t_game *game);

// CHECK_WALLS
void	n_of_rows(t_game *game);
void	check_adjacent_cells(int i, int j, t_game *game);
void	check_wall_status(t_game *game);

// CLEAN_MATRIX_UTILS
char	**realloc_to_tabs(char **matrix);
void	add_spcs(char *s, int j);
int		clean_row_size(char *str);

// CLEAN_MATRIX
void	fill_new_str(char *new_str, char *str);
void	fill_new_matrix(char **matrix, char **new_matrix);
char	**tabs_to_spcs(t_game *game);
void	create_new_map_matrix(t_game *game);

// COLOR
int		create_trgb(int t, int r, int g, int b);
void	comma_case(char *line, int *i, int *commas, t_game *game);
void	check_color_format(char *line, t_game *game);
int		extract_color(char *line, t_game *game);
void	parse_color(char *line, t_game *game, int side);

// PARSE_UTILS
int		is_valid_map_char(char c);
void	check_line_map_format(char *line, t_game *game);
char	next_token(char *line, int i);
int		last_token(char *line, int i);
char	*save_texture_path(char *line, int i, t_game *game);

// PARSE_MAP
void	parse_texture(char *line, t_game *game, int side);
int		parse_line(char *line, t_game *game);
void	parse_map_line(char *line, t_game *game);
int		parse_map(t_game *game);

// SAVE_TEXTURE
void	no_case(t_game *game, char *path);
void	so_case(t_game *game, char *path);
void	we_case(t_game *game, char *path);
void	ea_case(t_game *game, char *path);
void	save_texture(char *line, t_game *game, int side, int i);

//-----------------PRINT_MAP----------------------------------
// CREATE_BACKGROUND
void    draw_background(t_game *game);
void	minimap_wall_case(t_game *game, int i, int j);
void	minimap_empty_case(t_game *game, int i, int j);
void	draw_map(t_game *game);

// DRAW_PJ
void	draw_pj(t_game *game);

// PRINT_MAP
void	draw_cell(t_game *game, char cell, int x, int y);
void	fill_minimap(t_game *game);
void	save_minimap(t_game *game);
void	draw_minimap(t_game *game);

//-----------------RAY_CASTING----------------------------------
// DRAW_RAY
void	draw_wall(int x, t_ray *ray_data, t_game *game);
void	draw_ray(int x, int y, int x2, int y2, t_image *image);

// START_RAY
double	to_rad(double angle);
void	init_ray_cast(t_game *game, double cell_height, double cell_width);

//-----------------UPDATE----------------------------------
// DRAW_NEXT_FRAME
void	print_frame(t_game *game);
int		draw_next_frame(t_game *game);

// UPDATE
void	update_player_pos(t_game *game);
void	update_ray(t_game *game);

//----------------SRC----------------------------------
// ERROR
int		ft_error_message(char *message, t_game *game);

// EXIT
void	destroy_game(t_game *game);
void	destroy_images(t_game *game);
void	free_sprites(t_game *game);
void	free_map(t_game *game);
int		ft_closed(t_game *game);

// HANDLE_INPUT
void	ft_move(t_game *game, int nx, int ny);
int		on_release_input(int keysym, t_game *game);
int		on_press_input(int keysym, t_game *game);

// INIT_PJ
void	set_starting_pj_direction(t_game *game, char c);
void	set_starting_pj_pos(t_game *game);
void	init_pj(t_game *game);

// INIT
void	init_mlx(t_game *game);
void	init_map(t_game *game, char *map);
void	init_sprites(t_game *game);
void	init_game(t_game *game, char *map);

float	adjust_angle(float ra);
float	ray_dist(float ax, float ay, float bx, float by);
void    create_background(t_game *game);
void    set_textures(t_game *game);
void	copy_texture(int *dst, int *src);
void	render_ray(t_game *game, t_ray *ray, int n);

#endif
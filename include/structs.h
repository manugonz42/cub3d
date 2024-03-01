#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_ray
{
	int		horizontal_hit;	
	double	horizontal_x_hit;
	double	horizontal_y_hit;
	double	horizontal_distance;
	double	vertical_hit;
	double	vertical_x_hit;
	double	vertical_y_hit;
	double	vertical_distance;
	int		up;
	int		left;
	double	y_intercept;
	double	x_intercept;
	double	y_step;
	double	x_step;
	double	next_horizontal_x;
	double	next_horizontal_y;
	double	next_vertical_x;
	double	next_vertical_y;
	double	wall_hit_x;
	double	wall_hit_y;
	double	adjacent;
	double	opposite;
	double	distance;
}	t_ray;

typedef struct		s_image
{
	void		*ptr;
	char		*addr;
	int			rgb;	
	int			bitsinpixel;	
	int			line_bytes;	
	int			endian;
	int			setted;	
}	t_image;

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_player
{
	double	x;
	double	y;
	double	ray;
	int		fov;
	int		mv_speed;
	double	rot_speed;
	int		moving;
	int		rotating;
	t_ray	*ray_data;

}	t_player;

typedef struct s_map
{
	char	**matrix;
	char	*raw_map;
	char	*cub_path;
	int		rows;
	int		cols;
	int		alloc;
	double	cell_height;
	double	cell_width;
	t_pos	*player_pos;
	t_ray	*ray;
}	t_map;

typedef struct	s_sprites
{
	t_image	*no;
	t_image	*so;
	t_image	*ea;
	t_image	*we;
	t_image	*f;
	t_image	*c;
}	t_sprites;

typedef struct s_minimap
{
	t_image	*img;
	int		width;
	int		height;
	int		cell_size;
}	t_minimap;

typedef struct s_game
{
	t_map		*map;
	void		*mlx_server;
	void		*mlx_window;
	int			c_count;
	int			alloc;
	int			width;
	int			height;
	t_sprites	sprites;
	t_image		*frame;
	t_minimap	*minimap;
	t_player	*player;
}				t_game;

#endif
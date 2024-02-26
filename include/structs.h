#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_ray
{
	int		horizontal_hit;	
	int		horizontal_x_hit;
	int		horizontal_y_hit;
	int		vertical_hit;
	int		vertical_x_hit;
	int		vertical_y_hit;
	int		up;
	int		left;
	int		y_intercept;
	int		x_intercept;
	int		y_step;
	int		x_step;
	int		next_horizontal_x;
	int		next_horizontal_y;
	double	adjacent;
	double	opposite;
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
	float	x;
	float	y;
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
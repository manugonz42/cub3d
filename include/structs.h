#ifndef STRUCTS_H
# define STRUCTS_H

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
	float	ray;
	float	fov;
}	t_player;

typedef struct s_map
{
	char	**matrix;
	char	*raw_map;
	char	*cub_path;
	int		rows;
	int		cols;
	int		alloc;
	t_pos	*player_pos;
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

typedef struct s_game
{
	t_map		*map;
	void		*mlx_server;
	void		*mlx_window;
	int			c_count;
	int			alloc;
	t_sprites	sprites;
	t_image		*frame;
	t_image		*mini_map;
}				t_game;

#endif
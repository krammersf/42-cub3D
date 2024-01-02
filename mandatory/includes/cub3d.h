/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:51:58 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/02 17:05:15 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* --=+=+=+=+=+=--> Libraries <--=+=+=+=+=+=-- */
# include "../../minilibx-linux/mlx.h"
# include "../../libft/include/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdbool.h>
# include <sys/time.h>

/* --=+=+=+=+=+=--> Messages <--=+=+=+=+=+=-- */
# define GAME_NAME "Cube3d --> made by fde-carv & blablaba"

/* --=+=+=+=+=+=--> Width and Height <--=+=+=+=+=+=-- */
# define SCREEN_WIDTH 1024 //800 // LARGURA
# define SCREEN_HEIGHT 768 //600 // ALTURA
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

/* --=+=+=+=+=+=--> Key Slots <--=+=+=+=+=+=-- */
# define MOVE_FORWARD 0
# define MOVE_BACKWARD 1
# define SLIDE_LEFT 2
# define SLIDE_RIGHT 3
# define ROTATE_LEFT 4
# define ROTATE_RIGHT 5

/* --=+=+=+=+=+=--> Structs <--=+=+=+=+=+=-- */
typedef struct s_texture
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				txt_w;
	int				txt_h;
}		t_texture;

typedef struct s_mlx
{
	char			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	struct s_game	*game_ptr;
}		t_mlx;

typedef struct s_rgb
{
	int				red;
	int				green;
	int				blue;
}		t_rgb;

typedef struct s_game
{
	int				key[6];
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rot_speed;
	double			move_margin;
	double			time;
	double			old_time;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			old_dir_x;
	double			old_plane_x;
	double			frame_time;
	int				fps;
	double			tps;
	int				texture_x;
	int				pitch;
	t_texture		*txt_ptr;
	struct s_map	*map_ptr;
	t_mlx			*mini_ptr;
}		t_game;

typedef struct s_map
{
	int				fd;
	int				ttl_nbr_lines;
	char			*extension;
	char			*get_line;
	char			*map_path;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	char			*floor_texture;
	char			*ceiling_texture;
	char			**world_map;
	double			wall_x;
	double			step;
	double			tex_pos;
	int				tex_y;
	int				inside_checked;
	int				map_start;
	int				map_end;
	int				line_nbr;
	int				map_copy_x;
	int				map_copy_y;
	int				has_player;
	int				f_color_bites;
	int				c_color_bites;
	t_game			*game_ptr;
	t_rgb			ceiling_colors;
	t_rgb			floor_colors;
}		t_map;

enum e_direction
{
	south = 0,
	north = 1,
	east = 2,
	west = 3
};

/* --@@@@@@@@@@@--> FUNCTIONS <--@@@@@@@@@@@-- */

/* --=+=+=+=+=+=--> Close <--=+=+=+=+=+=-- */
void		free_t_map(t_map *map);
//void		cleaning(t_game *game, t_map *map);
int			close_window(t_game *game);

/* --=+=+=+=+=+=--> Drawing <--=+=+=+=+=+=-- */
void		draw_floor(t_mlx *mini, int color);
void		draw_ceiling(t_mlx *mini, int color);
int			get_rgb(int red, int green, int blue);
void		background(t_mlx mini, int floor_color, int ceiling_color);
int			ft_pixel_get(t_texture *txt, int x, int y);
void		ft_pixel_put(t_mlx *mini, int x, int y, int color);
void		fps(t_game *game);
void		check_hit(t_game *game);
void		calculate_walls(t_game *game);
void		draw_walls(t_game *game, int *x);
void		get_bite_floor_color(t_map *map);
void		get_bite_ceiling_color(t_map *map);
void		render_frames_1(t_game *game, int *x);
void		render_frames_2(t_game *game, int *x);
int			render_frames_total(void *arg);

/* --=+=+=+=+=+=--> Init <--=+=+=+=+=+=-- */
void		init_game2(t_game *game, struct s_map *map_ptr, t_mlx *m);
void		init_game(t_game *game, struct s_map *map_ptr, t_mlx *m);
void		init_t_map(t_map *map, t_game *game);
void		init_mlx(t_mlx *map);
void		init_textures_img(t_game *game);
void		open_window(t_mlx *map, int screen_width,
				int screen_height, char *window_description);
void		close_free(char *msg, char **arr, t_map *map);
void		read_cub_file(t_map *map);

/* --=+=+=+=+=+=--> Move <--=+=+=+=+=+=-- */
int			handle_keypress(int keysym, t_game *game);
int			handle_keyrelease(int keysym, t_game *game);
void		move_p_forward(t_game *game);
void		move_p_backward(t_game *game);
void		move_p_slide_left(t_game *game);
void		move_p_slide_right(t_game *game);
void		rotate_p_right(t_game *game);
void		rotate_p_left(t_game *game);
void		move_player_forward(t_game *game);
void		move_player_backward(t_game *game);
void		move_player(t_game *game);

/* --=+=+=+=+=+=--> Parser <--=+=+=+=+=+=-- */
int			access_file(t_map *map);
void		access_path(t_map *map, char *texture);
void		perror_close(char *msg, t_map *map);
void		perror_close_fd(char *msg, t_map *map, int fd);
int			check_input(int ac, char *path_str, t_map *map);
int			check_elem_file(char *line);
void		check_elem_file_is_ok(char *line, char **arr, t_map *map);
int			check_elem_file(char *line);
void		check_elem_file_is_ok(char *line, char **arr, t_map *map);
bool		check_map_extension(t_map *map, char *filename);
char		**to_copy_map(t_map *map);
int			ft_begin_strlen(char *line);
int			find_first_zero(t_map *map, char **map_copy);
void		check_flood_fill(t_map *map, char **array, int y, int x);
void		check_map_integrity(t_map *map);
void		fill_t_rgb(t_rgb *rgb, char *red, char *green, char *blue);
void		define_rgb_colors(t_map *map, char **rgb, char *str);
void		check_floor_comma(t_map *map);
void		check_ceiling_comma(t_map *map);
void		check_elements(t_map *map, char *texture, char *c);
void		check_texture(t_map *map, char **texture,
				char **dir, char **line_arr);
void		get_elements_textures(t_map *map, char **line_arr);
char		*get_texture(char *line);
void		get_elements_colors_textures(t_map *map, char **line_arr);
void		check_textures_paths(t_map *map);
void		get_elements(t_map *map);
void		get_map_size(t_map *map);
void		set_start_ns(char c, t_game *game);
void		set_start(double x, double y, char c, t_map *map);
bool		is_valid_char(char c);
void		get_map_to_array_while_get_line(t_map *map, int x, int y);
void		get_map_to_array(t_map *map);
void		get_ttl_nbr_lines(t_map *map);

/* --=+=+=+=+=+=--> Utils <--=+=+=+=+=+=-- */
void		free_arr(char **arr, t_map *m);
void		free_arr1(char **arr);
void		free_total(char **arr, char *str);
int			get_arr_size(char **arr);
bool		is_direction(char c);
bool		is_valid_colors(t_rgb *colors);
long long	get_actual_time(void);


char		*get_next_line(int fd);


/* --=+=+=+=+=+=--> Debug (in utils) <--=+=+=+=+=+=-- */
//void		ft_print_array(char **arr, int nb_lines);
//void		ft_print_t_map(t_map *map);

#endif
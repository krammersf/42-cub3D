/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:51:58 by fde-carv          #+#    #+#             */
/*   Updated: 2024/01/29 18:37:06 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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
# define GAME_NAME "Cube3D_bonus --> made by fde-carv & fernacar"

/* --=+=+=+=+=+=--> Width and Height <--=+=+=+=+=+=-- */
# define SCREEN_WIDTH 1024 //800 //1024 // LARGURA
# define SCREEN_HEIGHT 768 //600 //768 // ALTURA
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

/* --=+=+=+=+=+=--> Key Slots <--=+=+=+=+=+=-- */
# define MOVE_FORWARD 0
# define MOVE_BACKWARD 1
# define SLIDE_LEFT 2
# define SLIDE_RIGHT 3
# define ROTATE_LEFT 4
# define ROTATE_RIGHT 5
# define INTERACT 6

/* --=+=+=+=+=+=--> Structs <--=+=+=+=+=+=-- */

typedef struct s_littlemap
{
	double			start_x;
	double			start_y;
	double			end_x;
	double			end_y;
	int				x;
	int				y;
	double			x_center;
	double			y_center;
	int				line_length;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
	int				x2;
	int				y2;
	char			**little_map;
}		t_littlemap;

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
	int				key[7];
	int				mouse_x;
	int				mouse_y;
	int				mouse_lock;
	int				mouse_lock_x_pos;
	int				mouse_lock_y_pos;
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
	t_texture		*txt_ptr;
	struct s_map	*map_ptr;
	t_mlx			*mini_ptr;
	int				red;
	int				green;
	int				blue;
	t_littlemap		*littlemap_ptr;
	t_texture		*txt_hands;
	int				press_e;
	int				swap_hands;
	int				press_k;
	int				press_l;
}		t_game;

typedef struct s_map
{
	int				fd;
	int				total_nbr_lines;
	char			*extension;
	char			*get_line;
	char			*map_path;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	char			*floor_texture;
	char			*ceiling_texture;
	char			*door_texture;
	char			**world_map;
	double			wall_x;
	double			step;
	double			tex_pos;
	int				tex_y;
	int				inside_checked;
	int				doors_checked;
	int				map_start;
	int				map_end;
	int				map_width;
	int				line_nbr;
	int				map_copy_x;
	int				map_copy_y;
	int				has_player;
	int				f_color_bites;
	int				c_color_bites;
	t_game			*game_ptr;
	t_rgb			ceiling_colors;
	t_rgb			floor_colors;
	int				larger_line;
	char			**animated_hands;
	time_t			start_time_hand;
	time_t			current_time;
	time_t			start_time_change;
	char			*aaa_texture;
	char			*bbb_texture;
	char			*ccc_texture;
	char			*ddd_texture;
}		t_map;

typedef struct s_hands
{
	int					x;
	int					y;
	double				a;
	double				b;
	double				begin_x;
	double				begin_y;
}						t_hands;

enum e_direction
{
	south = 0,
	north = 1,
	east = 2,
	west = 3,
	door = 4,
	aaa = 5,
	bbb = 6,
	ccc = 7,
	ddd = 8,
};

/* --@@@@@@@@@@@--> FUNCTIONS <--@@@@@@@@@@@-- */

/* --=+=+=+=+=+=--> Close <--=+=+=+=+=+=-- */
void			free_t_map(t_map *map);
int				close_window(t_game *game);
void			error_close(char *msg, t_map *map);
void			error_close_fd(char *msg, t_map *map, int fd);

/* --=+=+=+=+=+=--> Drawing <--=+=+=+=+=+=-- */
void			draw_floor(t_mlx mini, int color);
void			draw_ceiling(t_mlx mini, int color);
int				get_rgb(int red, int green, int blue);
void			background(t_mlx mini, int floor_color, int ceiling_color);
int				ft_pixel_get(t_texture *txt, int x, int y);
void			ft_pixel_put(t_mlx *mini, int x, int y, int color);
void			fps(t_game *game);
void			check_hit(t_game *game);
void			calculate_walls(t_game *game);
void			draw_walls(t_game *game, int *x);
void			get_bite_floor_color(t_map *map);
void			get_bite_ceiling_color(t_map *map);
void			render_frames_1(t_game *game, int *x);
void			render_frames_2(t_game *game, int *x);
int				render_frames_total(void *arg);

/* --=+=+=+=+=+=--> Init <--=+=+=+=+=+=-- */
void			init_game2(t_game *game, struct s_map *map_ptr, t_mlx *m);
void			init_game(t_game *game, struct s_map *map_ptr, t_mlx *m);
void			init_t_map(t_map *map, t_game *game);
void			init_mlx(t_mlx *map);
void			init_textures_img(t_game *game);
void			open_window(t_mlx *map, int screen_width,
					int screen_height, char *window_description);
void			close_free(char *msg, char **arr, t_map *map);
void			read_cub_file(t_map *map);
void			set_start_position(char c, t_game *game);
void			set_start(double x, double y, char c, t_map *map);

/* --=+=+=+=+=+=--> Move <--=+=+=+=+=+=-- */
int				handle_keypress(int keysym, t_game *game);
int				handle_keyrelease(int keysym, t_game *game);
int				handle_mouse_movement(int x, int y, t_mlx *mlx);
int				handle_mouse_click_down(int button, int x, int y, t_mlx *mlx);
void			move_p_forward(t_game *game);
void			move_p_backward(t_game *game);
void			move_p_slide_left(t_game *game);
void			move_p_slide_right(t_game *game);
void			rotate_p_right(t_game *game);
void			rotate_p_left(t_game *game);
void			rotate_p_mouse(t_game *game, double amount);
void			move_player_forward(t_game *game);
void			move_player_backward(t_game *game);
void			move_player(t_game *game);

/* --=+=+=+=+=+=--> Parser <--=+=+=+=+=+=-- */
int				access_file(t_map *map);
void			access_path(t_map *map, char *texture);
int				check_input(int ac, char *path_str, t_map *map);
int				check_elem_file(char *line);
void			check_elem_file_is_ok(char *line, char **arr, t_map *map);
int				check_elem_file(char *line);
void			check_elem_file_is_ok(char *line, char **arr, t_map *map);
bool			check_map_extension(t_map *map, char *filename);
char			**to_copy_map(t_map *map);
int				ft_begin_strlen(char *line);
int				find_first_zero(t_map *map, char **map_copy);
void			check_flood_fill(t_map *map, char **array, int y, int x);
void			check_map_integrity(t_map *map);
int				fill_t_rgb_ckeck_rgb_size(t_rgb *rgb, char *red, \
					char *green, char *blue);
void			define_rgb_colors(t_map *map, char **rgb, char *str);
void			check_floor_comma(t_map *map);
void			check_ceiling_comma(t_map *map);
void			check_elements(t_map *map, char *texture, char *c);
void			check_texture(t_map *map, char **texture,
					char **dir, char **line_arr);
void			get_elements_textures(t_map *map, char **line_arr);
char			*get_texture(char *line);
void			get_elements_colors_textures(t_map *map, char **line_arr);
void			check_textures_paths(t_map *map);
void			get_elements(t_map *map);
void			get_map_size(t_map *map);
bool			is_valid_char(char c);
void			get_map_to_array_cheks_player_char(t_map *map, int x, int y);
void			get_map_to_array(t_map *map);
void			get_total_nbr_lines(t_map *map);
void			pad_line_width(char **world_map, int index, int max_width);

/* --=+=+=+=+=+=--> Utils <--=+=+=+=+=+=-- */
void			free_arr(char **arr, t_map *m);
void			free_arr1(char **arr);
void			free_arr2(char **arr, int size);
void			free_total(char **arr, char *str);
int				get_arr_size(char **arr);
bool			is_player(char c);
bool			is_valid_colors(t_rgb *colors);
long long		get_actual_time(void);
void			get_new_floor(t_game *game);

/* --=+=+=+=+=+=--> Littlemap <--=+=+=+=+=+=-- */
void			set_larger_line(t_game *game);
void			fill_lines_little_map(t_game *game, int i, int end);
char			*fill_end(int size);
void			add_spaces(t_game *game);
unsigned int	put_color(char c);
void			draw_rectangle(t_game *game, int x, int y, unsigned int color);
void			draw_final_rectangle(char c, t_game *game, int x, int y);
void			get_littlemap(t_game *game);
void			draw_line_l_player(t_game *game, t_littlemap littlemap, \
					int x2, int y2);
void			draw_square_little_player(t_mlx *mlx, int x, int y, \
					int side_length);
void			init_littlemap_struct(t_littlemap *littlemap, t_game *game);
void			draw_little_player(t_game *game);
void			draw_littlemap_complete(t_game *game);
void			draw_hands(t_game *game);
void			img_hands(t_game *game);
void			draw_walls2(t_game *game, int *x);
void			change_color(t_game *game);
int				handle_keypress2(int keycode_mlx, t_game *game);
void			init_change_color(t_game *game);
void			init_new_textures_bonus(t_map *map, t_game *game);

void			init_textures_extra_img(t_game *game);

bool			dont_hit(t_game *game);

void			load_texture(t_game *game);
void			draw_pixel_aaa(t_game *game, int *x, int y, int tex_y);
void			draw_pixel_bbb(t_game *game, int *x, int y, int tex_y);
void			draw_pixel_south(t_game *game, int *x, int y, int tex_y);
void			draw_pixel_north(t_game *game, int *x, int y, int tex_y);
void			draw_pixel_east(t_game *game, int *x, int y, int tex_y);
void			draw_walls3(t_game *game, int *x);
void			draw_walls4(t_game *game, int *x);
void			draw_pixel_west(t_game *game, int *x, int y, int tex_y);
void			draw_pixel_ccc(t_game *game, int *x, int y, int tex_y);
void			draw_pixel_ddd(t_game *game, int *x, int y, int tex_y);
void			time_change(t_game *game, int *x, int y, int tex_y);
void			wall_change(t_game *game, int *x, int y, int tex_y);

/* --=+=+=+=+=+=--> Debug (in utils) <--=+=+=+=+=+=-- */
void			ft_print_array(char **arr, int nb_lines);
void			ft_print_t_map(t_map *map);

void			ft_maps(t_map *map);

#endif
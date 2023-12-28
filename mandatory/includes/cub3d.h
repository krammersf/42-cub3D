/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:51:58 by fde-carv          #+#    #+#             */
/*   Updated: 2023/12/28 22:31:40 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../minilibx-linux/mlx.h"
# include "../../libft/include/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdbool.h>
# include <sys/time.h>
//# include <stdint.h>
//# include <fcntl.h>

# define SCREEN_WIDTH 1024 //800 // LARGURA
# define SCREEN_HEIGHT 768 //600 // ALTURA
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define GAME_NAME "Cube3d --> by ... fde-carv + blablaba"

typedef struct s_texture
{
	void		*img;//OK
	char		*addr;//OK
	int			bits_per_pixel;//OK
	int			line_length;//OK
	int			endian;//OK
	int			txt_w;//OK
	int			txt_h;//OK
}	t_texture;

typedef struct s_mlx
{
	char			*mlx;//OK
	void			*mlx_win;//OK
	void			*img;//OK
	char			*addr;//OK
	int				bits_per_pixel;//OK
	int				line_length;//OK
	int				endian;//OK
	struct s_game	*game_ptr;//OK
}	t_mlx;

typedef struct s_rgb
{
	int		red;//OK
	int		green;//OK
	int		blue;//OK
}	t_rgb;

typedef struct s_game
{
	int				move_up;
	int				move_down;
	int				move_left;
	int				move_right;
	int				slide_left;
	int				slide_right;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;//OK
	double			plane_y;//OK
	double			move_speed;//OK
	double			rot_speed;//OK
	double			move_margin;//OK
	double			time;//OK
	double			old_time;//OK
	double			camera_x;//OK
	double			ray_dir_x;//OK
	double			ray_dir_y;//OK
	int				map_x;//OK
	int				map_y;//OK
	double			side_dist_x;//OK
	double			side_dist_y;//OK
	double			delta_dist_x;//OK
	double			delta_dist_y;//OK
	double			perp_wall_dist;//OK
	int				step_x;//OK
	int				step_y;//OK
	int				hit;//OK
	int				side;//OK
	int				line_height;//OK
	int				draw_start;//OK
	int				draw_end;//OK
	double			old_dir_x;
	double			old_plane_x;
	double			frame_time;//OK
	int				fps;//OK
	double			tps;//OK
	int				texture_x;//OK
	int				pitch;//OK
	t_texture		*txt_ptr;//OK
	struct s_map	*map_ptr;//OK
	t_mlx			*mini_ptr;//OK
}	t_game;

typedef struct s_map
{
	int			fd;//OK
	int			ttl_nbr_lines;
	char		*extension;//OK
	char		*get_line;//OK
	char		*map_path;//OK
	char		*north_texture;//OK
	char		*south_texture;//OK
	char		*west_texture;//OK
	char		*east_texture;//OK
	char		*floor_texture;//OK
	char		*ceiling_texture;//OK
	char		**world_map;
	double		wall_x;
	double		step;//OK
	double		tex_pos;//OK
	int			tex_y;//OK
	//char		start_dir;
	//int			nbr;
	//int			comma;
	//int			rest;
	//int			border_begin_x;
	//int			border_begin_y;
	int			inside_checked;//OK
	int			map_start;//OK
	int			map_end;//OK
	int			line_nbr;//OK
	int			map_copy_x;//OK
	int			map_copy_y;//OK
	int			has_player;//OK
	t_game		*game_ptr;
	//long long	color;
	t_rgb		ceiling_colors;
	t_rgb		floor_colors;
	int			f_color;//cores in bites
	int			c_color;//cores in bites
}	t_map;

enum e_direction
{
	south = 0,
	north = 1,
	east = 2,
	west = 3
};

/*-----> Utils <-----*/
void		free_arr(char **arr, t_map *m);//
void		free_arr1(char **arr);//
void		free_total(char **arr, char *str);//
int			get_arr_size(char **arr);//
bool		is_valid_colors(t_rgb *colors);//
bool		is_direction(char c);//
long long	get_actual_time(void);//
void		access_path(t_map *map, char *texture);//

/*-----> Init <-----*/
void		close_free(char *msg, char **arr, t_map *map);
void		init_t_map(t_map *m, t_game *d);

/*-----> Cub3d <-----*/
void		ft_pixel_put(t_mlx *game, int x, int y, int color);
void		open_window(t_mlx *m, int screen_width, int screen_height, \
	char *window_description);
int			handle_keypress(int keysym, t_mlx *m);
int			handle_keyrelease(int keysym, t_mlx *m);
int			close_window(t_game *d);
void		init_game(t_game *d, struct s_map *map_ptr, t_mlx *m);
int			render_frames_total(void *arg);
void		render_frames_2(t_game *game, int *x);
void		background(t_mlx m, int ground_color, int sky_color);
void		init_textures_img(t_game *d);
void		init_mlx(t_mlx *m);
void		perror_close(char *msg, t_map *map);
void		perror_close_fd(char *msg, t_map *map, int fd);
void		perror_close_2mgs(char *msg1, char *msg2, t_map *map);
void		check_map_integrity(t_map *map);
int			ft_pixel_get(t_texture *txt, int x, int y);

/*-----> Drawing <-----*/
int			get_rgb(int red, int green, int blue);

/*-----> Parser <-----*/
void		read_cub_file(t_map *map);
int			access_file(t_map *map);
bool		check_map_extension(t_map *map, char *filename);
void		get_elements(t_map *map);
void		get_map_size(t_map *map);
void		get_map_to_array(t_map *map);
void		get_ttl_nbr_lines(t_map *map);
int			check_input(int ac, char *path_str, t_map *m);
void		check_flood_fill(t_map *map, char **floor, int i, int j);
char		*get_texture(char *line);
void		get_elements_textures(t_map *map, char **line_arr);
void		check_elem_file_is_ok(char *line, char **arr, t_map *m);
int			check_elem_file(char *line);

void		define_rgb_colors(t_map *map, char **rgb, char *str);
void		check_floor_comma(t_map *map);
void		check_ceiling_comma(t_map *map);
void		check_elements(t_map *map, char *texture, char *c);







/*-----> Player Movement <-----*/
void		move_p_up(t_mlx *m);
void		move_p_down(t_mlx *m);
void		move_p_left(t_mlx *m);
void		move_p_right(t_mlx *m);
void		move_p_slide_left(t_mlx *m);
void		move_p_slide_right(t_mlx *m);
void		move_player(t_game *game);

/*-----> Debug <-----*/
void		ft_print_array(char **arr, int nb_lines);
void		t_print_t_map(t_map *m);

#endif
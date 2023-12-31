# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 14:49:49 by fde-carv          #+#    #+#              #
#    Updated: 2023/12/31 12:05:05 by fde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	cub3d
NAME_BONUS 		=	cub3d_bonus
CC 				=	cc
FLAGS			=	-Wall -Wextra -Werror -Wno-unused-result -g #-fsanitize=address
MLXFLAGS		=	-lmlx -lXext -lX11 -lm -lz -lbsd
RM				=	rm -f
SRCDIR			=	mandatory/srcs
SRCDIR_BONUS	=	bonus/srcs_bonus
OBJSDIR			=	mandatory/objs
OBJSDIR_BONUS	=	bonus/objs_bonus
LIBFT			=	./libft/libft.a
LIBFT_DIR		=	./libft
MLX_DIR			=	./minilibx-linux

# ---===== COLORS =====--- #
RESET			=	\033[0m
BLACK 			=	\033[1;30m
RED 			=	\033[1;31m
GREEN 			=	\033[1;32m
YELLOW 			=	\033[1;33m
BLUE			=	\033[1;34m
PURPLE 			=	\033[1;35m
CYAN 			=	\033[1;36m
WHITE 			=	\033[1;37m
SBLINK			=	\033[5m
FBLINK			=	\033[6m

# ---===== SOURCE FILES =====--- #
SRCS			=	main.c\
					init/read_cub_file.c\
					init/init_data.c\
					init/open_window.c\
					init/init_textures_img.c\
					drawing/background.c\
					drawing/ft_pixel.c\
					drawing/making_walls.c\
					drawing/render_frames.c\
					utils/free_arr.c\
					utils/some_utils.c\
					move/move_player.c\
					move/handle_keypress.c\
					move/handle_player_keys_1.c\
					move/handle_player_keys_2.c\
					close/close_window.c\
					parser/check_map_integrity.c\
					parser/get_map_size.c\
					parser/access_file.c\
					parser/get_ttl_nbr_lines.c\
					parser/get_elements.c\
					parser/check_input.c\
					parser/check_map_extension.c\
					parser/get_map_to_array.c\
					parser/get_elements_textures.c\
					parser/check_line.c\
					parser/get_colors.c

SRCS_BONUS		=	main_bonus.c\
					parser/check_input_bonus.c\
					parser/check_map_integrity_bonus.c\
					parser/check_line_bonus.c\
					parser/get_ttl_nbr_lines_bonus.c\
					parser/get_map_size_bonus.c\
					parser/get_map_to_array_bonus.c\
					parser/get_elements_bonus.c\
					parser/access_file_bonus.c\
					parser/get_elements_textures_bonus.c\
					parser/check_map_extension_bonus.c\
					parser/set_start_bonus.c\
					move/move_player_bonus.c\
					move/handle_player_keys_bonus.c\
					move/handle_keypress_bonus.c\
					move/handle_mouse_bonus.c\
					drawing/render_frames_bonus.c\
					drawing/render_frames2_bonus.c\
					drawing/background_bonus.c\
					drawing/ft_pixel_put_bonus.c\
					drawing/ft_pixel_get_bonus.c\
					drawing/minimap_utils_bonus.c\
					drawing/minimap_array_bonus.c\
					drawing/minimap_bonus.c\
					drawing/draw_utils_bonus.c\
					drawing/draw_hands_bonus.c\
					drawing/draw_head_hud_bonus.c\
					drawing/sprites_bonus.c\
					drawing/draw_doors_bonus.c\
					drawing/draw_doors2_bonus.c\
					init/open_window_bonus.c\
					init/read_cub_file_bonus.c\
					init/init_textures_bonus.c\
					init/init_textures_extra_bonus.c\
					init/init_extra_sprites_bonus.c\
					init/init_data_bonus.c\
					init/init_imgs_bonus.c\
					close/close_window_bonus.c\
					utils/ft_strjoin_bonus.c\
					utils/get_next_line_bonus.c\
					utils/ft_strnstr_bonus.c\
					utils/get_array_size_bonus.c\
					utils/ft_isdigit_bonus.c\
					utils/ft_strlen_bonus.c\
					utils/ft_itoa_bonus.c\
					utils/flood_fill_bonus.c\
					utils/ft_is_numeric_bonus.c\
					utils/ft_atoi_bonus.c\
					utils/is_valid_colors_bonus.c\
					utils/ft_strdup_bonus.c\
					utils/ft_strchr_bonus.c\
					utils/ft_strncmp_bonus.c\
					utils/ft_calloc_bonus.c\
					utils/ft_bzero_bonus.c\
					utils/ft_split_set_bonus.c\
					utils/ft_strcmp_bonus.c\
					utils/ft_memcpy_bonus.c\
					utils/ft_split_bonus.c\
					utils/ft_strtrim_bonus.c\
					utils/ft_put_nbr_bonus.c\
					utils/time_bonus.c\
					utils/utils_list_bonus.c\
					utils/ft_substr_bonus.c\
					utils/is_direction_bonus.c\
					utils/is_only_digit_or_comma_bonus.c\
					utils/free_arr_bonus.c\

# ---===== CREATE OBJS =====--- #
OBJS			=	${SRCS:%.c=${OBJSDIR}/%.o}
OBJS_BONUS		=	${SRCS_BONUS:%.c=${OBJSDIR_BONUS}/%.o}

all: 				${NAME}

# ---===== MANDATORY =====--- #
${NAME}:			${OBJS}
					@${MAKE} -C ${LIBFT_DIR} > /dev/null 2>&1
					@${MAKE} -C ${MLX_DIR} > /dev/null 2>&1
					@${CC} ${OBJS} -L${MLX_DIR} ${LIBFT} ${MLXFLAGS} ${FLAGS} -o ${NAME}
					@echo "[${BLUE}Object LIBFT files ${WHITE}] ${GREEN}--> created${WHITE}"
					@echo "[${BLUE}MINILIBIX files${WHITE}] ${GREEN}--> created${WHITE}"
					@echo "\n[${WHITE}${YELLOW}$(SBLINK)$$(echo ${NAME} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${GREEN}--> created${RESET}\n"

${OBJS}:			${OBJSDIR}/%.o: ${SRCDIR}/%.c 
					@mkdir -p $(@D)
					@${CC} ${FLAGS} -I. -O3 -c $< -o $@
					@echo "[${CYAN}Object $(basename $(notdir $@)) files${WHITE}] ${GREEN}--> created${WHITE}"

# ---===== BONUS =====--- #
bonus: 				${NAME_BONUS}

${NAME_BONUS}:		${OBJS_BONUS}
					@${MAKE} -C ${LIBFT_DIR} > /dev/null 2>&1
					@${MAKE} -C ${MLX_DIR} > /dev/null 2>&1
					${CC} ${OBJS_BONUS} -L${MLX_DIR} ${LIBFT} ${MLXFLAGS} ${FLAGS} -o ${NAME_BONUS}
					@echo "[${BLUE}Object LIBFT files ${WHITE}] ${GREEN}--> created${WHITE}"
					@echo "[${BLUE}MINILIBIX files${WHITE}] ${GREEN}--> created${WHITE}"
					@echo "\n[${WHITE}${YELLOW}$(SBLINK)$$(echo ${NAME} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${GREEN}--> created${RESET}\n"

${OBJS_BONUS}:		${OBJSDIR_BONUS}/%.o: ${SRCDIR_BONUS}/%.c
					@mkdir -p $(@D)
					${CC} ${FLAGS} -I. -O3 -c $< -o $@
					@echo "[${CYAN}Object $(basename $(notdir $@)) files${WHITE}] ${GREEN}--> created${WHITE}"

clean:
					@${RM} -rf ${OBJSDIR} > /dev/null 2>&1
					@${RM} -rf ${OBJSDIR_BONUS} > /dev/null 2>&1
					@${MAKE} clean -C ${LIBFT_DIR} > /dev/null 2>&1
					@${MAKE} clean -C ${MLX_DIR} > /dev/null 2>&1
					@echo "\n[${WHITE}${CYAN}Object Files$(RESET)${WHITE}] ${RED}--> removed${RESET}"
					@echo "[${WHITE}${BLUE}Object LIBFT Files$(RESET)${WHITE}] ${RED}--> removed${RESET}"
					@echo "[${WHITE}${BLUE}MINILIBIX files$(RESET)${WHITE}] ${RED}--> removed${RESET}\n"

fclean:				clean
					@${RM} ${NAME} > /dev/null 2>&1
					@${RM} ${NAME_BONUS} > /dev/null 2>&1
					@${MAKE} fclean -C ${LIBFT_DIR} > /dev/null 2>&1
					@echo "[${WHITE}${YELLOW}$(SBLINK)$$(echo ${NAME} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${RED}--> removed${RESET}\n"

fclean2:			clean
					@${RM} ${NAME} > /dev/null 2>&1
					@${RM} ${NAME_BONUS} > /dev/null 2>&1
					@${MAKE} fclean -C ${LIBFT_DIR} > /dev/null 2>&1
					@echo "[${WHITE}${YELLOW}$(SBLINK)$$(echo ${NAME} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${RED}--> removed${RESET}\n"
					@rm -rf minilibx-linux > /dev/null 2>&1
					@rm -f output.log
					@rm -f lista_mandatory.txt
					@rm -f lista_bonus.txt
					@echo "[${WHITE}${BLUE}MINILIBIX files$(RESET)${WHITE}] ${RED}--> $(SBLINK)ERASED${RESET}\n"

download:
					@wget https://cdn.intra.42.fr/document/document/22624/minilibx-linux.tgz > /dev/null 2>&1
					@tar -xzf minilibx-linux.tgz > /dev/null 2>&1
					@rm minilibx-linux.tgz
					@echo "\n[${WHITE}${BLUE}MINILIBIX files$(RESET)${WHITE}] ${GREEN}--> $(SBLINK)Downloaded and Ready${RESET}\n"

re:					fclean all

# rebonus:			fclean bonus

leaks:
					@echo "$(PURPLE)\n $(SBLINK)VALGRIND${RESET} $(PURPLE)is running with all the 🚩s 🔛 ...${RESET}\n"
					@valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes --log-file=output.log  ./cub3d ./mandatory/maps/good/dungeon.cub
				
norm:
					@norminette -R CheckForbiddenSourceHeader > /dev/null 2>&1
					@norminette -R CheckDefine includes > /dev/null 2>&1
					@norminette -R . > /dev/null 2>&1
					@echo "$(GREEN)\n*** >>>  NORMINETTE is OK  <<< ***${RESET}\n"

norm2:
					@norminette -R CheckForbiddenSourceHeader
					@norminette -R CheckDefine
					@norminette -R .
					@echo "$(GREEN)\n*** >>>  NORMINETTE is OK  <<< ***${RESET}\n"	

.PHONY: 			all bonus clean fclean re rebonus

#.SILENT:
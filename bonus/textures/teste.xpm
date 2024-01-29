# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 14:49:49 by fde-carv          #+#    #+#              #
#    Updated: 2024/01/28 21:41:04 by fde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	cub3D
NAME_BONUS 		=	cub3D_bonus
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
					init/set_start.c\
					drawing/background.c\
					drawing/ft_pixel.c\
					drawing/making_walls.c\
					drawing/render_frames.c\
					move/move_player.c\
					move/handle_keypress.c\
					move/handle_player_keys_1.c\
					move/handle_player_keys_2.c\
					close/close_window.c\
					close/error.c\
					parser/access_file.c\
					parser/check_line.c\
					parser/check_map_extension.c\
					parser/check_map_integrity.c\
					parser/get_colors.c\
					parser/get_elements_textures.c\
					parser/get_elements.c\
					parser/get_map_size.c\
					parser/get_map_to_array.c\
					utils/free_arr.c\
					utils/some_utils.c\
										
SRCS_BONUS		=	main_bonus.c\
					init/read_cub_file_bonus.c\
					init/init_data_bonus.c\
					init/open_window_bonus.c\
					init/init_textures_img_bonus.c\
					init/set_start_bonus.c\
					drawing/background_bonus.c\
					drawing/ft_pixel_bonus.c\
					drawing/making_walls1_bonus.c\
					drawing/render_frames_bonus.c\
					move/move_player_bonus.c\
					move/handle_keypress_bonus.c\
					move/handle_player_keys_1_bonus.c\
					move/handle_player_keys_2_bonus.c\
					close/close_window_bonus.c\
					close/error_bonus.c\
					parser/access_file_bonus.c\
					parser/check_line_bonus.c\
					parser/check_map_extension_bonus.c\
					parser/check_map_integrity_bonus.c\
					parser/get_colors_bonus.c\
					parser/get_elements_textures_bonus.c\
					parser/get_elements_bonus.c\
					parser/get_map_size_bonus.c\
					parser/get_map_to_array_bonus.c\
					utils/free_arr_bonus.c\
					utils/some_utils_bonus.c\
					littlemap/little_player_bonus.c\
					littlemap/littlemap_bonus.c\
					littlemap/rectangle1_bonus.c\
					littlemap/rectangle2_bonus.c\
					drawing/draw_hands.c\
					drawing/making_walls_color_bonus.c\
					drawing/render_frames2_bonus.c\
					drawing/making_walls2_bonus.c\
					parser/check_doors.c\
					parser/get_map_to_array2_bonus.c\
					drawing/making_walls3_bonus.c\
					drawing/making_walls4_bonus.c\
					
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
					@${CC} ${OBJS_BONUS} -L${MLX_DIR} ${LIBFT} ${MLXFLAGS} ${FLAGS} -o ${NAME_BONUS}
					@echo "[${BLUE}Object LIBFT files ${WHITE}] ${GREEN}--> created${WHITE}"
					@echo "[${BLUE}MINILIBIX files${WHITE}] ${GREEN}--> created${WHITE}"
					@echo "\n[${WHITE}${YELLOW}$(SBLINK)$$(echo ${NAME_BONUS} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${GREEN}--> created${RESET}\n"

${OBJS_BONUS}:		${OBJSDIR_BONUS}/%.o: ${SRCDIR_BONUS}/%.c
					@mkdir -p $(@D)
					@${CC} ${FLAGS} -I. -O3 -c $< -o $@
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
					@echo "[${WHITE}${YELLOW}$(SBLINK)$$(echo ${NAME_BONUS} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${RED}--> removed${RESET}\n"
					
fclean2:			
					@${RM} -rf ${OBJSDIR} > /dev/null 2>&1
					@${RM} -rf ${OBJSDIR_BONUS} > /dev/null 2>&1
					@${RM} ${NAME} > /dev/null 2>&1
					@${RM} ${NAME_BONUS} > /dev/null 2>&1
					@${MAKE} clean -C ${LIBFT_DIR} > /dev/null 2>&1
					@${MAKE} clean -C ${MLX_DIR} > /dev/null 2>&1
					@echo "[${WHITE}${BLUE}Object LIBFT Files$(RESET)${WHITE}] ${RED}--> removed${RESET}"
					@echo "[${WHITE}${BLUE}MINILIBIX files$(RESET)${WHITE}] ${RED}--> removed${RESET}\n"
					@echo "[${WHITE}${YELLOW}$(SBLINK)$$(echo ${NAME} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${RED}--> removed${RESET}\n"
					@echo "[${WHITE}${YELLOW}$(SBLINK)$$(echo ${NAME_BONUS} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${RED}--> removed${RESET}\n"
					@rm -rf minilibx-linux > /dev/null 2>&1
					@rm -rf cub3D_map_tester > /dev/null 2>&1
					@rm -f output.log
					@rm -f lista_mandatory.txt
					@rm -f lista_bonus.txt
					@echo "[${WHITE}${BLUE}MINILIBIX files$(RESET)${WHITE}] ${RED}--> $(SBLINK)ERASED${RESET}\n"

download:
					@wget https://cdn.intra.42.fr/document/document/22624/minilibx-linux.tgz > /dev/null 2>&1
					@tar -xzf minilibx-linux.tgz > /dev/null 2>&1
					@rm minilibx-linux.tgz
					@echo "\n[${WHITE}${BLUE}MINILIBIX files$(RESET)${WHITE}] ${GREEN}--> $(SBLINK)Downloaded and Ready${RESET}\n"
					
download2:
					@rm -rf cub3D_map_tester > /dev/null 2>&1
					@git clone https://github.com/humblEgo/cub3D_map_tester.git > /dev/null 2>&1
					@echo "\n[${WHITE}${BLUE}cub3D Map Tester$(RESET)${WHITE}] ${GREEN}--> $(SBLINK)Downloaded and Ready${RESET}\n"
					@echo "${WHITE} To use: cd cub3D_map_testter$(RESET)\n"
					@echo "${WHITE} ./test_map_valid_function.sh$(RESET)\n"
					@echo "${WHITE} Answers 1-> n  2-> y  3 -> y $(RESET)\n"

re:					fclean all

rebonus:			fclean bonus

leaks:
					@echo "$(PURPLE)\n $(SBLINK)VALGRIND${RESET} $(PURPLE)is running with all the 🚩s 🔛 ...${RESET}\n"
					@valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes --log-file=output.log  ./cub3D ./mandatory/maps/good/dungeon.cub

leaks2:
					@echo "$(PURPLE)\n $(SBLINK)VALGRIND${RESET} $(PURPLE)is running with all the 🚩s 🔛 ...${RESET}\n"
					@valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes --log-file=output.log  ./cub3D_bonus ./bonus/maps/good/dungeon.cub

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

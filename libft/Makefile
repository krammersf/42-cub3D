# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 17:49:20 by fde-carv          #+#    #+#              #
#    Updated: 2023/12/28 15:55:15 by fde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
HDR = -I include
SRC_DIR = srcs
OBJ_DIR = objs
SUBDIRS = ctype extra lst math stdlib string strings printf gnl

SRCS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(SRC_DIR)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(OBJ_DIR)/, $(dir)))
SRCS	=	srcs/strings/ft_memccpy.c srcs/strings/ft_memcmp.c srcs/strings/ft_bzero.c srcs/strings/ft_memchr.c srcs/strings/ft_memset.c \
			srcs/strings/ft_memcpy.c srcs/strings/ft_memmove.c srcs/string/ft_strlcat.c srcs/string/ft_strnstr.c srcs/string/ft_strlcpy.c \
			srcs/string/ft_strncpy.c srcs/string/ft_strcpy.c srcs/string/ft_strlen.c srcs/string/ft_strdup.c srcs/string/ft_strchr.c \
			srcs/string/ft_strcat.c srcs/string/ft_strncmp.c srcs/string/ft_strlen_2d.c srcs/string/ft_strncat.c srcs/string/ft_strcmp.c srcs/string/ft_strrchr.c \
			srcs/string/ft_strstr.c srcs/string/ft_strnrcmp.c srcs/string/ft_strndup.c srcs/lst/ft_lstiter.c srcs/lst/ft_lstdelone.c srcs/lst/ft_lstmap.c \
			srcs/lst/ft_lstadd_back.c srcs/lst/ft_lstlast.c srcs/lst/ft_lstadd_front.c srcs/lst/ft_lstclear.c srcs/lst/ft_lstsize.c srcs/lst/ft_lstnew.c \
			srcs/ctype/ft_isalpha.c srcs/ctype/ft_toupper.c srcs/ctype/ft_isascii.c srcs/ctype/ft_isupper.c srcs/ctype/ft_islower.c \
			srcs/ctype/ft_isdigit.c srcs/ctype/ft_isalnum.c srcs/ctype/ft_isblank.c srcs/ctype/ft_iscntrl.c srcs/ctype/ft_ispunct.c srcs/ctype/ft_tolower.c \
			srcs/ctype/ft_isgraph.c srcs/ctype/ft_isspace.c srcs/ctype/ft_isprint.c srcs/ctype/ft_isxdigit.c srcs/math/ft_sqrt.c srcs/math/ft_pow.c \
			srcs/printf/ft_printf_hex.c srcs/printf/ft_printf.c srcs/printf/ft_printf_param.c srcs/printf/ft_printf_uns.c srcs/extra/ft_strjoin.c \
			srcs/extra/ft_putendl.c srcs/extra/ft_putstr.c srcs/extra/ft_striteri.c srcs/extra/ft_putchar.c srcs/extra/ft_putchar_fd.c srcs/extra/ft_swap.c \
			srcs/extra/ft_putnbr.c srcs/extra/ft_itoa.c srcs/extra/ft_strclen.c srcs/extra/ft_putstr_fd.c srcs/extra/ft_putendl_fd.c srcs/extra/ft_split_free.c \
			srcs/extra/ft_strmapi.c srcs/extra/ft_split.c srcs/extra/ft_putnbr_fd.c srcs/extra/ft_strtrim.c srcs/extra/ft_substr.c srcs/stdlib/ft_atol.c \
			srcs/stdlib/ft_atoi.c srcs/stdlib/ft_calloc.c srcs/stdlib/ft_atof.c srcs/extra/ft_split_set.c srcs/gnl/get_next_line_bonus_1.c srcs/gnl/get_next_line_bonus_2.c \
			srcs/extra/ft_flood_fill.c
OBJS	= $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

# pattern rule that specifies how to create an object file using a source file
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c 
	mkdir -p $(OBJ_DIR) $(OBJS_DIRS)
	@cc ${CFLAGS} ${HDR} -c $< -o $@
	

$(NAME) : ${OBJS}
	ar rcs ${NAME} $(OBJS)


all : ${NAME}

clean :
	$(RM) -rf $(OBJ_DIR)

fclean : clean
	${RM} ${NAME}

re : fclean all

#.SILENT :

.PHONY : all clean fclean re bonus

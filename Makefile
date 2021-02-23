# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgrea <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 10:59:04 by fgrea             #+#    #+#              #
#    Updated: 2021/02/12 10:07:07 by edassess         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
C_FLAGS = -Wall -Wextra -Werror

LFT_PATH = ./libraries/libft/
LFT_INC_PATH = ./libraries/libft/includes/
OBJ_PATH = ./objs/
INC_PATH = ./includes/
SRC_PATH = ./srcs/
SRC_FRT_PATH = ft_format_functions/
SRC_FLG_PATH = ft_flag_functions/

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = libftprintf.h
SRC_NAME = ft_printf.c ft_search.c \
	   ft_format_functions/ft_format_c.c ft_format_functions/ft_format_s.c \
	   ft_format_functions/ft_format_p.c ft_format_functions/ft_format_int.c \
	   ft_format_functions/ft_format_uint.c ft_format_functions/ft_format_percent.c \
	   ft_flag_functions/ft_flag_min.c ft_flag_functions/ft_flag_number.c \
	   ft_flag_functions/ft_flag_asterisk.c ft_flag_functions/ft_flag_hash.c \
	   ft_flag_functions/ft_flag_plus.c ft_flag_functions/ft_flag_spc.c \
	   ft_flag_functions/ft_flag_zero.c
	   #ft_format_functions/ft_format_n.c ft_format_functions/ft_format_f.c \
	   ft_format_functions/ft_format_e.c 

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH)) $(addprefix -I,$(LFT_INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LFT_PATH)
	@ar rc $@ $(OBJ)
	@libtool -static -o $@ $@ $(LFT_PATH)libft.a
	@ranlib $@
	@echo "Obj folder & files created"
	@echo "Executable created"
	@echo "Compilation finished"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(OBJ_PATH)
	@$(CC) $(C_FLAGS) $(INC) -o $@ -c $<

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_PATH)$(SRC_FRT_PATH) 2> /dev/null || true
	@mkdir $(OBJ_PATH)$(SRC_FLG_PATH) 2> /dev/null || true

clean:
	@make clean -C $(LFT_PATH)
	@rm -rf $(OBJ_PATH) 2> /dev/null || true
	@echo "Obj folder & files suppressed"

fclean: clean
	@make fclean -C $(LFT_PATH)
	@rm -f $(NAME)
	@echo "Executable suppressed"

re: fclean
	@$(MAKE) all

norme:
	@norminette -R CheckForbiddenSourceHeader $(SRC)
	@echo "C files norme check finished"
	@norminette -R CheckDefine $(INC_PATH)
	@echo "Header files norme check finished"

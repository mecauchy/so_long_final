# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 14:00:29 by mcauchy-          #+#    #+#              #
#    Updated: 2025/02/14 11:24:54 by mecauchy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES		=	./srcs/so_long.c ./srcs/move.c ./srcs/parsing.c ./srcs/utils.c ./srcs/bonus.c ./srcs/free_all.c
 
LIBFT			=	libft/libft.a
 
MLX				=	minilibx-linux/libmlx_Linux.a 
 
INCLUDES		=	-I . \
 					-I /libft \
					-I minilibx-linux/mlx \
			
OBJ_FILES		=	$(SRC_FILES:.c=.o)

CC				=	gcc -g3
#CC = gcc -O0 -g -fsanitize=address

CFLAGS			=	-Wall -Wextra -Werror

NAME			=	so_long

RED				=	\033[1;31m

YELLOW			=	\033[1;33m

RESET			=	\033[0m

all				:	$(NAME)

$(NAME)			:	$(OBJ_FILES) $(LIBFT) $(MLX)
					@clear
					@echo "Linking $(NAME) ..."	
					$(CC) $(OBJ_FILES) $(LIBFT) $(MLX) -lXext -lX11 -lm -lz $(CFLAGS) -no-pie -o $(NAME)
					echo "Done."
					@clear
					@echo "Compilation done."
					@echo ""
					@echo "........                                                                                   ........"
					@echo ""
					@echo "$(YELLOW)     =######=    -*######*:                    :##-        -######*.    =######+     =######+    $(RESET)"
					@echo "$(YELLOW)    .+++   +.    ===   :=+:                    -=+.        +=-  -=+.    ===  -=+    .+=-.    -:    $(RESET)"
					@echo "$(YELLOW)    .++          ===   :=+:                    -=+.        +=-  -=+.    ===  -=+    .+=-.    -:    $(RESET)"
					@echo "$(YELLOW)    .+++++++.    ===   :=+:                    -=+.        +=-  -=+.    ===  -=+    .+= .    $(RESET)"
					@echo "$(RED)         +++.    ===   :=+:                    -=+.        +=-  -=+.    ===  -=+    .+=   .:--:   $(RESET)"
					@echo "$(RED)         +++.    ===   :=+:                    -=+.        +=-  -=+.    ===  -=+    .+=   .:--:   $(RESET)"
					@echo "$(RED)    ::::::::     :::::::::    .:::::::::::     ::::::.     :::::::.    .::.  :::     .::::::::.    $(RESET)"
					@echo ""
					@echo ""
					@echo "$(RED)........                                                                                   ........$(RESET)"
					@echo ""				
					@echo ""				
					@echo "$(YELLOW)                    # ********************************************************* #$(RESET)"
					@echo "$(YELLOW)                    #                                                           #$(RESET)"
					@echo "$(YELLOW)                    #----------------------- by mcauchy- ---------------------- #$(RESET)"
					@echo "$(YELLOW)                    #                                                           #$(RESET)"
					@echo "$(YELLOW)                    # ********************************************************* #$(RESET)"
					@echo ""
					@echo "$(YELLOW)........                                                                                   ........$(RESET)"
					
%.o				:	%.c 
					@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 
	
$(LIBFT)		:
					$(MAKE) -C libft/

clean			:
					rm -rf $(OBJ_FILES)
					cd srcs/; rm -rf *.o
					$(MAKE) fclean -C libft/
		
fclean			:	clean
					rm -rf $(NAME)
		
re				:	fclean all

.PHONY			:	all clean fclean re
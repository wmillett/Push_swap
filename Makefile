# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 08:48:00 by wmillett          #+#    #+#              #
#    Updated: 2023/08/27 22:43:35 by wmillett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program Name ----------------------------
NAME = push_swap
#Dependencies -----------------------------
LIBFT = libft
#Command variables ------------------------
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
MK = mkdir -p
RM = rm -rf
#Sources directories ----------------------
INCDIR = inc
SRCDIR = src
LIBFT_A = libft.a
LIBFTDIR = libft
LIBFT = $(addprefix $(LIBFTDIR)/, $(LIBFT_A))
SRC = main.c\
	algo.c\
	radix.c\
	turn_radix.c\
	error.c\
 	utils.c\
	utils_print.c\
	utils_mem.c\
	utils_str.c\
	utils_dist.c\
	utils_sort.c\
	utils_stack.c\
	utils_pos.c\
	find_smaller.c\
	find_bigger.c\
  	sort_small.c\
   	stack_opers_a.c\
	stack_opers_b.c\
	stack_opers_both.c\
	handle_array.c\
	sort.c\
	sort_opers.c\
	parse.c\
	
VPATH = ${SRCDIR}
#Colours -----------------------------------
B_BLUE='\033[1;34m'
RED=\033[0;31m
YELLOW=\033[33m
MAGENTA=\033[35m
B_GREEN=\033[1;32m
PURPLE=\033[1;35m
COLOUR_END=\033[0m
#Object directories ------------------------
OBJDIR = obj
OBJS = $(addprefix ${OBJDIR}/, ${SRC:%.c=%.o})
#Rules -------------------------------------
${OBJDIR}/%.o : %.c
	@${CC} ${CFLAGS} -I${INCDIR} -Ilibft/inc -c $< -o $@
all: $(NAME)
$(NAME): $(OBJDIR) $(OBJS)
	@make -C $(LIBFTDIR)
	@$(CC) ${CFLAGS} $(MLXLB) $(OBJS) -L$(dir $(LIBFT)) -lft -o $(NAME)
	@echo "$(YELLOW)⚡️$(NAME) ⚡️$(B_GREEN)has been created $(COLOUR_END)!"
$(OBJDIR):
	@$(MK) $(OBJDIR)
clean:
	@$(RM) $(OBJDIR)
	@make -C $(LIBFTDIR) clean
fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFTDIR) fclean
	@echo "$(RED)$(NAME) has been deleted 🗑️$(COLOUR_END)"
re: fclean all
.PHONY: all clean fclean re
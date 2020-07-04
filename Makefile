# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: eutrodri <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/16 16:35:04 by eutrodri      #+#    #+#                  #
#    Updated: 2020/07/04 20:34:22 by anonymous     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCS = count_ants.c lem_in.c read_links.c read_rooms.c\
	 check_input.c store_input_str.c valid_check_room.c hashtables.c\
	 free.c check_comment.c store_links.c max_path.c\
	 save_path.c find_node.c save_all_p.c bfs.c\
	 find_room.c algo_b.c devide_ants.c walk_ants.c print_ants.c\
	 sort_all.c free2.c ft_atoi2.c q.c id.c error.c put_links_off.c

OBJ = count_ants.o lem_in.o read_links.o read_rooms.o\
	 check_input.o store_input_str.o valid_check_room.o hashtables.o\
	 free.o check_comment.o store_links.o max_path.o\
	 save_path.o find_node.o save_all_p.o bfs.o\
	 find_room.o algo_b.o devide_ants.o walk_ants.o print_ants.o\
	 sort_all.o free2.o ft_atoi2.o q.o id.o error.o put_links_off.o

FLAGS = -Wall -Werror -Wextra

HEADER_FILES = includes/lem_in.h

LIB = Libft/libft.a
PR = libft/ft_printf/libftprintf.a

S = $(addprefix srcs/, $(SRCS))

O = $(addprefix obj/, $(OBJ))

O_P = mkdir -p obj

COLOR_GREEN = $(shell printf "\e[38;5;10m")
COLOR_RED = $(shell printf "\e[31;5;10m")
COLOR_YELLOW = $(shell printf "\e[33;5;10m")
COLOR_DEFAULT = $(shell printf "\e[39m")
NORM = norminette $(S) | grep -e "Error" -e "Warning" -B 1
PRINT_PLUS = $(shell printf '$(COLOR_GREEN)[ + ]$(COLOR_DEFAULT)')
PRINT_CLEAN = $(shell printf '$(COLOR_RED)[ - ]$(COLOR_DEFAULT)')
PROCESS = $(shell printf '$(COLOR_YELLOW)[ › ]$(COLOR_DEFAULT)')


FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(LIB) $(O) $(PR)
	@echo "$(PROCESS) $(COLOR_YELLOW)COMPILING$(COLOR_DEFAULT)"
	@gcc -o $(NAME) $(O) -I includes libft/ft_printf/libftprintf.a\
	 libft/libft.a
	@echo "$(PRINT_PLUS) $(COLOR_GREEN)Done$(COLOR_DEFAULT)"

obj/%.o : srcs/%.c
	@$(O_P)
	@gcc $(FLAGS) -c -o $@ $< -I includes

$(LIB) :
	@make -C libft/
	@echo "$(PRINT_PLUS) $(COLOR_GREEN)Libft Done$(COLOR_DEFAULT)"

$(PR) :
	@make -C libft/ft_printf/
	@echo "$(PRINT_PLUS) $(COLOR_GREEN)Printf Done$(COLOR_DEFAULT)"

clean:
	@make clean -C libft/
	@rm -rf $(O) obj/
	@echo "$(PRINT_CLEAN) $(COLOR_RED)Removed .o files$(COLOR_DEFAULT)"

fclean: clean
	@make fclean -C libft/
	@rm -f libft.a
	@rm -f $(NAME)
	@echo "$(PRINT_CLEAN) $(COLOR_RED)Removed libary$(COLOR_DEFAULT)"

re: fclean all

norm:
	@echo "===================NORMINETTE==================="
	@$(NORM) || echo "no norminette errors"
	@echo "================================================"

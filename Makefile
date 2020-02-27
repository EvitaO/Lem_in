NAME = lem-in

SRCS = count_ants.c lem_in.c read_links.c read_rooms.c go_to_start.c

OBJ = count_ants.o lem_in.o read_links.o read_rooms.o go_to_start.o

FLAGS = -Wall -Werror -Wextra

S = $(addprefix srcs/, $(SRCS))

O = $(addprefix obj/, $(OBJ))


COLOR_GREEN = $(shell printf "\e[38;5;10m")
COLOR_RED = $(shell printf "\e[31;5;10m")
COLOR_YELLOW = $(shell printf "\e[33;5;10m")
COLOR_DEFAULT = $(shell printf "\e[39m")
NORM = norminette $(SRCS) | grep -e "Error" -e "Warning" -B 1
PRINT_PLUS = $(shell printf '$(COLOR_GREEN)[ + ]$(COLOR_DEFAULT)')
PRINT_CLEAN = $(shell printf '$(COLOR_RED)[ - ]$(COLOR_DEFAULT)')
PROCESS = $(shell printf '$(COLOR_YELLOW)[ › ]$(COLOR_DEFAULT)')


FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) :
	@echo "$(PROCESS) $(COLOR_YELLOW)COMPILING$(COLOR_DEFAULT)"
	@make -C libft/
	@echo "$(PRINT_PLUS) $(COLOR_GREEN)Libft Done$(COLOR_DEFAULT)"
	@mv libft/libft.a .
	@gcc $(FLAGS) -c $(S) -I includes
	@mv $(OBJ) obj/
	@gcc $(FLAGS) -o $(NAME) $(O) -I includes/ libft.a
	@echo "$(PRINT_PLUS) $(COLOR_GREEN)Done$(COLOR_DEFAULT)"

clean:
	@make clean -C libft/
	@rm -f $(O)
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

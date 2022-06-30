SRC = push_swap.c utils.c interaction_push.c best_algo.c initialyser.c  interaction_swap.c\
		parsing_and_sec_function.c algo_3.c algo_5.c make_the_operation.c check_stack_b.c \
		best_algo_utils.c interaction_reverse_rotate.c interaction_rotate.c push_swap_utils.c
SRC_BONUS = checker_utils.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
MAIN = main.c
LIBFT = ./libft/libft.a
MAIN_BONUS = checker.c

%o : %c
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C ./libft
	$(MAKE) bonus -C ./libft
	$(CC) $(MAIN) $(LIBFT) $(OBJ) -o $(NAME)

bonus : $(NAME) $(OBJ_BONUS)
	$(CC) $(MAIN_BONUS) $(OBJ_BONUS) $(LIBFT) $(OBJ) -o checker

clean :
	@rm -rf $(OBJ) $(OBJ_BONUS)
	$(MAKE) clean -C ./libft
	@echo clean termine
fclean : clean
	@rm -rf $(NAME) checker
	$(MAKE) fclean -C ./libft
	@echo fclean termine
re : fclean all

.PHONY : all clean fclean re bonus

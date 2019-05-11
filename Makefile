NAME = get_next_line
SRCS = get_next_line.c main.c 
OBJ = get_next_line.o main.o

all: $(NAME)

$(NAME):
		 clang -Wall -Wextra -Werror -I libft/ -o get_next_line.o -c get_next_line.c
		 clang -Wall -Wextra -Werror -I libft/ -o main.o -c main.c
		 clang -o a.out main.o get_next_line.o -I libft/includes -L libft/ -lft

libft:
		make -C libft/ fclean && make -C libft/

clean:
	    /bin/rm -f $(OBJ)

fclean: clean
	    /bin/rm -f $(NAME)

re: fclean  all

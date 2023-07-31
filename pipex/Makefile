NAME = pipex

BNAME = bonus

SOURCES = ./ft_split.c\
./childs.c\
./create_pipes.c\
./paths.c\
./utils.c\
./pipex.c\
./utils2.c

BSOURCES = ./ft_split.c\
./childs_bonus.c\
./childs.c\
./paths.c\
./utils.c\
./pipex_bonus.c\
./create_pipes.c\
./create_pipes_bonus.c\
./get_next_line.c\
./utils2.c


CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SOURCES:.c=.o)

BOBJECTS = $(BSOURCES:.c=.o)


RM = rm -f

all: $(NAME) $(BNAME)

$(NAME): $(OBJECTS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)


$(BNAME): $(BOBJECTS)
			$(CC) $(CFLAGS) -o $(BNAME) $(BOBJECTS)

clean:
		$(RM) $(OBJECTS) $(BOBJECTS) 
fclean:	clean
		$(RM) $(NAME) $(BNAME)
re:		fclean all

.PHONY: all, clean, fclean, re

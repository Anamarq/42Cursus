NAME = libftprintf.a

SOURCES = ./ft_printf.c\
./utils.c\
./ft_itoa.c\
./hexas.c\
./numbers.c\
./strings.c


CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SOURCES:.c=.o)

RM = rm -f

AR = ar -src

all: $(NAME)

$(NAME): $(OBJECTS)
			$(AR) $(NAME) $(OBJECTS)

clean:
		$(RM) $(OBJECTS) 
fclean:	clean
		$(RM) $(NAME)
re:		fclean all

.PHONY: all, clean, fclean, re

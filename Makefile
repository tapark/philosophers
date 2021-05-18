SRCS_1 =	./philo_one.c \
			./utils.c \

SRCS_2 =	

SRCS_3 =	

NAME_1 = philo_one
NAME_2 = philo_two
NAME_3 = philo_three
OBJS_1 = $(SRCS_1:.c=.o)
OBJS_2 = $(SRCS_2:.c=.o)
OBJS_3 = $(SRCS_3:.c=.o)
INCS = .
RM = rm -f
CC = gcc
CFLAGS = #-Wall -Wextra -Werror -g3 -fsanitize=address

$(NAME_1) : $(OBJS_1)
		$(CC) $(CFLAGS) -o $(NAME_1) $(OBJS_1) -I $(INCS)

$(NAME_2) : $(OBJS_2)
		$(CC) $(CFLAGS) -o $(NAME_2) $(OBJS_2) -I $(INCS)

$(NAME_3) : $(OBJS_3)
		$(CC) $(CFLAGS) -o $(NAME_3) $(OBJS_3) -I $(INCS)



all : $(NAME_1) #$(NAME_2) $(NAME_3)

clean :
		$(RM) $(OBJS_1) $(OBJS_2) $(OBJS_3)

fclean : clean
		$(RM) $(NAME_1) $(NAME_2) $(NAME_3)

re : fclean all

test :
		./$(NAME_1) 5 100 100 100 7

retest : re test
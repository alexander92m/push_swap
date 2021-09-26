NAME = push_swap

LH = /SRC/push_swap.h

LHB = checker.h

LA = push_swap.a

LAB = checker.a

CHECKER = checker

SRC =	SRC/main.c\
		SRC/ft_isdigit.c\
		SRC/ft_atoi.c\
		SRC/ft_strlen.c\
		SRC/control_func1.c\
		SRC/control_func2.c\
		SRC/control_func3.c\
		SRC/sort1.c\
		SRC/sort2.c\
		SRC/sort3.c\
		SRC/sort4.c\
		SRC/sort5.c

SRC_B = SRC_B/checker_bonus.c\
		SRC_B/checker_error_bonus.c\
		SRC_B/checker_read_bonus.c\
		SRC_B/control_func1_bonus.c\
		SRC_B/control_func2_bonus.c\
		SRC_B/control_func3_bonus.c\
		SRC_B/ft_isdigit_bonus.c\
		SRC_B/ft_atoi_bonus.c\
		SRC_B/ft_strlen_bonus.c
		
OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

CC = clang
AR = ar
ARFLAGS = -rcs

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : $(LA)
	$(CC) $? -o $@

$(LA) : $(OBJ)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c $(LH) $(LHB)
	$(CC) $(CFLAGS) -c $<

bonus :	checker all

$(CHECKER) : $(LAB)
	$(CC) $? -o $@

$(LAB) : $(OBJ_B)
	$(AR) $(ARFLAGS) $@ $?

clean :
	rm -f $(OBJ)
	rm -f $(LA)
	rm -f $(LAB)
	rm -f $(OBJ_B)

fclean : clean
	rm -f $(NAME)
	rm -f checker

re : fclean all

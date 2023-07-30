NAME1 = server
NAME2 = client 
SER_B = server_bonus
CLT_B = client_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
FT_PRINTF = ./ft_printf/libftprintf.a

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
all: $(NAME1) $(NAME2)

bonus: $(SER_B) $(CLT_B)

$(NAME1) : server.o
	make -C ./ft_printf
	$(CC) $(CFLAGS) server.c utils.c $(FT_PRINTF) -o $@

$(NAME2) : client.o
	$(CC) $(CFLAGS) client.c utils.c $(FT_PRINTF) -o $@

$(SER_B) : server_bonus.o
	make -C ./ft_printf
	$(CC) $(CFLAGS) server_bonus.c utils_bonus.c $(FT_PRINTF) -o $@

$(CLT_B) : client_bonus.o
	$(CC) $(CFLAGS) client_bonus.c utils_bonus.c $(FT_PRINTF) -o $@
	
clean:
	make clean -C ./ft_printf
	rm -f server.o client.o
	rm -f server_bonus.o client_bonus.o

fclean: clean
	make fclean -C ./ft_printf 
	rm -f $(NAME2) $(NAME1)
	rm -f $(CLT_B) $(SER_B)

re: fclean all

.PHONY : all clean fclean re bonus

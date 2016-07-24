# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gperroch <gperroch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/24 09:22:04 by gperroch          #+#    #+#              #
#    Updated: 2015/08/27 18:37:35 by gperroch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
SPECC = recognition_special.c recognition_ending_special.c
SPECO = recognition_special.o recognition_ending_special.o

all: shard_1 shard_2

shard_1:
	@gcc -c $(FLAGS) copy_map.c core.c display_final.c fcts.c main.c map_evolution.c $(SPECC)

shard_2:
	@gcc $(FLAGS) copy_map.o core.o display_final.o fcts.o main.o map_evolution.o $(SPECO) -o bsq 

clean:
	@rm copy_map.o core.o display_final.o fcts.o main.o map_evolution.o $(SPECO)

fclean: clean
	@rm bsq

re: fclean all

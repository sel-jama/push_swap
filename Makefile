# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 19:18:50 by sel-jama          #+#    #+#              #
#    Updated: 2023/02/28 22:15:34 by sel-jama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = parse_stack.c rotate.c reverse_rotate.c swap.c push.c \
check_args.c utils.c sort_stack.c get_rank.c set_position.c \
set_cost.c mini_quick_sort.c push_swap.c utils_2.c

SRCS_BONUS = parse_stack.c rotate.c reverse_rotate.c swap.c push.c \
check_args.c utils.c checker_bonus.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c utils_2.c

BONUS_OBJS = ${SRCS_BONUS:.c=.o} 

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

NAME_BONUS = checker

all: ${NAME}

bonus: $(NAME_BONUS)

${NAME} : ${OBJS}
	@make -C libft/
	@make bonus -C libft/
	${CC} ${CFLAGS} ${OBJS} libft/libft.a -o ${NAME}

${NAME_BONUS} : ${BONUS_OBJS}
	@make -C libft/
	@make bonus -C libft/
	${CC} ${CFLAGS} ${BONUS_OBJS} libft/libft.a -o ${NAME_BONUS}

clean :
	@rm -f ${OBJS} ${BONUS_OBJS}

fclean : clean
	@rm -f ${NAME} ${NAME_BONUS}
	@make fclean -C libft/

re: fclean all
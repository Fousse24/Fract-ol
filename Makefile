# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 14:11:04 by sfournie          #+#    #+#              #
#    Updated: 2021/09/13 11:44:47 by sfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra
C_OBJS	= $(CC) $(CFLAGS) -I$(MLX) -I$(INCS) -c $< -o $(ODIR)/$@
NAME	= fractol.a

IDIR	= ./includes
MLXI	= /usr/local/include
MLXL	= /usr/local/lib
SDIR	= ./srcs
ODIR	= ./objs
LFTDIR	= $(IDIR)/libft
LFTA	= $(LFTDIR)/libft.a
MLIBFT	= @ cd $(LFTDIR) && make

MLX		= $(IDIR)/mlx
INCS	= $(IDIR)/fractol.h

SRCS	= ft_color.c ft_draw.c ft_fractol.c ft_julia.c\
		  ft_input_handler.c ft_move.c ft_zoom.c ft_getcolor.c\
		  ft_settings.c ft_utils.c ft_mandelbrot.c ft_burning_ship.c
vpath %.c $(SDIR)

_OBJS	= $(SRCS:.c=.o)
OBJS	= $(patsubst %,$(ODIR)/%,$(_OBJS))
vpath %.o $(ODIR)

all		: $(NAME)	

PRINTED :=
%.o :  %.c
	@ $(or $(PRINTED),$(eval PRINTED := :)$(info # Compiling object files...))
	@ $(C_OBJS)

$(NAME)	: $(INCS) $(LFTA) $(ODIR) $(_OBJS)
	$(info # Compiling library...)
	@ ar -rcs $(NAME) $(OBJS)
	$(info # Compiling executable...)
	@ $(CC) -L$(MLXL) -lmlx -framework OpenGL -framework AppKit $(NAME) -o fractol
	$(info Executable is "fractol")

$(ODIR)	:
	@ mkdir -p $(ODIR)
	
$(LFTA): 
	$(MLIBFT) all
	@ cp $(LFTA) $(NAME)	

clean	:
	$(info # Cleaning objects...)
	@ rm -rf $(ODIR)
	$(MLIBFT) clean
	$(info # Cleaning done!)

fclean	: clean
	@ rm -rf $(NAME)
	$(MLIBFT) fclean

re		: fclean all

bonus	: all

.PHONY	: clean all fclean re libft bonus
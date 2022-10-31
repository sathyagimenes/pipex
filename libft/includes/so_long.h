/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:30:06 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/30 01:36:22 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include <fcntl.h>

# include <stdbool.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/resource.h>
# include <sys/stat.h>

# define WINDOW_HEIGHT 360
# define WINDOW_WIDTH 640
# define EMPTY_SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER_POSITION 'P'
# define IMG_SIZE 64

# define RED "\x1b[38;5;1m"
# define RESET "\x1b[0m"

# define FAIL 0
# define SUCCESS 1

typedef enum e_error
{
	INVALID_ARGUMENT,
	INVALID_TYPE_BER,
	INVALID_SHAPE,
	INVALID_MAP,
	INVALID_SAVE,
	INVALID_ENTITIES,
	INVALID_WALL,
	INVALID_PLAYER,
	INVALID_COLLECTIBLE,
	INVALID_EXIT,
	INVALID_PATH
}	t_error;

typedef enum e_face
{
	P_UP,
	P_DOWN,
	P_LEFT,
	P_RIGHT
}	t_face;

typedef enum e_end
{
	ESCAPE_KEY,
	FOUND_EXIT,
}	t_end;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_sprite
{
	int		qty;
	int		width;
	int		height;
	void	*image;
	char	*path;
}	t_sprite;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_path
{
	char	**grid;
	t_point	point;
	int		collect;
	int		exit;
}	t_path;

typedef struct s_player
{
	t_point		point;
	void		*image;
	int			qty;
	int			steps;
	int			width;
	int			height;
	t_face		face;
	t_sprite	sprite[4];
}	t_player;

typedef struct s_objects
{
	t_sprite	collectible;
	t_sprite	exit;
	t_sprite	floor;
	t_sprite	wall;
}	t_objects;

typedef struct s_program
{
	void		*mlx;
	void		*mlx_win;
	int			row_qnty;
	int			column_qnty;
	char		**map_grid;
	t_player	player;
	t_objects	obj;
	t_point		pos;
}	t_program;

void	load_data(t_program *program);
int		initialize_game(t_program *program);
int		validate_argument(int argc, char *argv);
int		keypress_hook(int keycode, t_program *program);
int		end_game(t_program *program, t_end end_type);
int		print_error_message(t_error error_type);
int		print_map_error(t_error error_type);
int		print_entity_error(t_error error_type);
int		read_map(char *argv_1, t_program *program);
int		get_next_line(int fd, char **line);
void	free_grid(t_program *program);
int		map_validation(t_program *program);
int		render(t_program *program);
int		load_sprites(t_program *program);
void	move_player_up(t_program *program);
void	move_player_down(t_program *program);
void	move_player_right(t_program *program);
void	move_player_left(t_program *program);
void	destroy_sprites(t_program *program);
int		verify_path(t_program *program);
void	save_player_position(t_program *program);

#endif

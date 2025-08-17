/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 20:24:11 by ltrillar          #+#    #+#             */
/*   Updated: 2025/08/17 23:23:54 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 40

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_textures
{
void *font;
char *font_path;
void *wall;
char *wall_path;
void *player;
char *player_path;
void *f_00;
char *f_00_path;
void *exit;
char *exit_path;
} t_textures;
typedef struct s_coin
{
int x;
int y;
} t_coin;
typedef struct s_data
{
void *mlx;
void *win;
int width;
int height;
int player_x;
int player_y;
int coin_count;
int exit_loc_x;
int exit_loc_y;
int count;
char **map;
char *map_path;
t_textures t;
t_coin *coins;
} t_data;

/*
** NAME: Initialization & Setup
** DESC: Functions for initializing data structures and textures
*/
void load_t(t_data *d);
void init_tex(t_data *d);
void init_var(t_data *d);

/*
** NAME: Map Handling
** DESC: Functions for map loading, validation and rendering
*/
void map(t_data *d, char *ber);
int line_count(t_data *d);
int format_check(char *str);
int rules_check(t_data *d);

/*
** NAME: Rendering & Graphics
** DESC: Functions for drawing game elements
*/
void open_window(t_data *d);
void print_line(t_data *d, char *line, int y);
void draw_basic_tile(t_data *d, int i, char tile, int y);
void handle_coin(t_data *d, int i, int y);

/*
** NAME: Game Logic & Controls
** DESC: Functions for player movement and game state
*/
int keyPress(int keycode, t_data *d);
int is_wall(int x, int y, t_data *d);
void is_coin(int x, int y, t_data *d);

/*
** NAME: Validation & Utilities
** DESC: Helper functions for file and path validation
*/
int is_right_path(t_data *d);

/*
** NAME: Memory Management & Cleanup
** DESC: Functions for freeing allocated memory and cleanup
*/
int close_game(t_data *d);
void free_textures(t_data *d);
void free_coins(t_data *d);
void free_map(char **map);

/*
** NAME: Error Handling
** DESC: Functions for error management
*/
void exit_error(char *msg, t_data *d);

#endif
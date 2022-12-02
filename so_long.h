/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:00:30 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/27 23:03:36 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdarg.h>

# define L 32
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLEC 'C'
# define ENEMY 'X'
# define CLOSE 17
# define PRESS 2
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define RESET "\033[0m"

# define UP 124
# define DOWN 123
# define LEFT 125
# define RIGHT 126
# define ESC 53

typedef struct s_player
{
	int	direction;
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	char		**map;
	char		**map_check;
	int			collectibles;
	int			rows;
	int			cols;
	t_player	player;
	t_player	*enemy;
	int			enemy_nbr;
	char		*enemy_color;
	char		*wall;
	char		*coin;
}		t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_s;
	t_map	map;
	int		moves;
	int		exit;
}	t_game;

size_t	ft_strlen(char *c);
char	*get_next_line(int fd);
void	ft_fill_map(char *map_file, t_game *prog);
void	ft_win_create(t_game *game);
void	ft_render(t_game game);
void	ft_check_map(char *file, t_game *game);
void	ft_free_game(t_game *game);
void	ft_error(t_game *game, char *message);
void	ft_allocation_error(char **map);
void	ft_func(t_game *game, int x, int y);
void	ft_get_info(t_game *game);
void	ft_check_if_dir(char *f_name);
int		ft_get_rows_nbr(int fd);
int		ft_get_cols_nbr(t_game game);
int		ft_check_extention(char *f_name);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_check_empty(char *file);
int		ft_check_len(t_game *game);
int		ft_check_characters(t_game game);
int		ft_check_surounded(t_game game);
int		ft_check_collec(t_game game);
int		ft_check_player(t_game game);
int		ft_check_exit(t_game game);
int		ft_free(t_game *game, int flag);
int		ft_handler(int key, t_game *game);
void	ft_move(t_game *game, int dest_x, int dest_y, int player);
int		ft_check_path(t_game *game);
void	ft_fill_check_map(char *map_file, t_game *game);
int		ft_printf(const	char *format, ...);
int		ft_win(t_game *game);
int		ft_close(t_game *game);
int		ft_lose(t_game *game);
int		ft_move_animation(void	*param);
void	ft_move_enemy(t_game *game);
void	ft_anime_col(t_game *game);
void	ft_wall_path(t_game *game);
int		ft_check_c(t_game game);
int		ft_check_e(t_game game);
void	ft_func_helper(t_game *game, int x, int y, int flag);
int		ft_check_last_nl(char *file, t_game *game);

#endif
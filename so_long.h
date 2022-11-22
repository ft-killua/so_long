/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:00:30 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/22 20:42:29 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

# define L 32
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLEC 'C'
# define ENEMY 'X'
# define CLOSE 17
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define RESET "\033[0m"
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
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
	int			collectibles;
	int			rows;
	int			cols;
	t_player	player;
}		t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_s;
	t_map	map;
	int		fd;
	int		exit;
}	t_game;

size_t	ft_strlen(char *c);
char	*get_next_line(int fd);
void	ft_fill_map(char *map_file, t_game *prog);
void	ft_win_create(t_game *game);
void	ft_render(t_game game);
int		ft_get_rows_nbr(int fd);
int		ft_get_cols_nbr(t_game game);
int		ft_check_extention(char *f_name);
void	ft_check_map(char *file, t_game *game);
void	ft_free_game(t_game *game);
char	*ft_strchr(const char *s, int c);
void	ft_error(t_game *game, char *message);
void	ft_check_if_dir(char *f_name);
int		ft_check_len(t_game *game);
int		ft_check_characters(t_game game);
int		ft_check_surounded(t_game game);
int		ft_check_collec(t_game game);
int		ft_check_player(t_game game);
int		ft_check_exit(t_game game);
void	ft_get_info(t_game *game);
int		ft_free(t_game *game);
int		ft_handler(int key, t_game *game);
void	ft_move(t_game *game, int dest_x, int dest_y, int player);
#endif
// #include <mlx.h>
// int main()
// {
//     void *mlx_ptr;//connection identifier between our software and display
//     void *mlx_win;//window identifier 

//     mlx_ptr = mlx_init();
//     mlx_win = mlx_new_window(mlx_ptr, 1000, 500, "solong");
    
//     //infinite loop that waits for events and then calls a user defined function associated to this event
//     //it takesas parameter the connection identifier
//     //Each window can define a different function for the same event.
//     mlx_loop(mlx_ptr);
//     return 0; 
// }
// //to compile ; cc -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
// //man /usr/share/man/man3/mlx_loop.1 

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_mlx
{
	void *mlx;
	void *win;
}	t_mlx;

int func(int button, int x, int y, void *param)
{
	t_mlx *test = param;
	mlx_pixel_put(test->mlx, test->win, 800/2, 480/2, 0x00FF00);
	return (0);
}

int func2(int keycode, t_mlx *data)
{
	mlx_destroy_window(data->mlx, data->win);
	return (0);
}

int func3(int key_code, t_mlx *data)
{
	printf("gggg");
	return (0);
}

int	main(void)
{
	void	*mlx_win;
	t_mlx	data;

	void 	*wall;
	void	*player;
	void	*exit;
	char 	*wall_path = "./assets/wall.xpm";
	char 	*player_path = "./assets/player.xpm";
	char 	*exit_path = "./assets/exit.xpm";
	int		img_width;
	int		img_height;
	int 	x;
	int		y;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 640, 320, "HAAAHWA KHRJ TANI !");
	x = 0;
	y = 32;
	//mlx_mouse_hook(mlx_win, &func1, &data);
	//mlx_pixel_put(mlx, mlx_win, 800/2, 480/2, 0xFFFFFF);
	//mlx_hook(data.win, 2, 1L<<0, func2, &data);
	//mlx_key_hook(data.win, func3, &data);
	wall = mlx_xpm_file_to_image(data.mlx, wall_path, &img_width, &img_height);
	player = mlx_xpm_file_to_image(data.mlx, player_path, &img_width, &img_height);
	exit = mlx_xpm_file_to_image(data.mlx, exit_path, &img_width, &img_height);
	while (x <= 640)
	{
		mlx_put_image_to_window(data.mlx, data.win, wall, x, 0);
		mlx_put_image_to_window(data.mlx, data.win, wall, x, 288);
		x += 32;
	}
	while (y <= 320)
	{
		mlx_put_image_to_window(data.mlx, data.win, wall, 0, y);
		mlx_put_image_to_window(data.mlx, data.win, wall, 608, y);
		y += 32;
	}
	//mlx_put_image_to_window(data.mlx, data.win, player, 50, 160);
	//mlx_put_image_to_window(data.mlx, data.win, exit, 0, 150);
	mlx_loop(data.mlx);
	return (0);
}
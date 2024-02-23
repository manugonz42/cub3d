#include "include/cub3d.h"

int i = 0;

typedef struct
{
    void *mlx;
    void *win;
    int key_pressed;
} t_data;

int deal_key_press(int key, t_data *data)
{
	i = 1;
    if (key == 119) // Código de la tecla 'W' en ASCII
    {
		printf("Tecla 'W' presionada\n");
        data->key_pressed = 1;
    }
    return (0);
}

int deal_key_release(int key, t_data *data)
{
	//printf("suelta funcion\n");
	i = 0;
    if (key == 119) // Código de la tecla 'W' en ASCII
    {
       	printf("Tecla 'W' liberada\n");
        data->key_pressed = 0;
    }
    return (0);
}

void perform_action(t_data *data)
{
    if (data->key_pressed)
    {
        // Realiza la acción mientras la tecla 'W' está presionada
        printf("Realizando acción mientras la tecla 'W' está presionada\n");

        // Tu código aquí
    }
}

int	draw_next_frame(t_data *data)
{
	if (i == 1)
		printf("presionada\n");
	usleep(FPS);
	return 0;
}

int main(void)
{
    t_data *data;

    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, 500, 500, "Presionar 'W'");

    // Asocia las funciones deal_key_press y deal_key_release con los eventos
    // de tecla presionada y tecla liberada, respectivamente.
	mlx_do_key_autorepeatoff(data->mlx);
    mlx_hook(data->win, 2, 1L<<0, deal_key_press, &data);
    mlx_hook(data->win, 3, 1L<<1, deal_key_release, &data);
	
	mlx_loop_hook(data->mlx, draw_next_frame, data);
	mlx_loop(data->mlx);
    return (0);
}
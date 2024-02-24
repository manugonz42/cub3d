#include "mlx/mlx.h"
#include "mlx/mlx_int.h"


typedef struct s_image
{
    void *ptr;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_image;

void draw_line(int x, int y, int x2, int y2, t_image *image)
{
    int dx = x2 - x;
    int dy = y2 - y;
    int steps, k;
    float x_increment, y_increment, x_actual, y_actual;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    x_increment = (float)dx / (float)steps;
    y_increment = (float)dy / (float)steps;
    x_actual = x;
    y_actual = y;

    for (k = 0; k < steps; k++)
    {
        int pixel_index = ((int)y_actual * image->line_length) + ((int)x_actual * (image->bits_per_pixel / 8));
        *(int *)(image->addr + pixel_index) = 0xFFFFFF; // Color blanco

        x_actual += x_increment;
        y_actual += y_increment;
    }
}

int main()
{
    void *mlx_ptr;
    t_image image;

    mlx_ptr = mlx_init();
    image.ptr = mlx_new_image(mlx_ptr, 800, 600);
    image.addr = mlx_get_data_addr(image.ptr, &image.bits_per_pixel, &image.line_length, &image.endian);

    draw_line(100, 100, 500, 300, &image);

    mlx_put_image_to_window(mlx_ptr, mlx_new_window(mlx_ptr, 800, 600, "Image Window"), image.ptr, 0, 0);

    mlx_loop(mlx_ptr);

    return 0;
}

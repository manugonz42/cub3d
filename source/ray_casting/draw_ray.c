#include "cub3d.h"

void draw_ray(int x, int y, int x2, int y2, t_image *image)
{
    int color = create_trgb(0, 255, 0, 0);
    printf("draw_ray: x: %d, y: %d, x2: %d, y2: %d\n", x, y, x2, y2); // (1)
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
    x_actual = x + 31;
    y_actual = y + 31;

    int pixel_index = (y_actual * image->line_bytes) + (x_actual * (image->bitsinpixel / 8));
    *(int *)(image->addr + pixel_index) = 0xFF0000; // Color blanco

    for (k = 0; k < steps; k++)
    {
        x_actual += x_increment;
        y_actual += y_increment;

        pixel_index = (y_actual * image->line_bytes) + (x_actual * (image->bitsinpixel / 8));
        *(int *)(image->addr + pixel_index) = color; // Color blanco
    }
}

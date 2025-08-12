#include "../include/so_long.h"

int main(void)
{
    void *mlx;
    void *win;

    int j;
    int k;
    int i;
    int h;
    
    void *img_font;
    char *path_img_font = "src/textures/font.xpm";
    void *img_wall;
    char *path_img_wall = "src/textures/wall.xpm";

    int img_width;
    int img_height;
    

    if (!load_t())
        return (1);
    
    mlx = mlx_init();
    if (!mlx) {
        ft_printf("Error: MLX initialization failed\n");
        return (1);
    }
    ft_printf("MLX initialized successfully\n");
    
    img_font = mlx_xpm_file_to_image(mlx, path_img_font, &img_width, &img_height);
    img_wall = mlx_xpm_file_to_image(mlx, path_img_wall, &img_width, &img_height);
    if ((!img_font) || (!img_wall)) {
        ft_printf("Error: MLX could not load XPM file %s\n", path_img_font);
        ft_printf("This usually means MLX doesn't like the XPM format\n");
        return (1);
    }
    ft_printf("Image loaded successfully: %dx%d\n", img_width, img_height);
    
    win = mlx_new_window(mlx, 800, 400, "My Minecraft 2d game :)");
    if (!win) {
        ft_printf("Error: Could not create window\n");
        return (1);
    }
    ft_printf("Window created successfully\n");

    j = 0;
    k = 0;
    i = 0;
    h = 0;
    while (h <= 4)
    {
        j = 0;
        i = 0;
        while (i <= 9)
        {
            mlx_put_image_to_window(mlx, win, img_font, j, k);
            j += 80;
            i++;
        }
        k += 80;
        h++;
    }
    mlx_loop(mlx);
    return (0);
}
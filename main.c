#include "fractal.h"

void    fill_pix(t_frac *p, int x, int y)
{
    p->img.img_data[(x) * 4 + (y) * 4 * p->height] = 0;
	p->img.img_data[(x) * 4 + (y) * 4 * p->height + 1] = 255;
	p->img.img_data[(x) * 4 + (y) * 4 * p->height + 2] = 255;
}

int     main()
{
    t_frac  p;
    t_img   img;
    int     kmax = 100;
    double  newx;
    double  newy;
    double  x;
    double  y;
    p.height = 1600;
    p.width = 1600;
    p.j= 0;
    p.conn = mlx_init();
    p.win = mlx_new_window(p.conn, p.height, p.width, "PIZDA");
    p.img.p_img = mlx_new_image(p.conn, p.height, p.width);
    p.img.img_data = mlx_get_data_addr(p.img.p_img, &p.img.bpp, &p.img.size_line, &p.img.endian);
    while (p.j < 400)
    {
        p.i = 0;
        while (p.i < 400)
        {
            x = p.i;
            y = p.j;
            while (kmax >= 0 && (pow(x, 2) + pow(y, 2) <= 6400000))
            {
                newx = pow(x, 2) - pow(y, 2) + p.i;
                newy = 2 * x * y + p.j;
                x = newx;
                y = newy;
                kmax--;
            }
            if (kmax == -1)
                fill_pix(&p, p.i * 20 + 300, p.j * 20 + 300);
            // else
            //     fill_pix(&p, p.i, p.j);
            kmax = 10;
            p.i++;
        }
        p.j++;
    }
    mlx_put_image_to_window(p.conn, p.win, p.img.p_img, 0, 0);
    mlx_loop(p.conn);
}
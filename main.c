#include "fractal.h"

void    fill_pix(t_param *p, int x, int y)
{
	p->img.img_data[(x) * 4 + (y) * 4 * p->width] = p->clr.r;
	p->img.img_data[(x) * 4 + (y) * 4 * p->width + 1] = p->clr.g;
	p->img.img_data[(x) * 4 + (y) * 4 * p->width + 2] = p->clr.b;
}

void	calculate_draw(t_param *p)
{
	p->j = 0;
	mlx_clear_window(p->conn, p->win);
	ft_bzero((void *)p->img.img_data, p->height * p->width * 4);
	while (p->j < p->height)
	{
		p->i = 0;
		while (p->i < p->width)
		{
			p->clr.r = 0;
			p->clr.g = 122;
			p->clr.b = 255;
			p->c_re = (double)(p->i / (p->width / (p->re_max - p->re_min)) + p->re_min);
			p->c_im = (double)(p->j / (p->height / (p->im_max - p->im_min)) + p->im_min);
			p->x = 0.0;
			p->y = 0.0;
			p->iter = 0;
			while (p->iter < MAX_ITER && (pow(p->x, 2) + pow(p->y, 2) < (double)4))
			{
				p->x_new = (double)(pow(p->x, 2) - pow(p->y, 2) + p->c_re);
				p->y = (double)(2 * p->x * p->y + p->c_im);
				p->x = p->x_new;
				p->iter++;
			}
			//if (iter < MAX_ITER)
			p->clr.r += p->iter;
			fill_pix(p, p->i, p->j);
			p->i++;
		}
		p->j++;
	}
	mlx_put_image_to_window(p->conn, p->win, p->img.p_img, 0, 0);
}

int		mouse_press(int key, int x, int y, void *ptr)
{
	t_param	*p;
	double	mouse_re;
	double	mouse_im;

	p = (t_param *)ptr;
	mouse_re = x / (p->width / (p->re_max - p->re_min)) + p->re_min;
	mouse_im = y / (p->height / (p->im_max - p->im_min)) + p->im_min;
	if (key == 4)
	{
		p->re_min = (p->re_min - mouse_re) * 0.96 + mouse_re;
		p->re_max = (p->re_max - mouse_re) * 0.96 + mouse_re;
		p->im_min = (p->im_min - mouse_im) * 0.96 + mouse_im;
		p->im_max = (p->im_max - mouse_im) * 0.96 + mouse_im;
		calculate_draw(p);
		printf("%f", p->re_max);
	}
	printf("%d", key);
	return (0);
}

int     main()
{
	t_param  p;
	p.height = 800;
	p.width = 900;
	p.j = 0;
	p.re_min = -2;
	p.re_max = 1;
	p.im_min = -1;
	p.im_max = 1;
	p.conn = mlx_init();
	p.win = mlx_new_window(p.conn, p.width, p.height, "PIZDA");
	p.img.p_img = mlx_new_image(p.conn, p.width, p.height);
	p.img.img_data = mlx_get_data_addr(p.img.p_img, &p.img.bpp, &p.img.size_line, &p.img.endian);
	calculate_draw(&p);
	mlx_hook(p.win, 4, 1L << 2, mouse_press, (void *)&p);
	mlx_loop(p.conn);
}
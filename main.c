#include "fractal.h"

void    fill_pix(t_param *p, int x, int y)
{
	p->img.img_data[(x) * 4 + (y) * 4 * p->width] = p->clr.r;
	p->img.img_data[(x) * 4 + (y) * 4 * p->width + 1] = p->clr.g;
	p->img.img_data[(x) * 4 + (y) * 4 * p->width + 2] = p->clr.b;
}

char	*prog_gpu(void)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*res;
	char	*tmp;

	res = ft_strnew(1);
	if ((fd = open(PROG_GPU, O_RDONLY)) == -1)
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(res, buf);
		free(res);
		res = ft_strdup(tmp);
		free(tmp);
	}
	close(fd);
	return (res);
}	

void	calculate_draw_iter(t_param *p)
{
	p->j = 0;
	mlx_clear_window(p->conn, p->win);
	ft_bzero((void *)p->img.img_data, HEIGHT * WIDTH * 4);
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

void	calculate_draw(t_param *p)
{
	int		err;
	p->j = 0;
	mlx_clear_window(p->conn, p->win);
	p->clp->buffer = clCreateBuffer(p->clp->context, CL_MEM_WRITE_ONLY, sizeof(cl_int) * (HEIGHT * WIDTH), NULL, NULL);
	ft_bzero((void *)p->img.img_data, HEIGHT * WIDTH * 4);
	// clp->plat_id = NULL;
	// clp->ret_num_platforms = 0;
	// ret = clGetPlatformIDs(1, &clp->plat_id, &clp->ret_num_platforms); // not work???
	// if (ret != CL_SUCCESS)
	// {
	// 	printf ("%d", ret);
	// }
	//ret = clGetDeviceIDs(clp.plat_id, CL_DEVICE_TYPE_GPU, 1, &clp.dev_id, &clp.ret_num_platforms); // not work
	init_kernel_arg(p->clp, p);
	clock_t t0 = clock();
	clEnqueueNDRangeKernel(p->clp->command_queue, p->clp->kernel, 2, NULL, (&p->global), NULL, 0, NULL, NULL);
	clFinish(p->clp->command_queue);
	err = clEnqueueReadBuffer(p->clp->command_queue, p->clp->buffer, CL_TRUE, 0,
	sizeof(cl_int) * HEIGHT * WIDTH, p->img.img_data, 0, NULL, NULL);
	t0 = clock() - t0;
	printf("-->%f", ((double)(t0) / CLOCKS_PER_SEC));
	free(p->clp->buffer);
	mlx_put_image_to_window(p->conn, p->win, p->img.p_img, 0, 0);
}

int		button_press(int key, void *ptr)
{
	t_param	*p;
	double	re;
	double	im;

	p = (t_param *)ptr;
	if (key == 65362)
	{
		re = p->mse_x / (p->width / (p->re_max - p->re_min)) + p->re_min;
		im = p->mse_y / (p->height / (p->im_max - p->im_min)) + p->im_min;
		p->re_min = (p->re_min - re) * 0.98 + re;
		p->re_max = (p->re_max - re) * 0.98 + re;
		p->im_min = (p->im_min - im) * 0.98 + im;
		p->im_max = (p->im_max - im) * 0.98 + im;
		// printf("re_max%d\n", p->mse_x);
		// printf("re_min%d\n", p->mse_y);
		calculate_draw(p);
	}
	//ft_putnbr(key);
	return (0);
}

int		mouse_motion(int x, int y, void *ptr)
{
	t_param	*p;

	p = (t_param *)ptr;
	p->mse_x = x;
	p->mse_y = y;
	//printf("re_max%d\n", x);
	//printf("re_min%d\n", y);
	return (0);
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
		p->re_min = (p->re_min - mouse_re) * 0.98 + mouse_re;
		p->re_max = (p->re_max - mouse_re) * 0.98 + mouse_re;
		p->im_min = (p->im_min - mouse_im) * 0.98 + mouse_im;
		p->im_max = (p->im_max - mouse_im) * 0.98 + mouse_im;
		// clock_t t0 = clock();
		calculate_draw(p);
		//calculate_draw_iter(p);
		// t0 = clock() - t0;
		// printf("-->%f", ((double)(t0) / CLOCKS_PER_SEC));
		//printf("re_max%f\n", p->re_max);
		//printf("re_min%f\n", p->re_min);
	}
	return (0);
}

int     main()
{
	t_param  p;
	p.height = HEIGHT;
	p.width = WIDTH;
	size_t		buf;
	size_t		len;
	cl_uint		res;
	p.j = 0;
	p.re_min = -2;
	p.re_max = 1;
	p.im_min = -1;
	p.im_max = 1;
	p.iter_max = MAX_ITER;
	p.conn = mlx_init();
	p.win = mlx_new_window(p.conn, WIDTH, HEIGHT, "PIZDA");
	p.img.p_img = mlx_new_image(p.conn, WIDTH, HEIGHT);
	p.img.img_data = mlx_get_data_addr(p.img.p_img, &p.img.bpp, &p.img.size_line, &p.img.endian);
	t_clp	*clp;
	clp = (t_clp *)malloc(sizeof(t_clp));
	cl_int ret;
	clp->dev_id = NULL;
	p.global = HEIGHT * WIDTH;
	ret = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, &clp->dev_id, NULL);
	clGetDeviceInfo(clp->dev_id, CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(res), &res, &len);
	printf("%d", res);
	if (ret != CL_SUCCESS)
	{
		printf("%s", "Devises pizda");
		exit(1);
	}
	clp->context = clCreateContext(NULL, 1, &clp->dev_id, NULL, NULL, &ret);
	if (!clp->context)
	{
		if (ret == CL_INVALID_PLATFORM)
			printf("%s", "CL_INVALID_PLATFORM");
		if (ret == CL_INVALID_VALUE)
			printf("%d", CL_INVALID_VALUE);
		if (ret == CL_DEVICE_NOT_AVAILABLE)
			printf("%s", "CL_DEVICE_NOT_AVAILABLE");
		if (ret == CL_OUT_OF_HOST_MEMORY)
			printf("%s", "CL_OUT_OF_HOST_MEMORY");
		printf("%d", ret);
		printf("%s", "context");
		exit(1);
	}
	clp->command_queue = clCreateCommandQueueWithProperties(clp->context, clp->dev_id, 0, &ret);
	if (!clp->command_queue)
	{
		printf("%s", "queue");
		exit(1);
	}
	clp->source = prog_gpu();
	clp->prog = clCreateProgramWithSource(clp->context, 1, (const char **)&clp->source, NULL, NULL);
	if (!clp->prog)
	{
		printf("%s", "prog");
		exit(1);
	}
	clBuildProgram(clp->prog, 0, NULL, NULL, NULL, NULL);
	clp->kernel = clCreateKernel(clp->prog, "calc_draw", NULL);
	//calculate_draw(&p);
	p.clp = clp;
	//calculate_draw(&p);
	mlx_hook(p.win, 2, 1L << 0, button_press, (void *)&p);
	mlx_hook(p.win, 4, 1L << 2, mouse_press, (void *)&p);
	mlx_hook(p.win, 6, 1L << 6, mouse_motion, (void *)&p);
	mlx_loop(p.conn);
}
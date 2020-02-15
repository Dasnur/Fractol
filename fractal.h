#ifndef FRACTAL_H
#define FRACTAL_H

#include "../minilibx/mlx.h"
#include <math.h>
#include "libft/libft.h"
#include <CL/cl.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>

#define MAX_ITER 255
#define PROG_GPU "compute_gpu.cl"
#define HEIGHT 1000
#define WIDTH 1800

typedef struct 		s_clp
{
	int				ret;
	cl_platform_id	plat_id;
	cl_uint			ret_num_platforms;
	cl_device_id	dev_id;
	cl_context		context;
	cl_command_queue	command_queue;
	char			*source;
	cl_program		prog;
	cl_kernel		kernel;
	cl_mem			buffer;
	cl_device_info	dev_info;
}					t_clp;
	
typedef struct		s_clr
{
	int				r;
	int				g;
	int				b;
}					t_clr;

typedef struct		s_img
{
	void			*p_img;
	char			*img_data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct      s_param
{
	void			*win;
	void			*conn;
	int				i;
	int				j;
	t_img			img;
	t_clr			clr;
	t_clp			*clp;
	int				height;
	int				width;
	double			re_min;
	double			re_max;
	double			im_min;
	double			im_max;
	double			c_re;
	double			c_im;
	double			x;
	double			y;
	double			x_new;
	int				iter;
	int				iter_max;
	int				mse_x;
	int				mse_y;
	size_t			global;
}					t_param;

void	init_kernel_arg(t_clp *clp, t_param *p);

#endif
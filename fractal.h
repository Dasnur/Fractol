#ifndef FRACTAL_H
#define FRACTAL_H

#include "../minilibx/mlx.h"
#include <math.h>
#include "libft/libft.h"
#include <Cl/cl.h>

#define MAX_ITER 255

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
}					t_param;


#endif
__kernel void calc_draw(__global int *output, int height, int width,
double re_max, double re_min, double im_max, double im_min, int iter_max)
{
	int		id;
	double	c_re;
	double	c_im;
	double	x;
	double	y;
	int		iter;
	double	tmp;

	idx = get_global_id(0);
	idy = get_global_id(1);
	if (idx + idy * width < 0 || idx + idy * width >= width * height)
		return ;
    c_re = (double)(idx / (width / (re_max - re_min)) + re_min);
	c_im = (double)(idy / (height / (im_max - im_min)) + im_min);
	x = 0.0;
	y = 0.0;
	iter = 0;
	while (iter < iter_max && (x * x + y * y < 4))
	{
		tmp = (x * x - y * y + c_re);
		y = (2 * x * y + c_im);
		x = tmp;
		iter++;
	}
	if (iter < iter_max)
		output[idx + idy * width] += iter;
}
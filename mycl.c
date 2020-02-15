#include "fractal.h"

void	init_kernel_arg(t_clp *clp, t_param *p)
{
	clSetKernelArg(clp->kernel, 0, sizeof(cl_mem), &clp->buffer);
	clSetKernelArg(clp->kernel, 1, sizeof(int), &p->height);
	clSetKernelArg(clp->kernel, 2, sizeof(int), &p->width);
	clSetKernelArg(clp->kernel, 3, sizeof(double), &p->re_max);
	clSetKernelArg(clp->kernel, 4, sizeof(double), &p->re_min);
	clSetKernelArg(clp->kernel, 5, sizeof(double), &p->im_max);
	clSetKernelArg(clp->kernel, 6, sizeof(double), &p->im_min);
	clSetKernelArg(clp->kernel, 7, sizeof(int), &p->iter_max);
}
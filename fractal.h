#ifndef FRACTAL_H
#define FRACTAL_H

#include "minilibx/mlx.h"
#include <math.h>

typedef struct      s_img
{
    void    *p_img;
    char    *img_data;
    int     bpp;
    int     size_line;
    int     endian;
}                   t_img;

typedef struct      s_frac
{
    void    *win;
    void    *conn;
    int     i;
    int     j;
    t_img   img;
    int     height;
    int     width;
}                   t_frac;


#endif
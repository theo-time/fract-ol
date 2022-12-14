
#include "fractol.h"

int coloring(int n, t_model *model)
{

	if(n < model->max_iter)
	{
		// Smootheming
		n = pow(n, 1);

		// Color shift
		n = (n + model->color_shift) % model->max_iter;

		// Color precision adjust
		n = n * model->color_precision % model->max_iter;
	}

	if (model->color_algo_id == 13)
		return (histogram(n, model));


	return((model->color_algo)(n, model->color_shift, model->color_precision, model->max_iter));
}

int	neutral(int n, int color_shift, int color_precision, int max_iter)
{
	(void) max_iter;
	(void) color_shift;
	(void) color_precision;
	return (n);
}

int yellow_BnW(int n, int color_shift, int color_precision, int max_iter)
{
	(void) color_shift;
	(void) color_precision;
	int r, g, b;
	r = 255 - ((float) n * 10 / (float) max_iter ) * 255;
	g =  255 - ((float) n * 10 / (float) max_iter )* 255;
	b =  255 - ((float) n * 10 / (float) max_iter ) * 255;
	return (create_trgb(255, r, g, b));
} 

int	black_n_white(int n, int color_shift, int color_precision, int max_iter)
{

	(void) color_shift;
	(void) color_precision;
	int r, g, b;
	r =  (int) (((float) (n ) / (float) max_iter ) * 255) % 255;
	g =  (int) (((float) (n ) / (float) max_iter ) * 255) % 255;
	b =  (int) (((float) (n ) / (float) max_iter ) * 255) % 255;
	return (create_trgb(255, r, g, b));
} 

int	one_color_gradient(int n, int color_shift, int color_precision, int max_iter)
{
	(void) max_iter;
	(void) color_shift;
	(void) color_precision;
	int r, g, b;
	r = 255 - n * 255 / 100;
	g = 0;
	b = 0;
	return (create_trgb(255, r, g, b));
} 

int	one_color_gradient2(int n, int color_shift, int color_precision, int max_iter)
{
	(void) color_shift;
	(void) color_precision;
	int r, g, b;
	r = (float) (n * n) / (float) (max_iter * max_iter) * 255 ;
	g = 0;
	b = 0;
	if(n == max_iter)
		return (create_trgb(255, 0, 0, 0));
	return (create_trgb(255, r, g, b));
} 

int	multicolor2(int n, int color_shift, int color_precision, int max_iter)
{
	(void) max_iter;
	(void) color_shift;
	(void) color_precision;
	int r, g, b;
	r = n * 1000 % 255;
	g = n % 255;
	b = n * 1000 % 255;
	return (create_trgb(255, r, g, b));
} 

int	rainbow_efficient(int n, int color_shift, int color_precision, int max_iter)
{
	(void) color_shift;
	(void) color_precision;
	int black = create_trgb(255, 0, 0, 0);
	int color1 = create_trgb(255, 255, 0, 0);
	int color2 = create_trgb(255, 255, 128, 0);
	int color3 = create_trgb(255, 128, 255, 0);
	int color4 = create_trgb(255, 0, 255, 0);
	int color5 = create_trgb(255, 0, 255, 128);
	int color6 = create_trgb(255, 0, 255, 255);
	int color7 = create_trgb(255, 0, 128, 255);
	int color8 = create_trgb(255, 0, 0, 255);
	int color9 = create_trgb(255, 127, 0, 255);
	int color10 = create_trgb(255, 255, 0, 255);
	int color11 = create_trgb(255, 255, 0, 127);

	int colors[11] = {color1,color2,color3,color4,color5,color6,color7,color8,color9,color10, color11};
	if(n == max_iter)
		return(black);	
	return (colors[ (5 + (int) (((float) n / (float) max_iter) * 11.0f)) % 11 ]);
} 

int	rainbow_efficient2(int n, int color_shift, int color_precision, int max_iter)
{
	(void) color_shift;
	(void) color_precision;
	int black = create_trgb(255, 0, 0, 0);
	int color1 = create_trgb(255, 255, 0, 0);
	int color2 = create_trgb(255, 255, 128, 0);
	int color3 = create_trgb(255, 128, 255, 0);
	int color4 = create_trgb(255, 0, 255, 0);
	int color5 = create_trgb(255, 0, 255, 128);
	int color6 = create_trgb(255, 0, 255, 255);
	int color7 = create_trgb(255, 0, 128, 255);
	int color8 = create_trgb(255, 0, 0, 255);
	int color9 = create_trgb(255, 127, 0, 255);
	int color10 = create_trgb(255, 255, 0, 255);
	int color11 = create_trgb(255, 255, 0, 127);

	if(n == max_iter)
		return(black);
	n = (n + 50) % max_iter;
	if(n < 5)
		return(color1);
	else if(n < (float) 10 / (float) 100 * max_iter)
		return(color2);
	else if(n < (float)20 / (float) 100 * max_iter)
		return(color3);
	else if(n < (float)30 / (float) 100 * max_iter)
		return(color4);
	else if(n < (float)40 / (float) 100 * max_iter)
		return(color5);
	else if(n < (float)50 / (float) 100 * max_iter)
		return(color6);	
	else if(n < (float)60 / (float) 100 * max_iter)
		return(color7);
	else if(n < (float)70 / (float) 100 * max_iter)
		return(color8);
	else if(n < (float)80 / (float) 100 * max_iter)
		return(color9);
	else if(n < (float)90 / (float) 100 * max_iter)
		return(color10);
	else 
		return(color11);
	return(create_trgb(255, 255, 0, 127));
} 

int	rainbow_efficient3(int n, int color_shift, int color_precision, int max_iter)
{


	(void) color_shift;
	(void) color_precision;
	// n = (model->max_iter - n) % model->max_iter;
	if(n == max_iter)
		return(create_trgb(255, 0, 0, 0));	
	else if(n < 60)
		return(create_trgb(255, 255, 0, 0));
	else if(n < 70)
		return(create_trgb(255, 255, 128, 0));
	else if(n < 80)
		return(create_trgb(255, 0, 255, 0));
	else if(n < 90)
		return(create_trgb(255, 0, 128, 255));
	else if(n < (5 / 5) * max_iter)
		return(create_trgb(255, 255, 0, 255));
	return(create_trgb(255, 255, 0, 127));
} 



int	basic_HSV(int m, int color_shift, int color_precision, int max_iter)
{
	float hue;
	int saturation;
	int value;

	(void) color_shift;
	(void) color_precision;
	if (m == max_iter)
		return(create_trgb(255,0,0,0));

	hue = (int) (360 * ((float) m  / (float) max_iter)) % 360;
	saturation = 100;
	// printf("%d\n", m);
	if (m < max_iter)
		value = 100;
	else 
		value = 0;
	return (create_HSV(hue, saturation, value));
} 

int	shaded_HSV(int m, int color_shift, int color_precision, int max_iter)
{
	int hue;
	int saturation;
	int value;

	(void) color_shift;
	(void) color_precision;
	if (m == max_iter)
		return(create_trgb(255,0,0,0));
	
	// m = (m + model->color_shift + model->max_iter) % model->max_iter;


	hue = ((float) m / (float) 10);
	saturation = 100;//(100.0f * ((float) m / (float) model->max_iter));

	// printf("%d\n", m);
	if (m < max_iter)
		value = (m * 5) % 100;
	else 
		value = 0;
	return (create_HSV(hue, saturation, value));
} 

int	shaded_HSV_2(int m, int color_shift, int color_precision, int max_iter)
{
	int hue;
	int saturation;
	int value;
	(void) color_shift;
	(void) color_precision;

	if (m == max_iter)
		return(create_trgb(255,0,0,0));

	hue = 100; //(360.0f * ((float) m / (float) model->max_iter));
	saturation = (100.0f * ((float) m / (float) max_iter));

	// printf("%d\n", m);
	if (m < max_iter)
		value = (m * 5) % 100;
	else 
		value = 0;
	return (create_HSV(hue, saturation, value));
} 

int    polynomials(int n, int color_shift, int color_precision, int max_iter)
{
    double    t;
    int r;
	int g;
	int b;
	(void) color_shift;
	(void) color_precision;
	// ft_printf("n : %d", n);
    t = (double) n / (double) max_iter;
    r = 9 * (1 - t) * pow(t, 3) * 255;
    g = 15 * pow((1 - t), 2) * pow(t, 2) * 255;
    b =  8.5 * pow((1 - t), 3) * t * 255;
    return (((int)r << 16) | ((int)g << 8) | ((int)b));
}

// double linear_interpolation(color1, color2, t):
//     return color1 * (1 - t) + color2 * t 

float lerp(float color1, float color2, int t)
{
    return (color1 * (1 - t) + color2 * t);
}


int    histogram(int n, t_model *m)
{
 	static float hue = 0;
	float saturation;
	float value;
	hue = 360.0f  - (360.0f * lerp(m->hues[(int)floor(n)], m->hues[(int)ceil(n)], n % 1));
	saturation = 100;
	if (n < m->max_iter)
		value = 100;
	else 
	 	value = 0;
	// if(value == 0)
	// 	printf("%f \n", value);
	return (create_HSV(hue, saturation, value));
}


// int    polynomials_red(int n, int color_shift, int color_precision)
// {
//     double    t;
//     int r;
// 	int g;
// 	int b;
// 	(void) color_shift;
// 	(void) color_precision;
//     t = pow(0.5,((double) ((m * model->color_precision) % model->max_iter) / (double) model->max_iter));
//     r = 9 * (1 - t) * pow(t, 3) * 255;
//     g = 15 * pow((1 - t), 2) * pow(t, 2) * 255;
//     b =  8.5 * pow((1 - t), 3) * t * 255;
//     return (((int)r << 16) | ((int)g << 8) | ((int)b));
// }



// int    polynomials_2_colors_tweak(int n, int color_shift, int color_precision)
// {
//     double    t;
//     int r;
// 	int g;
// 	int b;
// 	(void) color_shift;
// 	(void) color_precision;
//     t = (int)( (double) m / (double) model->max_iter)  % 255;
//     r = (int) (9 * (1 - t) * pow(t, 3) * 255 * model->color_precision) % 255;
//     g = (int) (15 * pow((1 - t), 2) * pow(t, 2) * 255 * model->color_precision) % 255;
//     b = (int) (8.5 * pow((1 - t), 3) * t * 255 * model->color_precision) % 255;
//     return (((int)r << 16) | ((int)g << 8) | ((int)b));
// }

// int	histogram(int n, int color_shift, int color_precision)
// {
// 	(void) color_shift;
// 	(void) color_precision;
// }

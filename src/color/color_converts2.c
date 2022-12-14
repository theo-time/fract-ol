
#include "fractol.h"

double double_abs(double db)
{
    if(db < 0)
        return -db;
    return(db);
}

int	create_HSV(float H, float S, float V)
{
    if(H>360 || H<0 || S>100 || S<0 || V>100 || V<0)
    {
        ft_printf("The givem HSV values are not in valid range : %d %d %d \n", H, S, V);
        return create_trgb(255,30,30,30);
    }
    
    float s = (float) S / (float) 100; // = 1 always
    float v = V / (float) 100; // = 1 always
    float C = (float)s * (float) v; // = 1 always
    float X = C * (float) (1-double_abs(fmod(H / 60.0f, 2.0f) - 1));
    float m = v - C; // = 0 always 
    float r,g,b;

    if(H >= 0 && H < 60){
        r = C,g = X,b = 0;
    }
    else if(H >= 60 && H < 120){
        r = X,g = C,b = 0;
    }
    else if(H >= 120 && H < 180){
        r = 0,g = C,b = X;
    }
    else if(H >= 180 && H < 240){
        r = 0,g = X,b = C;
    }
    else if(H >= 240 && H < 300){
        r = X,g = 0,b = C;
    }
    else{
        r = C,g = 0,b = X;
    }

    int R = (r+m)*255.0f;
    int G = (g+m)*255.0f;
    int B = (b+m)*255.0f;
    // printf("s : %f | v : %f | C : %f | X : %f \n", s, v, C, X); 
    // printf("%d | %d | %d | %f \n", R, G, B, m); 
    return create_trgb(255, R,G,B);
}

// z = 255 * [1 - |(H/60)mod_2 - 1|],

#include "fractol.h"

void move_camera(int keycode, t_model *m)
{
    // printf("keycode : %d \n", keycode);
    // printf("camera pos : %f | %f \n",  camera->pos.x, camera->pos.y);
    if(keycode == 65361)
        m->camera.pos.x -= m->camera.size.x  / 10.0f;
    if(keycode == 65362)
        m->camera.pos.y -= m->camera.size.y  /  10.0f;
    if(keycode == 65363)
        m->camera.pos.x += m->camera.size.x  /  10.0f;
    if(keycode == 65364)
        m->camera.pos.y += m->camera.size.y  /  10.0f;

    compute(m);
	render(m);
}

t_vector interpolate(t_vector a, t_vector b, float f)
{
    t_vector output;

    output.x = (b.x - a.x) * f;
    output.y = (b.y - a.y) * f;
    return output;
}


t_vector v_add(t_vector a, t_vector b)
{
    t_vector output;

    output.x = a.x + b.x;
    output.y = a.y + b.y;
    return output;
}

void zoom_in(t_camera *camera, int x, int y)
{
    camera->pos = v_add(camera->pos, interpolate(camera->pos, pixel_to_pos(x, y, *camera), 0.3));//+= (x - camera->pos.x) / 2;/+= (y- camera->pos.y) / 2;
    camera->size.x /= 1.2f;
    camera->size.y /= 1.2f;
}

void zoom_out(t_camera *camera, int x, int y)
{
	(void) x;
	(void) y;
    camera->size.x *= 1.2f;
    camera->size.y *= 1.2f;
}
#include <physic.h>
#include <world.h>

t_wall	polygon_to_wall(t_polygon poly)
{
	t_double3	triangle[3];

	triangle[0] = (t_double3){poly.v01[0], poly.v01[1], poly.v01[2]};
	triangle[1] = (t_double3){poly.v12[0], poly.v12[1], poly.v12[2]};
	triangle[2] = (t_double3){poly.v20[0], poly.v20[1], poly.v20[2]};
	return (wall_from_triangle(triangle)); //lazy way of things
}

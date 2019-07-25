#include <physic.h>

/*
** extrusion: x: size of the extrusion, displacement (along the normal) of the extrusion
*/

/*
int	point_in_extruded_wall(t_double3 point, t_wall wall, t_double2 extrusion, double *correction)
{
	t_double3	v;
	double		d;
	t_double3	p;
	double		dots[3];
	double		y;

	// printf("point: %f %f %f\n", point.x, point.y, point.z);
	v = d3_substract(point, wall.center);
	y = d3_dot_product((t_double3){0, 1, 0}, wall.normal);
	// printf("y det (1 floor, 0 wall, -1 ceiling): %f\n", y);
	d = d3_dot_product(v, wall.normal);
	// printf("det: %f\n", d);
	p = d3_substract(point, d3_scale(wall.normal, d));
	// printf("projection: %f %f %f\n", p.x, p.y, p.z);
	dots[0] = d3_dot_product(d3_substract(p, wall.vertices[0]), d3_substract(wall.vertices[1], wall.vertices[0]));
	dots[1] = d3_dot_product(d3_substract(p, wall.vertices[1]), d3_substract(wall.vertices[2], wall.vertices[1]));
	dots[2] = d3_dot_product(d3_substract(p, wall.vertices[2]), d3_substract(wall.vertices[0], wall.vertices[2]));
	// printf("dots: %f %f %f\n", dots[0], dots[1], dots[2]);
	if ((dots[0] > 0.0 || dots[1] > 0.0 || dots[2] > 0.0)
			&& (dots[0] < 0.0 || dots[1] < 0.0 || dots[2] < 0.0))
		return (0);
	// printf("in triangle\n");
	double md = (d < 0.0 ? -1.0 : 1.0) * d3_magnitude(d3_substract(p, point));
	// printf("magnitude * direction of p->p' %f\n", md);
	double ec = //(1.0 - fabs(y)) *
		extrusion.y;
	// printf("extrusion correction: %f\n", ec);
	// printf("positive extrusion (in front of the wall): %f\n", ec);
	// printf("negative extrusion (behind the wall): %f\n", extrusion.x - ec);
	if (md < ec && md > -(extrusion.x - ec))
		;// printf("in extrusion\n");
	else
		return (0);
	// printf("correction multiplicator: %f\n", ec - md);
	if (correction != NULL)
		*correction = ec - md;
	return (1);
}
*/

int	point_in_extruded_wall(double point[3], t_wall wall, double extrusion[2], double *correction)
{
	double		v[3];
	double		d;
	double		p[3];
	double		dots[3];

	d = vec3_dot(v, wall.normal);
	vec3scalar_multiply(wall.normal, d, p);
	vec3vec3_substract(point, p, p);
	dots[0] = vec3_dot((double[3]){p[0] - wall.vertices[0][0], p[1] - wall.vertices[0][1], p[2] - wall.vertices[0][2]}, (double[3]){wall.vertices[1][0] - wall.vertices[0][0], wall.vertices[1][1] - wall.vertices[0][1], wall.vertices[1][2] - wall.vertices[0][2]});
	dots[1] = vec3_dot((double[3]){p[0] - wall.vertices[1][0], p[1] - wall.vertices[1][1], p[2] - wall.vertices[1][2]}, (double[3]){wall.vertices[2][0] - wall.vertices[1][0], wall.vertices[2][1] - wall.vertices[1][1], wall.vertices[2][2] - wall.vertices[1][2]});
	dots[2] = vec3_dot((double[3]){p[0] - wall.vertices[2][0], p[1] - wall.vertices[2][1], p[2] - wall.vertices[2][2]}, (double[3]){wall.vertices[0][0] - wall.vertices[2][0], wall.vertices[0][1] - wall.vertices[2][1], wall.vertices[0][2] - wall.vertices[2][2]});
	if ((dots[0] > 0.0 || dots[1] > 0.0 || dots[2] > 0.0)
		&& (dots[0] < 0.0 || dots[1] < 0.0 || dots[2] < 0.0))
		return (0);
	double md = (d < 0.0 ? -1.0 : 1.0) * vec3_magnitude((double[3]){p[0] - point[0], p[1] - point[1], p[2] - point[2]});
	double ec = /*(1.0 - fabs(y)) * */extrusion[1];
	if (md > ec || md < -(extrusion[0] - ec))
		return (0);
	if (correction != NULL)
		*correction = ec - md;
	return (1);
}

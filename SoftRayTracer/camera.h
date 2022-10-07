#pragma once

#include "rtweekend.h"

class camera
{
public:
	camera(
		vec3 lookfrom,vec3 lookat,vec3 vup,
		double vfov,//垂直方向的fov（摄像机到视口上方和摄像机到视口下方的夹角）
		double aspect,//视口宽长比
		double aperture,
		double focus_dist,
		double t0=0,
		double t1=0
	)
	{
		origin = lookfrom;//摄像机的位置
		
		lens_radius = aperture / 2;
		time0 = t0;
		time1 = t1;
		auto theta = degrees_to_radians(vfov);
		auto half_height = tan(theta / 2);
		auto half_width = aspect * half_height;

		w = unit_vector(lookfrom - lookat);
		u = unit_vector(cross(vup, w));
		v = cross(w, u);

		lower_left_corner = origin 
							- half_width *focus_dist* u 
							- half_height * focus_dist * v
							- focus_dist * w;

		horizontal = 2 * half_width * focus_dist * u;
		vertical = 2 * half_height * focus_dist * v;
	}

	ray get_ray(double s, double t)
	{
		vec3 rd = lens_radius * random_in_unit_disk();
		vec3 offset = u * rd.x() + v * rd.y();

		return ray(
			origin + offset,
			lower_left_corner + s * horizontal + t * vertical - origin - offset,
			random_double(time0, time1)
		);
	}

public:
	vec3 origin;
	vec3 lower_left_corner;
	vec3 horizontal;
	vec3 vertical;
	vec3 u, v, w;//表示摄像机旋转的三个单位向量
	double lens_radius;
	double time0, time1;//快门打开和关闭的时间
};
#pragma once
#include "vec3.h"

class ray
{
public:
	ray() {}
	ray(const vec3& origin,const vec3& directon,double time=0.0)
		:orig(origin),dir(directon),tm(time)
	{}

	vec3 origin() const { return orig; }
	vec3 direction() const { return dir; }
	double time() const { return tm; }

	vec3 at(double t)const
	{
		return orig + t * dir;
	}
public:
	vec3 orig;
	vec3 dir;
	double tm;
};
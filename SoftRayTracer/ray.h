#pragma once
#include "vec3.h"

class ray
{
public:
	ray() {}
	ray(const vec3& origin,const vec3& directon)
		:orig(origin),dir(directon)
	{}

	vec3 origin() const { return orig; }
	vec3 direation() const { return dir; }

	vec3 at(double t)const
	{
		return orig + t * dir;
	}
public:
	vec3 orig;
	vec3 dir;
};
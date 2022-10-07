#pragma once

#include "rtweekend.h"
#include "material.h"

class lambertian :public material 
{
public:
	lambertian(const vec3& a):albedo{a}{}
	virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered)const override;
public:
	vec3 albedo;
};


bool lambertian::scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const
{
	vec3 scatter_direction = rec.normal + random_unit_vector();
	scattered = ray(rec.p, scatter_direction,r_in.time());
	attenuation = albedo;
	return true;
}
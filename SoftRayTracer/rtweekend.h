#pragma once

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

//使用指定名字空间下的名称
using std::shared_ptr;
using std::make_shared;

//常量
const double infinity = std::numeric_limits<double>::infinity();
const double PI = 3.1415926535897932385;

//工具函数
inline double degrees_to_radians(double degrees)
{
	return degrees * PI / 180;
}

inline double ffmin(double a, double b) { return a <= b ? a : b; }
inline double ffman(double a, double b) { return a <= b ? b : a; }

//C
inline double random_double()
{
	return rand() / (RAND_MAX + 1.0);
}

//C++
/*inline double random_double()
{
	static std::uniform_real_distribution<double> distribution(0.0, 1.0);
	static std::mt19937 generator;
	static std::function<double()> rand_generator =
		std::bind(distribution, generator);
	return rand_generator();
}*/

inline double random_double(double min, double max)
{
	return min + (max - min) * random_double();
}

inline double clamp(double x, double min, double max)
{
	if (x < min) return min;
	if (x > max) return max;
	return x;
}

//通用头文件
#include "ray.h"
#include "vec3.h"
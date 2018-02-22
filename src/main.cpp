#include <iostream>
#include "camera.hpp"
#include <cmath>
#include "triangle.hpp"

using namespace ray_tracer::math;
using namespace ray_tracer::core;
using namespace ray_tracer::light;
using namespace ray_tracer::geometry;

int main()
{
  int resolution = 512;
  
  Camera c(resolution, resolution);
  Triangle t(Vec3f(-1.0f, 1.0f, 4.0f), Vec3f(1.0f, 1.0f, 4.0f), Vec3f(1.0f, -1.0f, 4.0f));

  for(int i = 0; i < resolution; ++i){
    for(int j = 0; j < resolution; ++j){
      Ray v = c.GenerateRay(j, i);
      if(t.Intersect(v)){
	c.SetPixel(j, i, Color(1.0f, 1.0f, 1.0f));
	std::cout << "intersection\n";
      }
    }
  }

  c.SaveImage("test.ppm");
  
  return 0;
}

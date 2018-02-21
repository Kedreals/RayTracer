#include <iostream>
#include "camera.hpp"
#include <cmath>

using namespace ray_tracer::math;
using namespace ray_tracer::core;

int main()
{
  int resolution = 4;
  
  Camera c(resolution, resolution);

  std::cout << c.GetFov() << "\n";
  for(int i = 0; i < resolution; i = i + resolution/4){
    for(int j = 0; j < resolution; j = j + resolution/4){
      Vec3f v = c.GenerateRay(i,j).D();
      std::cout << v.X() << " ";
    }
    std::cout << "\n";
  }
  
  return 0;
}

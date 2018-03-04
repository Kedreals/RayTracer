#include <iostream>
#include "camera.hpp"
#include <cmath>
#include "triangle.hpp"
#include "main.cuh"
#include "monteCarlo.hpp"
#include <ctime>

using namespace ray_tracer::math;
using namespace ray_tracer::core;
using namespace ray_tracer::light;
using namespace ray_tracer::geometry;

/** \todo Intersection class
    \todo scene class
    \todo loading a scene
    \todo vertex class
    \todo bounding volume hirarchy
    \todo model class
    \todo implementing cuda functions
 */

float evalPercent(int i, int resolution)
{
  return 100.0*(float)i/(float)resolution;
}

void printProgress(int i, int resolution)
{
  float p = evalPercent(i, resolution);
  printf("\033[s%f%% of pixel have been renderered [\033[32m%s\033[37m%s]\033[u", p, std::string((int)(p/5), '=').c_str(), std::string(20-(int)(p/5), '=').c_str());
}

int main()
{
  int resolution = 512;
  
  Camera c(resolution, resolution);
  
  Triangle* obj = (Triangle*)malloc(2*sizeof(Triangle));
  Triangle* lights = (Triangle*)malloc(2*sizeof(Triangle));

  float xstart = -5.0;
  float y = 3.0;
  float zstart = 0.0;
  float xdim = 10.0;
  float zdim = 10.0;
  
  obj[0] = Triangle(Vec3f(xstart, y, zstart), Vec3f(xstart+xdim, y, zstart), Vec3f(xstart+xdim, y, zstart+zdim));
  obj[1] = Triangle(Vec3f(xstart, y, zstart), Vec3f(xstart+xdim, y, zstart+zdim), Vec3f(xstart, y, zstart+zdim));

  lights[0] = Triangle(Vec3f(xstart+0.35f*xdim, -y, zstart+0.35f*zdim), Vec3f(xstart+0.65f*xdim, -y, zstart+0.35f*zdim), Vec3f(xstart+0.65f*xdim, -y, zstart+0.65f*zdim), 100.0f);
  lights[1] = Triangle(Vec3f(xstart+0.35f*xdim, -y, zstart+0.35f*zdim), Vec3f(xstart+0.65f*xdim, -y, zstart+0.65f*zdim), Vec3f(xstart+0.35f*xdim, -y, zstart+0.65f*zdim), 100.0f);
  
  int multisampling = 16;

  printf("Start rendering a %ix%i image with %i multisampling\n", resolution, resolution, multisampling);
  clock_t t1 = clock();
  for(int i = 0; i < resolution; ++i){
    printProgress(i, resolution);
    for(int j = 0; j < resolution; ++j){
      Color color(0.0f, 0.0f, 0.0f);
      for(int k = 0; k < multisampling; ++k)
	{
	  Triangle* t;
	  bool intersection = false;
	  Ray v = c.GenerateRay(j,i, multisampling, k);
	  for(int l = 0; l < 2; ++l)
	    {
	      if(obj[l].Intersect(v))
		{
		  intersection = true;
		  t = &obj[l];
		}
	    }
	  for(int l = 0; l < 2; ++l)
	    {
	      if(lights[l].Intersect(v))
		{
		  intersection = true;
		  t = &lights[l];
		}
	    }

	  if(intersection)
	    color += t->GetColor()*(MonteCarlo(v(), t->GetNormal(), 2, obj, 2, lights, 128) + t->GetEll());
	}
      c.SetPixel(j, i, color*(1.0f/static_cast<float>(multisampling)));
    }
  }
  t1 = clock() - t1;
  printProgress(resolution, resolution);
  std::cout << std::endl;
  printf("rendering took %fs\n", (float)t1/(float)CLOCKS_PER_SEC);
  c.SaveImage("test.ppm");

  free(obj);
  free(lights);
  
  return 0;
}

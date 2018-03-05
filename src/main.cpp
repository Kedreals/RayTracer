#include "camera.hpp"
#include "monteCarlo.hpp"
#include <ctime>

using namespace ray_tracer::core;
using namespace ray_tracer::light;

/** \todo indirect light
    \todo loading a scene
    \todo vertex class
    \todo bounding volume hirarchy
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

  Scene scene;
  
  int multisampling = 4;
  int directLightSampleCount = 128;

  printf("Start rendering a %ix%i image with %i sample per pixel and %i direct light samples\n", resolution, resolution, multisampling, directLightSampleCount);
  clock_t t1 = clock();
  for(int i = 0; i < resolution; ++i){
    printProgress(i, resolution);
    for(int j = 0; j < resolution; ++j){
      Color color(0.0f, 0.0f, 0.0f);
      for(int k = 0; k < multisampling; ++k)
	{
	  Ray v = c.GenerateRay(j,i, multisampling, k);
	  Intersection intersect;
	  
	  if(scene.Intersect(v, intersect)){
	    color += intersect.Color*(MonteCarlo(intersect.Pos, intersect.N, scene, directLightSampleCount) + intersect.Ell);
	  }
	}
      c.SetPixel(j, i, color*(1.0f/static_cast<float>(multisampling)));
    }
  }
  t1 = clock() - t1;
  printProgress(resolution, resolution);
  std::cout << std::endl;
  float s = (float)t1/(float)CLOCKS_PER_SEC;
  int min = (int)s / 60;
  s = ((int)s*100 % 6000)/100.0f;
  int h = min / 60;
  min = min % 60;
  printf("rendering took %ih %im %fs\n", h, min, s);
  c.SaveImage("test.ppm");
  
  return 0;
}

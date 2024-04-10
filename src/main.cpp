#include <string>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
#include"Mesh.hpp"
// #include"Scene.hpp"
#include"Camera.hpp"
#include"LightSource.hpp"
#include"Vector.hpp"
#include"Material.hpp"
#include"Vector.hpp"
#include"Sphere.hpp"
#include"ImagePlane.hpp"


class Scene
{
    public:
        Scene(int height, int width)
            :planeWidth(width), planeHeight(height)
        {
            spheres.push_back(Sphere(150, Vector(-100, 0, 0)));
            spheres.push_back(Sphere(150, Vector(100, 0, 0)));
        }
        int getHight() const;
        int getWidth() const;
        
        void traceRays(std::string);
        RGBColor castRay(int, int);
    private:
        int planeWidth;
        int planeHeight;
        std::vector<Sphere> spheres;

};
void Scene::traceRays(std::string file)
{
    ImagePlane image(planeWidth, planeHeight);
    for(int x = 0; x < planeWidth; x++)
    {
        for(int y = 0; y < planeHeight; y++)
        {
            image.setPixel(x, y, castRay(x, y));
        }
    }
       image.WritePpm(file.c_str(), true);

}
RGBColor Scene::castRay(int x, int y)
{
    int rayX  = x - planeWidth / 2;
    int rayY = y - planeHeight / 2;

    Ray ray(Vector(rayX, rayY, -100), Vector(rayX, rayY, -99));
    for (std::vector<Sphere>::iterator itr = spheres.begin(); itr < spheres.end(); itr++) {
        
        bool intersection = itr->checkIntersection(ray);

        if (intersection == true) 
        {
            //std::cout<<"Pixel is returned"<<std::endl;
            return RGBColor(1.0, 1.0, 1.0); // Set interesction points to white
        }
    }

    return RGBColor(0.0, 0.0, 0.0); // Set to Black
}


int main()
{
    Scene firstScene(500, 500);
    
    std::cout<<"Program is on run"<<std::endl;
    
    std::string outputFile = "firstScene.ppm";

    firstScene.traceRays(outputFile);
}
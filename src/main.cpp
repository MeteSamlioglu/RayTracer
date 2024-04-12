#include <string>
#include<iostream>
#include<stdio.h>
#include <limits>
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
#include"IntersectionPoint.hpp"
#include"Objects.hpp"



class Scene
{
    public:
        Scene(int height, int width)
            :planeWidth(width), planeHeight(height)
        {
            objects.push_back(new Sphere(150, Vector(-100, 0, 0), RGBColor(1.0, 0.0, 0.0)));
            objects.push_back(new Sphere(150, Vector(100, 0, 0), RGBColor(0.0, 1.0, 0.0)));
        }
        int getHight() const;
        int getWidth() const;
        ~Scene();
        void traceRays(std::string);
        RGBColor castRay(int, int);
    private:
        int planeWidth;
        int planeHeight;
        std::vector<Objects*> objects;

};
Scene::~Scene()
{
    for(std::vector<Objects*>::iterator itr = objects.begin(); itr < objects.end(); itr++)
    {
        delete *itr;
    }
}
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
    //IntersectionPoint closestIntersection = IntersectionPoint();

    //closestIntersection.setDistance(std::numeric_limits<double>::max());
    
    for (std::vector<Objects*>::iterator itr = objects.begin(); itr < objects.end(); itr++) {
        
        IntersectionPoint intersection = (*itr)->checkIntersection(ray);

        if (intersection.isIntersected() == true /*&& intersection.getDistance() < closestIntersection.getDistance() */) 
        {
            //return RGBColor(1.0, 1.0, 1.0); // Set interesction points to white
            //closestIntersection = intersection;
            //std::cout<<intersection.getColor().getR()<<" "<<intersection.getColor().getG()<<intersection.getColor().getB()<<std::endl;
            //std::cout<<"Color "<<intersection.getColor().getR()<<" "<<intersection.getColor().getG()<<" "<<intersection.getColor().getB()<<std::endl;
            return intersection.getColor();
        }
    }
    return RGBColor(0.0, 0.0, 0.0); // Set to Black
    //return closestIntersection.getColor();
}


int main()
{
    Scene firstScene(500, 500);
    
    std::cout<<"Program is on run"<<std::endl;
    
    std::string outputFile = "firstScene.ppm";

    firstScene.traceRays(outputFile);
}
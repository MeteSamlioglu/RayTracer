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
#include"Triangle.hpp"
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
            // objects.push_back(new Sphere(150, Vector(-100, 0, 0), RGBColor(1.0, 0.0, 0.0)));
            // objects.push_back(new Sphere(150, Vector(100, 0, 0), RGBColor(0.0, 1.0, 0.0)));
        }
        int getHight() const;
        int getWidth() const;
        ~Scene();
        void traceRays(std::string);
        RGBColor castRay(int, int);

        IntersectionPoint findClosestIntersection(Ray ray);
        RGBColor performLighting(IntersectionPoint point_);
        RGBColor getDiffuseLigt(IntersectionPoint point_);
        RGBColor getAmbientLight(IntersectionPoint point_);

        void addObjectToScene(Objects* sceneObject)
        {
            objects.push_back(sceneObject);
        }

        void addLightToScene(LightSource* ligtSource)
        {
            lights.push_back(ligtSource);    
        }

    private:
        int planeWidth;
        int planeHeight;
        std::vector<Objects*> objects;
        std::vector<LightSource*> lights;

};
Scene::~Scene()
{
    for(std::vector<Objects*>::iterator itr = objects.begin(); itr < objects.end(); itr++)
    {
        delete *itr;
    }
    for(std::vector<LightSource*>::iterator itr = lights.begin(); itr < lights.end(); itr++)
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
IntersectionPoint Scene::findClosestIntersection(Ray ray)
{
    IntersectionPoint closestIntersection = IntersectionPoint();

    closestIntersection.setDistance(std::numeric_limits<double>::max());

     for (std::vector<Objects*>::iterator itr = objects.begin(); itr < objects.end(); itr++) {
        
        IntersectionPoint intersection = (*itr)->checkIntersection(ray);

        if (intersection.isIntersected() == true && intersection.getDistance() < closestIntersection.getDistance()) 
        {
            closestIntersection = intersection;
        }
    }
    return closestIntersection;
}
RGBColor Scene::performLighting(IntersectionPoint point)
{
    RGBColor diffuseColor = getDiffuseLigt(point);
    RGBColor ambientColor = getAmbientLight(point);
    return diffuseColor + ambientColor;
}

RGBColor Scene::getDiffuseLigt(IntersectionPoint point)
{
    RGBColor diffuseColor(0.0, 0.0, 0.0);
    
    for(std::vector<LightSource*>::iterator itr = lights.begin(); itr < lights.end(); itr++)
    {
        LightSource* light = *itr;
        Vector lightOffset = light->getPosition() - point.getIntersectionPoint();
        /*
            TODO: Be careful about normalizing lightOffset too.
        */
        Vector lightDirection = lightOffset.normalize();
        double dotProduct = point.getNormalVector().dotProduct(lightDirection);
        

        /**
         * Intersection is facing light.
        */
       if(dotProduct >= 0.0f)
       {
            diffuseColor = diffuseColor + (point.getColor() * dotProduct);
       }
    }
    
    return diffuseColor;
}
RGBColor Scene::getAmbientLight(IntersectionPoint point_)
{
    return point_.getColor() * 0.2;
}

RGBColor Scene::castRay(int x, int y)
{
    int rayX  = x - planeWidth / 2;
    int rayY = y - planeHeight / 2;

    Ray ray(Vector(rayX, rayY, 100), Vector(0, 0, -1));
    
    IntersectionPoint intersection = findClosestIntersection(ray);
    
    if(intersection.isIntersected())
        return performLighting(intersection);
    else
        return RGBColor();
    //    return RGBColor(0.0, 0.0, 0.6); //Set background to black

}


int main()
{
    Scene myScene(500, 500);
    
    std::cout<<"Program is on run"<<std::endl;
    
    std::string outputFile = "Scene.ppm";

    myScene.addObjectToScene(new Sphere(150, Vector(-300, 0, 0), RGBColor(1.0, 0.0, 0.0)));
    
    myScene.addObjectToScene(new Sphere(100, Vector(300, 0, 0), RGBColor(0.0, 1.0, 0.0)));  

    myScene.addObjectToScene(new Triangle(Vector(150, 0, 0), Vector(0, 150, 0), Vector(0, 0, 150)));

    
    myScene.addLightToScene(new LightSource(Vector(300, 100, 0)));

    myScene.traceRays(outputFile);

    return 0;
}
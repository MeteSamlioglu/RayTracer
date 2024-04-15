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
        Scene(int height, int width, int maxReflections_)
            :planeWidth(width), planeHeight(height), maxReflections(maxReflections_)
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
        RGBColor getSpecularLighting(IntersectionPoint point, LightSource* light_);
        RGBColor getSpecularAndDiffuseLightning(IntersectionPoint point_);
        
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
        int maxReflections;
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
    RGBColor ambientColor = getAmbientLight(point);
    RGBColor diffuseAndSpecularColor = getSpecularAndDiffuseLightning(point);

    return diffuseAndSpecularColor + ambientColor;
}

RGBColor Scene::getSpecularAndDiffuseLightning(IntersectionPoint point)
{
    RGBColor diffuseColor(0.0, 0.0, 0.0);
    RGBColor specularColor(0.0, 0.0, 0.0);

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
            Ray shadow = Ray(point.getIntersectionPoint() + lightDirection, lightDirection, 1);
            IntersectionPoint shadowIntersection = findClosestIntersection(shadow);
            if(shadowIntersection.isIntersected())
            {
                /*
                    Position of object surface is in shadow
                    continue with other lights
                */
                continue;
            }
            
            diffuseColor = diffuseColor + (point.getColor() * dotProduct);
            specularColor = specularColor + getSpecularLighting(point, light);
       }
    }
    
    return diffuseColor + specularColor;
}
RGBColor Scene::getAmbientLight(IntersectionPoint point_)
{
    return point_.getColor() * 0.2;
}

RGBColor Scene::getSpecularLighting(IntersectionPoint point_, LightSource* light_)
{
    RGBColor specularColor(0.0, 0.0, 0.0);
    double shininess = point_.getIntersectedObject()->getShininess();

    if(shininess == NOT_SHINY)
    {
        return specularColor; /* Specular light will not be showen on non shiny objects*/
    }

    Vector view = (point_.ray.origin - point_.getIntersectionPoint()).normalize();
    Vector lightOffset = light_->getPosition() - point_.getIntersectionPoint();
    Vector L = lightOffset.normalize();
    Vector N = point_.getNormalVector();

    Vector R = N * 2 * L.dotProduct(N) - L;
    
    double dotProd = view.dotProduct(R);
    if( dotProd <= 0)
    {
        return specularColor;
    }

    double specularAmount = pow(dotProd, shininess);
    specularColor.setR(specularAmount);
    specularColor.setG(specularAmount);
    specularColor.setB(specularAmount);

    return specularColor;
}

RGBColor Scene::castRay(int x, int y)
{
    int rayX  = x - planeWidth / 2;
    int rayY = y - planeHeight / 2;

    Ray ray(Vector(rayX, rayY, 100), Vector(0, 0, -1), maxReflections);
    
    IntersectionPoint intersection = findClosestIntersection(ray);
    
    if(intersection.isIntersected())
        return performLighting(intersection);
    else
        return RGBColor();
    //    return RGBColor(0.0, 0.0, 0.6); //Set background to black

}


int main()
{
    Scene myScene(600, 600, 10);
    
    std::cout<<"Program is on run"<<std::endl;
    
    std::string outputFile = "Scene.ppm";

    myScene.addObjectToScene(new Sphere(150, Vector(-150, 0, -150), RGBColor(1.0, 0.0, 0.0), 10, 0.5));
    
    myScene.addObjectToScene(new Sphere(25, Vector(50, 50, 25), RGBColor(0.0, 1.0, 0.0), 10, 0.5));  
    //myScene.addObjectToScene(new Triangle(Vector(150, 0, 0), Vector(0, 150, 0), Vector(0, 0, 150)));

    myScene.addLightToScene(new LightSource(Vector(300, 100, 150)));
    myScene.addLightToScene(new LightSource(Vector(-300, 100, 150)));

    myScene.traceRays(outputFile);

    return 0;
}


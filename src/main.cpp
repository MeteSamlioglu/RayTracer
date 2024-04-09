#include <string>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<math.h>
#include"Mesh.hpp"
// #include"Scene.hpp"
#include"Camera.hpp"
#include"LightSource.hpp"
#include"Vector.hpp"
#include"Material.hpp"
#include"ImagePlane.hpp"

class Scene
{
    public:
        Scene(int height, int width)
            :planeWidth(width), planeHeight(height)
        {}
        int getHight() const;
        int getWidth() const;
        void rayTrace(std::string);
        //Color castRay(int, int);
        //RGBColor castRay(int, int);
    private:
        int planeWidth;
        int planeHeight;

};


int main()
{
    std::cout<<"Initial"<<std::endl;
}
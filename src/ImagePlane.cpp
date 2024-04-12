#include"ImagePlane.hpp"
#include<iostream>


ImagePlane::ImagePlane(int planeWidth_, int planeHeight_)
    :planeWidth(planeWidth_), planeHeight(planeHeight_), max(1.0)
{
    pixelMap = (RGBColor **)malloc(sizeof(RGBColor*)*planeWidth_);

    for(int i = 0; i < planeWidth; i++)
    {
        pixelMap[i] = (RGBColor *)malloc(sizeof(RGBColor) * planeHeight);
    }
}


void ImagePlane::WritePpm(const char *outfile, bool scale_color)
{
    FILE *fp = fopen(outfile, "wb"); // Notice the "b" for binary mode
    if (fp == NULL)
    {
        perror("ERROR: Image::WritePpm() failed to open file for writing!\n");
        exit(EXIT_FAILURE);
    }

    int _width = getWidth();
    int _height = getHeight();
    double _max = getMax();

    // Write PPM header
    // P6 format indicates it is a binary file with RGB colors
    fprintf(fp, "P6\n%d %d\n255\n", _width, _height);

    // Write the raw pixel data in RGB order
    for (int y = 0; y < _height; y++)
    {
        for (int x = 0; x < _width; x++)
        {
            unsigned char rbyte, gbyte, bbyte;
            if (scale_color)
            {
                rbyte = (unsigned char)((pixelMap[x][y].getR() / _max) * 255);
                gbyte = (unsigned char)((pixelMap[x][y].getG() / _max) * 255);
                bbyte = (unsigned char)((pixelMap[x][y].getB() / _max) * 255);
            }
            else
            {
                double r = (pixelMap[x][y].getR() > 1.0) ? 1.0 : pixelMap[x][y].getR();
                double g = (pixelMap[x][y].getG() > 1.0) ? 1.0 : pixelMap[x][y].getG();
                double b = (pixelMap[x][y].getB() > 1.0) ? 1.0 : pixelMap[x][y].getB();
                rbyte = (unsigned char)(r * 255);
                gbyte = (unsigned char)(g * 255);
                bbyte = (unsigned char)(b * 255);
            }
            // Write the pixels in RGB order
            fwrite(&rbyte, sizeof(unsigned char), 1, fp);
            fwrite(&gbyte, sizeof(unsigned char), 1, fp);
            fwrite(&bbyte, sizeof(unsigned char), 1, fp);
        }
    }

    fclose(fp);
}
RGBColor ImagePlane::getPixel(int x, int y)
{ 

    return pixelMap[x][y];
}

void ImagePlane::setPixel(int x, int y, RGBColor pixel)
{
    if(x < 0 || x >= getWidth() || y < 0 || y >= getHeight())
    {
        exit(EXIT_FAILURE);
    }

    pixelMap[x][y] = pixel;
    
    /* max color*/
    
    max = (pixel.getR() > max) ? pixel.getR() : max; 
    max = (pixel.getG() > max) ? pixel.getG() : max;
    max = (pixel.getB() > max) ? pixel.getB() : max;
}   


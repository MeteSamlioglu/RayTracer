#include"ImagePlane.hpp"
#include<iostream>


RGBColor::RGBColor(double r_, double g_, double b_)
    :r(r_), g(g_), b(b_), filter(1.0)
{}

RGBColor::RGBColor(double r_, double g_, double b_, double filter_)
    :r(r_), g(g_), b(b_), filter(filter_)
{}

double RGBColor::getR() const
{
    return r;
}
double RGBColor::getG() const
{
    return g;
}
double RGBColor::getB() const
{
    return b;
}
ImagePlane::ImagePlane(int planeWidth_, int planeHeight_)
    :planeWidth(planeWidth_), planeHeight(planeHeight_), max(1.0)
{
    pixelMap = (RGBColor **)malloc(sizeof(RGBColor*)*planeWidth_);

    for(int i = 0; i < planeWidth; i++)
    {
        pixelMap[i] = (RGBColor *)malloc(sizeof(RGBColor) * planeHeight);
    }
}


void ImagePlane::WriteTga(const char *outfile, bool scale_color)
{
    FILE *fp = fopen(outfile, "w");
    if (fp == NULL)
    {
        perror("ERROR: Image::WriteTga() failed to open file for writing!\n");
        exit(EXIT_FAILURE);
    }
    int _width = getWidth();
    int _height = getHeight();
    double _max = getMax();

    // write 24-bit uncompressed targa header
    // thanks to Paul Bourke (http://local.wasp.uwa.edu.au/~pbourke/dataformats/tga/)
    putc(0, fp);
    putc(0, fp);
    
    putc(2, fp); // type is uncompressed RGB
    
    putc(0, fp);
    putc(0, fp);
    putc(0, fp);
    putc(0, fp);
    putc(0, fp);
    
    putc(0, fp); // x origin, low byte
    putc(0, fp); // x origin, high byte
    
    putc(0, fp); // y origin, low byte
    putc(0, fp); // y origin, high byte

    putc(_width & 0xff, fp); // width, low byte
    putc((_width & 0xff00) >> 8, fp); // width, high byte

    putc(_height & 0xff, fp); // height, low byte
    putc((_height & 0xff00) >> 8, fp); // height, high byte

    putc(24, fp); // 24-bit color depth

    putc(0, fp);

    // write the raw pixel data in groups of 3 bytes (BGR order)
    for (int y = 0; y < _height; y++)
    {
        for (int x = 0; x < _width; x++)
        {
            // if color scaling is on, scale 0.0 -> _max as a 0 -> 255 unsigned byte
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
            putc(bbyte, fp);
            putc(gbyte, fp);
            putc(rbyte, fp);
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
#ifndef IMAGEPLANE_HPP
#define IMAGEPLANE_hPP

#include"RGBColor.hpp"

class ImagePlane
{
    public:
        ImagePlane(int planeWidth_, int planeHeight_);
        // ~ImagePlane();
        
        void WritePpm(const char *outfile, bool scale_Color = true);
        void pixel(int x, int y, RGBColor pixel);
        void setPixel(int x, int y, RGBColor pixel);
        RGBColor getPixel(int x, int y);
        
        int getWidth() const { return planeWidth; }
        int getHeight() const { return planeHeight; }
        double getMax() const {return max;}

    private:
        int planeWidth;
        int planeHeight;
        RGBColor **pixelMap;
        double max;
};

#endif
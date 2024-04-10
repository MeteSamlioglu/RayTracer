#ifndef IMAGEPLANE_HPP
#define IMAGEPLANE_hPP

class RGBColor
{
    public:
        RGBColor(double r_, double g_, double b_);
        RGBColor(double r_, double g_, double b_, double filter_);
        double getR() const;
        double getG() const;
        double getB() const;
    private:
        double r;
        double g;
        double b;
        double filter;
};


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
#include "Image_Class.h"
#include <iostream>
int main()
{
    Image image("mario.bmp");
    Image result(image.width, image.height);
    for (int y = 0; y < image.height; y++)
    {
        for (int x = 0; x < image.width; x++)
        {
            for (int z = 0; z < 3; z++)
            {
                int pix=255 - image.getPixel(x,y,z);
                result.setPixel(x, y, z,pix);
            }
        }
    }
    result.saveImage("mario_inverted.bmp");
}
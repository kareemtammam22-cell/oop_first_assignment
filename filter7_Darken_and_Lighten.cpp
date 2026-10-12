#include "Image_Class.h"
#include <iostream>
using namespace std;
int main(){
    Image image("mario.bmp");
    Image result(image.width, image.height);
    for (int y=0;y < image.height;y++)
    {
        for (int x=0;x< image.width;x++ )
        {
            for(int z=0;z<3;z++)
            {
                int pix=image.getPixel(x,y,z)/2;
                result.setPixel(x,y,z,pix);
            }
        }
    }
    result.saveImage("mario_Darken.bmp");

    int double_num= 2;
    for (int y=0;y < image.height;y++)
    {
        for (int x=0;x< image.width;x++ )
        {
            for(int z=0;z<3;z++)
            {
                int oldpix=image.getPixel(x,y,z);
                int newpix=oldpix*2;
                if(newpix>255)
                {
                    newpix=255;
                }
                result.setPixel(x,y,z,newpix);
            }
        }
    }
    result.saveImage("mario_Lighten.bmp");
}
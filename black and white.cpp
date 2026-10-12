#include<iostream>
#include"image_class.h"
using namespace std;
void black_and_white_fillter(Image &image){
    for (size_t i = 0; i <image.width; i++){
        for (size_t j = 0; j < image.height; j++){
            unsigned int avg=0;
            for (size_t k = 0; k < image.channels; k++){
                avg+=image(i,j,k);
            }
            avg/=3;
            image(i,j,0)=avg;
            image(i,j,1)=avg;
            image(i,j,2)=avg;                
            int new_avg=(image(i,j,0)>127?255:0);
            image(i,j,0)=new_avg;
            image(i,j,1)=new_avg;
            image(i,j,2)=new_avg;           
        }
    }    
} 
int main()
{
    Image image("arrow.jpg");
    black_and_white_fillter(image);
    image.saveImage("output.jpg");
}    
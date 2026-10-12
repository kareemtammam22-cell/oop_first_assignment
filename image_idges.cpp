#include<iostream>
#include"image_class.h"
using namespace std;
void Detect_Image_Edges(Image &image){
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
        }

    }
    for (size_t i = 1; i <image.width-1; i++){
        for (size_t j = 1; j < image.height-1; j++){
            if(abs(image(i,j,0)-image(i-1,j,0))>20&&abs(image(i,j,0)-image(i,j+1,0))>20)
        {
            image(i,j,0)=0;
            image(i,j,1)=0;
            image(i,j,2)=0;            
        }
        else{
            image(i,j,0)=255;
            image(i,j,1)=255;
            image(i,j,2)=255;                
        }
        }
    }    
}  
int main()
{
    Image image("arrow.jpg");
    Detect_Image_Edges(image);
    image.saveImage("output.jpg");
}    
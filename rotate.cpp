#include<iostream>
#include"image_class.h"
using namespace std;
void Rotate_90(Image &image){

    Image image2(image.height,image.width);
    for (size_t i = 0; i <image2.width; i++){
        for (size_t j = 0; j < image2.height; j++)
        {
         for (size_t k = 0; k < image2.channels; k++)
         {
            image2(i,j,k)=image(j,image.height-1-i,k);            
         }
        }
    } 
    image=image2;
    }
void Rotate_270(Image &image){      
    Image image3(image.height,image.width);
    for (size_t i = 0; i <image3.width; i++){
        for (size_t j = 0; j < image3.height; j++){
            for (size_t k = 0; k < image3.channels; k++){
                image3(i,j,k)=image(image.width-1-j,i,k);            
            }
        }
    }    
    image=image3;
    }   
  
void Rotate_180(Image &image){      
    Image image9(image.width,image.height);
    for (size_t i = 0; i <image9.width; i++){
        for (size_t j = 0; j < image9.height; j++){
            for (size_t k = 0; k < image9.channels; k++){
                image9(i,j,k)=image(image.width-1-i,image.height-1-j,k);            
            }
        }
    }    
    image=image9;
    }  
int main()
{
    Image image("arrow.jpg");
    Rotate_180(image);
    image.saveImage("output3.jpg");
}    
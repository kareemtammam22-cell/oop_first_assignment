#include<iostream>
#include"image_class.h"
using namespace std;
void old_tv_effect(Image& image){
    for (size_t i = 0; i <image.width; i++){
        for (size_t j = 0; j < image.height; j++){

            if(j%2==0){
            image(i,j,0)=.6*image(i,j,0);
            image(i,j,1)=.6*image(i,j,1);
            image(i,j,2)=.6*image(i,j,2);                        
            }
        }    
    }
}
int main()
{
    Image image("arrow.jpg");
    old_tv_effect(image);
    image.saveImage("output.jpg");
}    
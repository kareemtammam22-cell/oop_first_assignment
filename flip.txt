//filter2:flip image
#include <iostream>
#include <string>
#include "Image_Class.h"
      
using namespace std;
//flip h
void fliphorizontal(Image & img){
    Image temp(img.width, img.height);
    for(int i=0; i<img.width; i++){
        for(int j=0; j<img.height; j++){
            for(int k=0; k<3; k++){
                temp(i,j,k) = img(img.width-1-i, j, k);
            }
        }
    }
    img = temp;
}

//flip v
void flipvertical(Image & img){
    Image temp(img.width, img.height);
    for(int i=0; i<img.width; i++){
        for(int j=0; j<img.height; j++){
            for(int k=0; k<3; k++){
                temp(i,j,k) = img(i, img.height-1-j, k);
            }
        }
    }
    img = temp;
}

int main(){
    string filename;
    cout<<"enter imagefile name: ";
    cin>>filename;

    Image img1(filename);
    fliphorizontal(img1);
    img1.saveImage("flipped_horizontal.jpg");
    Image img2(filename);
    flipvertical(img2);
    img2.saveImage("flipped_vertical.jpg"); 
    cout<<"image saved:flipped_horizontal.jpg and flipped_vertical.jpg\n";
    return 0;
}

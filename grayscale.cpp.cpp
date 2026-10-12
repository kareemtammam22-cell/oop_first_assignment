#include <iostream>
#include <string>
#include "Image_Class.h"

using namespace std;
//filter1:grayscale conversion
void converttograyscale(Image & img){
    for (int i=0;i < img.width;++i){
      for (int j=0; j<img.height; ++j){
        int avg =(img(i,j,0)+img(i,j,1)+img(i,j,2))/3;
        img(i,j,0)=avg;
        img(i,j,1)=avg;
        img(i,j,2)=avg;
       }
    }
}
int main(){
    string filename;
    cout<< "enter image name: ";
    cin>>filename;
Image img(filename);
converttograyscale(img);
img.saveImage("output.jpg");
cout<<"Image saved successfully as output.jpg\n";
return 0;

}


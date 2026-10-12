#include <iostream>
#include <algorithm>
#include "Image_Class.h"
using namespace std;

int main(){
cout<<"Write your image name"<<"\n";
string img_name;
cin>>img_name;
Image image(img_name);
cout<<"The Image size is "<<image.height<<" X "<<image.width<<"\n";
int h,w;
cout<<"Please Enter the Hight"<<"\n";
cin >>h;
cout<<"Please Enter the Width"<<"\n";
cin >>w;
if (h>image.height || w>image.width|| h <= 0 || w <= 0){
  cout <<"wrong size";
} 
else{
Image res(w,h);
        for (int i=0;i<w;i++)
          for (int j=0;j<h;j++)
             for (int k=0;k<3 ;k++)
                res(i, j, k) =image(i,j,k);
        image=res;
        image.saveImage("Cropped"+img_name);
}
    
}
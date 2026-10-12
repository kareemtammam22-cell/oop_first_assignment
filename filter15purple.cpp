#include <iostream>
#include <algorithm>
#include "image_class.h"
using namespace std;
int main()
{
  cout<<"Please Enter your image name"<<"\n";
  string img_name;
  cin>>img_name;
  Image image(img_name);
  for (int w=0 ;w < image.width ; w++){
    for(int h=0 ; h < image.height ; h++){
        image(w,h,0)=min(255,(int)(image(w,h,0)*1.5));
        image(w,h,1)=(image(w,h,1)*0.5);
        image(w,h,2)=min(255,(int)(image(w,h,2)*1.5));
    }
  }
  image.saveImage("purple_"+img_name);
}
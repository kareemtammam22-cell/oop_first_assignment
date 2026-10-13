#include<iostream>
#include"image_class.h"
/*
  OOP Assignment phase_1
  Section:((Groub B))-Wednesday-(lab8)-(s39,s40)
 ------------------------------------
  1.Seif hassan 
    ID:20250314
    Filter 1 (Grayscale)
    Filter 5 (Flip Image)
    Filter 9 (Merge image)
    Filter 13 (Natural sunlight/wano)    
 -------------------------------------    
  2.Omar sayed mohamed sayed
    ID:20251265
    Filter 2 (Black & White)
    Filter 6 (Rotate Image)
    Filter 10 (Detect_Image_Edges)
    Filter 14  (old_tv_filter)      
 -------------------------------------    
  3.Kareem Ali Ahmed Tammam 
    ID:20251292
    Filter 3 (Invert Image)
    Filter 7 (Darken / Lighten)
    Filter 11 (crop image)   
    Filter 15(Purple wano)     
 -------------------------------------    
  4.Youssef salama saad
    ID:20251495
    Filter 4 (Add Frame)
    Filter 8 (Resize Image)
    Filter 12(Blur image)  
    Filter 16(Infared photography)  
  ------------------------------------
  LINKS :-
  1. Repo Link :-
    https://github.com/kareemtammam22-cell/oop_first_assignment
  2. Document Link :-
    https://docs.google.com/document/d/1yu7QnNshQ2BBxHu9fQFTO11VFZPli34F/edit?usp=drivesdk&ouid=117183389754258683203&rtpof=true&sd=true
  ------------------------------------
  أقسم بالله العظيم أن هذا الكود من عمل الفريق 100% بلا نسخ أي مصدر أو تخليق بذكاء اصطناعي
  1- 	Seif Hassan Ramadan Mohamed
  2-  Omar Sayed Mohamed Sayed
  3-  Kareem Ali Ahmed Tammam
  4-  Yousef Salama Saad Mabrouk
*/

using namespace std;
void Infraed_photographary(Image& image){
    for (int x = 0; x < image.width; ++x) {
        for (int y = 0; y < image.height; ++y) {
            int gray = (image(x, y, 0) + image(x, y, 1) + image(x, y, 2)) / 3;

            int v = gray * 14 / 10 - 20;
            if (v < 0) v = 0;
            if (v > 255) v = 255;

            image(x, y, 0) = 255;
            image(x, y, 1) = v;
            image(x, y, 2) = v;
        }
    }
}
void Blur_image(Image& image){
    Image original = image;

    int level;
    cout << "Enter blur level (1 to 10): ";
    cin >> level;

    for (int x = 0; x < image.width; x++) {
        for (int y = 0; y < image.height; y++) {
            for (int c = 0; c < 3; c++) {
                int sum = 0, count = 0;

                for (int i = -level; i <= level; i++) {
                    for (int j = -level; j <= level; j++) {
                        int nx = x + i;
                        int ny = y + j;
                        if (nx >= 0 && nx < image.width && ny >= 0 && ny < image.height) {
                            sum += original(nx, ny, c);
                            count++;
                        }
                    }
                }

                image(x, y, c) = sum / count;
            }
        }
    }
}
void crop_image(Image& image){
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
}
    
}
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
void purple_image(Image& image){       
  for (int w=0 ;w < image.width ; w++){
    for(int h=0 ; h < image.height ; h++){
        image(w,h,0)=min(255,(int)(image(w,h,0)*1.5));
        image(w,h,1)=(image(w,h,1)*0.5);
        image(w,h,2)=min(255,(int)(image(w,h,2)*1.5));
    }
  }
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
void invert_fillter(Image &image){
    Image result(image.width, image.height);
    for (int y = 0; y < image.height; y++){
        for (int x = 0; x < image.width; x++){
            for (int z = 0; z < 3; z++){
                int pix=255 - image.getPixel(x,y,z);
                result.setPixel(x, y, z,pix);
            }
        }
    }
    image=result;    
}
void mergeFilter(Image &image) { 
    string filename2;
    cout << "Enter the second image name: ";
    cin >> filename2;
    Image image2(filename2);

    // intersection area
    int w = min(image.width, image2.width);
    int h = min(image.height, image2.height);

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < 3; k++) {
                image(i, j, k) = (image(i, j, k) + image2(i, j, k)) / 2;
            }
        }
    }
}
void Lighten_filter(Image &image){
    for (int y=0;y < image.height;y++){
        for (int x=0;x< image.width;x++ ){
            for(int z=0;z<3;z++){
                int oldpix=image.getPixel(x,y,z);
                int newpix=oldpix*2;
                if(newpix>255)
                {
                    newpix=255;
                }
                image.setPixel(x,y,z,newpix);
            }
        }
    }  
}
void sunlightFilter(Image &image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int r = image(i, j, 0) * 1.6;
            int g = image(i, j, 1) * 1.4;
            int b = image(i, j, 2) * 0.8;

            image(i, j, 0) = min(255, r);
            image(i, j, 1) = min(255, g);
            image(i, j, 2) = min(255, b);
        }
    }
}

void darken_filter(Image &image){
    for (int y=0;y < image.height;y++){
        for (int x=0;x< image.width;x++ ){
            for(int z=0;z<3;z++)
            {
                int pix=image.getPixel(x,y,z)/2;
                image.setPixel(x,y,z,pix);
            }
        }
    }
}
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
void frameFilter(Image& image)
{
    int choice;
    int border;

    cout << "Choose frame type:\n";
    cout << "1. Simple Frame\n";
    cout << "2. Fancy Frame\n";
    cin >> choice;

    cout << "Enter frame pixles: ";
    cin >> border;

    int red, green, blue;

    cout << "Enter frame color (R G B): ";
    cin >> red >> green >> blue;

    for (int _y = 0; _y < image.height; _y++)
    {
        for (int _x = 0; _x < image.width; _x++)
        {
            if (_x < border ||
                _x >= image.width - border ||
                _y < border ||
                _y >= image.height - border)
            {
                image.setPixel(_x, _y, 0, red);
                image.setPixel(_x, _y, 1, green);
                image.setPixel(_x, _y, 2, blue);
            }
        }
    }

    if (choice == 2)
    {
        int innerBorder = border / 3;

        for (int _y = innerBorder; _y < image.height - innerBorder; _y++)
        {
            for (int _x = innerBorder; _x < image.width - innerBorder; _x++)
            {
                if (_x < innerBorder + 5 ||
                    _x >= image.width - innerBorder - 5 ||
                    _y < innerBorder + 5 ||
                    _y >= image.height - innerBorder - 5)
                {
                    image.setPixel(_x, _y, 0, 255);
                    image.setPixel(_x, _y, 1, 255);
                    image.setPixel(_x, _y, 2, 255);
                }
            }
        }
    }
}
void resizeImage(Image& image)
{
    int _newWidth=200, _newHeight=200;

    cout << "Enter new width: ";
    cin >> _newWidth;

    cout << "Enter new height: ";
    cin >> _newHeight;

    if (_newWidth <= 0 || _newHeight <= 0){
        cout << "Invalid dimensions!\n";
        return;
    }

    Image resized(_newWidth, _newHeight);

    for (int _y = 0; _y < _newHeight; _y++){
        for (int _x = 0; _x < _newWidth; _x++){
            int _oldX = _x * image.width / _newWidth;
            int _oldY = _y * image.height / _newHeight;
            for (int _channel = 0; _channel < 3; _channel++){
                resized(_x, _y, _channel) =image(_oldX, _oldY, _channel);
            }
        }
    }

    image = resized;
}
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
int main(){
    string filename;
    cout<<"enter imagefile name: ";
    cin>>filename;  
    Image image(filename);

int choice;
    do {
        cout << "\n******************************************\n";
        cout << "         Image Processing Menu           \n";
        cout << "*****************************************\n";
        cout << "1. Grayscale Conversion    \n";
        cout << "2. Black and Whit          \n";
        cout << "3. Invert Image Colors     \n";
        cout << "4. Add Frame               \n";
        cout << "5. Flip Image              \n";
        cout << "6. Rotate Image            \n";
        cout << "7. Darken / Lighten Image  \n";
        cout << "8. Resize Image            \n";
        cout << "9. Merge image            \n";        
        cout << "10.Detect_Image_Edges            \n";
        cout << "11.crop image             \n";     
        cout << "12.Blur image             \n"; 
        cout << "13.Natural sunlight/wano             \n";                    
        cout << "14.old_tv_filter             \n";   
        cout << "15.Purple wano             \n";  
        cout << "16.Infared photography             \n";                               
        cout << "17.Save and Exit           \n";
        cout << "0. Exit without Saving     \n";
        cout << "=========================================\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                converttograyscale(image);
                cout << "Grayscale filter applied!\n";
                break;
            case 2:
                black_and_white_fillter(image);
                cout << "Black & White filter applied!\n";
                break;
            case 3:
                invert_fillter(image);
                cout << "Invert filter applied!\n";
                break;
            case 4:
                frameFilter(image);
                cout << "Frame filter applied!\n";
                break;
            case 5: {
                int flipChoice;
                cout << "1. Horizontal Flip\n2. Vertical Flip\nChoice: ";
                cin >> flipChoice;
                if (flipChoice == 1) fliphorizontal(image);
                else if (flipChoice == 2) flipvertical(image);
                cout << "Flip filter applied!\n";
                break;
            }
            case 6: {
                int rotateChoice;
                cout << "Choose angle: 1. 90    2. 180     3. 270 Deg\nChoice: ";
                cin >> rotateChoice;
                if (rotateChoice == 1) Rotate_90(image);
                else if (rotateChoice == 2) Rotate_180(image);
                else if (rotateChoice == 3) Rotate_270(image);
                cout << "Rotation applied!\n";
                break;
            }
            case 7: {
                int dark_light_lChoice;
                cout << "1. Lighten\n2. Darken\nChoice: ";
                cin >> dark_light_lChoice;
                if (dark_light_lChoice == 1) Lighten_filter(image);
                else if (dark_light_lChoice == 2) darken_filter(image);
                cout << "Lighting filter applied!\n";
                break;
            }
            case 8:
                resizeImage(image);
                cout << "Resize applied!\n";
                break;
            case 9:
                mergeFilter(image);
                cout << "Merge applied!\n";
                break;                
            case 10:
                Detect_Image_Edges(image);
                cout << "Detect edges filter applied!\n";
                break; 
            case 11:
                crop_image(image);
                cout << "Crop applied!\n";
                break;
            case 12:
                Blur_image(image);
                cout << "Blur applied!\n";
                break;
            case 13:
                sunlightFilter(image);
                cout << "wano applied!\n";
                break;                                                
            case 14:
                old_tv_effect(image);
                cout << "old tv filter applied!\n";
                break;
            case 15:
                purple_image(image);
                cout << "purple applied!\n";
                break;         
            case 16:
                Infraed_photographary(image);
                cout << "Infraed_photographary applied!\n";
                break;                                                        
            case 17: {
                string saveName;
                cout << "Enter file name to save (like output.jpg,.bmp,.png): ";
                cin >> saveName;
                image.saveImage(saveName);
                cout << "Image saved successfully\n";
                break;
            }
            case 0:
                cout << "Exiting without saving changes\n";
                break;
            default:
                cout << "Invalid choice Try again\n";
        }
    } while (choice != 0 && choice != 17);    

    return 0;
}

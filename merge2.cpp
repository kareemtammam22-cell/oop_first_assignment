#include <iostream>
#include <algorithm>
#include "Image_Class.h"
using namespace std;

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
int main() {
    string filename;
    cout << "Enter the first image name: ";
    cin >> filename;
    Image image(filename);

    mergeFilter(image);

    string outName;
    cout << "Enter output image name (with extension): ";
    cin >> outName;
    image.saveImage(outName);

    cout << "Done!" << endl;
    return 0;
}
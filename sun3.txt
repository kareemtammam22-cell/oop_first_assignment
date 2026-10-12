#include <iostream>
#include <algorithm>
#include "Image_Class.h"
using namespace std;

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

int main() {
    string filename;
    cout << "Enter the image name: ";
    cin >> filename;
    Image image(filename);

    sunlightFilter(image);

    string outName;
    cout << "Enter output image name (with extension): ";
    cin >> outName;
    image.saveImage(outName);

    cout << "Done!" << endl;
    return 0;
}
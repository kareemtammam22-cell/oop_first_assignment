#include <iostream>
#include "Image_Class.h"

using namespace std;

int main() {
    string filename;
    cout << "Enter image name: ";
    cin >> filename;
    Image image(filename);

    for (int _x = 0; _x < image.width; ++_x) {
        for (int _y = 0; _y < image.height; ++_y) {
            int gray = (image(_x, _y, 0) + image(_x, _y, 1) + image(_x, _y, 2)) / 3;

            int v = gray * 14 / 10 - 20;
            if (v < 0) v = 0;
            if (v > 255) v = 255;

            image(_x, _y, 0) = 255;
            image(_x, _y, 1) = v;
            image(_x, _y, 2) = v;
        }
    }

    cout << "Enter output name: ";
    cin >> filename;
    image.saveImage(filename);
}

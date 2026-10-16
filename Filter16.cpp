#include <iostream>
#include "Image_Class.h"

using namespace std;

int main() {
    string filename;
    cout << "Enter image name: ";
    cin >> filename;
    Image image(filename);

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

    cout << "Enter output name: ";
    cin >> filename;
    image.saveImage(filename);
}

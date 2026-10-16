#include <iostream>
using namespace std;
#include "Image_Class.h"

int main() {
    string filename;
    cout << "Enter image name: ";
    cin >> filename;

    Image image(filename);
    Image original = image;

    int level;
    cout << "Enter blur level (1 to 10): ";
    cin >> level;

    for (int _x = 0; _x < image.width; _x++) {
        for (int _y = 0; _y < image.height; _y++) {
            for (int _c = 0; _c < 3; _c++) {
                int sum = 0, count = 0;

                for (int i = -level; i <= level; i++) {
                    for (int j = -level; j <= level; j++) {
                        int nx = _x + i;
                        int ny = _y + j;
                        if (nx >= 0 && nx < image.width && ny >= 0 && ny < image.height) {
                            sum += original(nx, ny, _c);
                            count++;
                        }
                    }
                }

                image(_x, _y, _c) = sum / count;
            }
        }
    }

    cout << "Enter name to save (.jpg, .bmp, .png, .tga): ";
    cin >> filename;
    image.saveImage(filename);

    return 0;
}

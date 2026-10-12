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

    cout << "Enter name to save (.jpg, .bmp, .png, .tga): ";
    cin >> filename;
    image.saveImage(filename);

    return 0;
}
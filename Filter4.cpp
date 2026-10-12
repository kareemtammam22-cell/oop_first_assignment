#include <iostream>
#include "Image_Class.h"

using namespace std;

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

int main()
{
    Image image("fruit.bmp");
    frameFilter(image);

    image.saveImage("output.jpg");

    return 0;
}
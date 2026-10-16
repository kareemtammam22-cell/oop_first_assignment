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

    for (int y = 0; y < image.height; y++)
    {
        for (int x = 0; x < image.width; x++)
        {
            if (x < border ||
                x >= image.width - border ||
                y < border ||
                y >= image.height - border)
            {
                image.setPixel(x, y, 0, red);
                image.setPixel(x, y, 1, green);
                image.setPixel(x, y, 2, blue);
            }
        }
    }

    if (choice == 2)
    {
        int innerBorder = border / 3;

        for (int y = innerBorder; y < image.height - innerBorder; y++)
        {
            for (int x = innerBorder; x < image.width - innerBorder; x++)
            {
                if (x < innerBorder + 5 ||
                    x >= image.width - innerBorder - 5 ||
                    y < innerBorder + 5 ||
                    y >= image.height - innerBorder - 5)
                {
                    image.setPixel(x, y, 0, 255);
                    image.setPixel(x, y, 1, 255);
                    image.setPixel(x, y, 2, 255);
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

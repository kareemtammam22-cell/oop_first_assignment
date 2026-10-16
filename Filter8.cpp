#include <iostream>
#include "Image_Class.h"

using namespace std;

void resizeImage(Image& image)
{
    int newWidth, newHeight;

    cout << "Enter new width: ";
    cin >> newWidth;

    cout << "Enter new height: ";
    cin >> newHeight;

    if (newWidth <= 0 || newHeight <= 0)
    {
        cout << "Invalid dimensions!\n";
        return;
    }

    Image resized(newWidth, newHeight);

    for (int y = 0; y < newHeight; y++)
    {
        for (int x = 0; x < newWidth; x++)
        {
            int oldX = x * image.width / newWidth;
            int oldY = y * image.height / newHeight;

            for (int channel = 0; channel < 3; channel++)
            {
                resized(x, y, channel) =
                    image(oldX, oldY, channel);
            }
        }
    }

    image = resized;
}

int main()
{
    string filename;

    cout << "Enter image name: ";
    cin >> filename;

    Image image(filename);

    resizeImage(image);

    cout << "Enter output image name: ";
    cin >> filename;

    image.saveImage(filename);

    cout << "Image resized successfully!\n";

    return 0;
}

#include <iostream>
#include "Image_Class.h"

using namespace std;

//***/ /***//*** //***//* **//* **

void resizeImage(Image& image)
{
    int _newWidth, _newHeight;

    cout << "Enter new width: ";
    cin >> _newWidth;

    cout << "Enter new height: ";
    cin >> _newHeight;

    if (_newWidth <= 0 || _newHeight <= 0)
    {
        cout << "Invalid dimensions!\n";
        return;
    }

    Image resized(_newWidth, _newHeight);

    for (int _y = 0; _y < _newHeight; _y++)
    {
        for (int _x = 0; _x < _newWidth; _x++)
        {
            int _oldX = _x * image.width / _newWidth;
            int _oldY = _y * image.height / _newHeight;

            for (int _channel = 0; _channel < 3; _channel++)
            {
                resized(_x, _y, _channel) =
                    image(_oldX, _oldY, _channel);
            }
        }
    }

    image = resized;
}

//***/ /***//*** //***//* **//* **

int main()
{
    string _filename;

    cout << "Enter image name: ";
    cin >> _filename;

    Image image(_filename);

    resizeImage(image);

    cout << "Enter output image name: ";
    cin >> _filename;

    image.saveImage(_filename);

    cout << "Image resized successfully!\n";

    return 0;
}
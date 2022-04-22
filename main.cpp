#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

int loadImage ();
void saveImage ();
void doSomethingForImage ();

int main()
{
    if(loadImage() == 0)
    {
        doSomethingForImage ();
        saveImage();

    }
}

int loadImage ()
{
    char imageFileName[100];

    cout<<"Ahlan ya user ya habibi :) \n"
          "Please enter file name of the image to process"<<endl;
    cin >> imageFileName;

    strcat (imageFileName, ".bmp");
    return readGSBMP(imageFileName, image);
}

void saveImage ()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

void doSomethingForImage ()
{
    //main filters
}

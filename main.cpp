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
    char Numfilter;
    cout<<"Please select a filter to apply or 0 to exit:\n"
          "1- Black & White Filter\n"
          "2- Invert Filter\n"
          "3- Merge Filter \n"
          "4- Flip Image\n"
          "5- Rotate Image \n"
          "6- Darken and Lighten Image\n"
          "7- Detect Image Edges \n"
          "8- Enlarge Image\n"
          "9- Shrink Image\n"
          "a- Mirror 1/2 Image\n"
          "b- Shuffle Image\n"
          "c- Blur Image\n"
          "s- Save the image to a file\n"
          "0- Exit\n";

    cin>>Numfilter;
    switch (Numfilter)
    {
        case '1':
            // Black and White filter call
            break;

        case '2':
            // Invert filter call

            break;

        case '3':
            // Invert filter call

            break;

        case '4':
            // Merge filter call
            break;

        case '5':
            // Rotate filter call
            break;

        case '6':
            // Darken and Lighten filter call
            break;

        case '7':
            // Detect Edges filter call
            break;

        case '8':
            // Enlarge filter call
            break;

        case 'a':
            // Shrink filter call
            break;

        case 'b':

            // Shuffle filter call
            break;

        case 'c':
            // Blur filter call
            break;

        case 's':
            // Save the image to a file
            saveImage();

        case '0':
            // close program
            cout<<"shokran ya user ya hapipi :)" <<endl;



    }

}

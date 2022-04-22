// FCI � Programming 1 � 2022 - Assignment 3
// Program Name: Gray-Scale-Image-Processor
// Last Modification Date: 22/04/2022
// Author1 and ID and Group: Ahmed Hesham  20211008  s11
// Author2 and ID and Group: Mahmoud Mohamed  20210375 s11
// Author3 and ID and Group: Aiman Motea  20210783 s11
// Teaching Assistant: Eng Afaf Abdulmonem



#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
char Numfilter;

int loadImage ();
void saveImage ();
void doSomethingForImage ();
void Merge_Images  ();
void Darken_and_Lighten_Image ();
void Shrink_Image ();
void Blur_Image ();

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

void doSomethingForImage ()
{
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
            // Merge filter call
            Merge_Images  ();
            break;

        case '4':
            // Flip filter call
            break;

        case '5':
            // Rotate filter call
            break;

        case '6':
            // Darken and Lighten filter call
            Darken_and_Lighten_Image  ();
            break;

        case '7':
            // Detect Edges filter call
            break;

        case '8':
            // Enlarge filter call
            break;

        case  '9':
            // Shrink filter call
            Shrink_Image  ();

        case 'a':
            // Miror filter call
            break;

        case 'b':

            // Shuffle filter call
            break;

        case 'c':
            // Blur filter call
            Blur_Image();
            break;

        case 's':
            // Save the image to a file
            saveImage();

        case '0':
            // close program
            cout<<"shokran ya user ya hapipi :)" <<endl;



    }

}


void saveImage ()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    switch(Numfilter)
    {
        case '9':
            writeGSBMP(imageFileName, image2);
            break;

        default:
            writeGSBMP(imageFileName, image);

    }
}



void Merge_Images()
{
    charimage_name2[100];
    cout << "Enter the source image 2 file name: ";
    cin >> image_name2;

    strcat (image_name2, ".bmp");
    if (readGSBMP(image_name2, image2) == 0)
    {
        for (int i = 0; i < SIZE; i++) 
        {
            for (int j = 0; j< SIZE; j++)
            {
                image[i][j]=((image[i][j]+image2[i][j])/2);
            }
        }
    }

}




void Darken_and_Lighten_Image ()
{
    char choose;
    cout<<"Choose: "<<endl<<"(L)ighter "<<endl<<"(d)arker"<<endl;
    cin>>choose;
    switch(choose.lower())
    {
        case 'l':
            for (int i = 0; i < SIZE; i++) 
            {
                for (int j = 0; j< SIZE; j++)
                {
                    if(image[i][j]*1.5<=255)
                    {
                        image[i][j]*=1.5;
                    }
                    else
                    {
                        image[i][j]=255;
                    }
            }
            break;

        case 'd':
            for (int i = 0; i < SIZE; i++) 
            {
                for (int j = 0; j< SIZE; j++)
                {
                    if(image[i][j]/1.5>=0)
                    {
                        image[i][j]/=1.5;
                    }
                    else
                    {
                        image[i][j]=0;
                    }
                }
            }

}



void Shrink_Image()
{
    int choose;
    cout<<"Enter shrinking rate: "<<endl<<"1-1/2"<<endl<<"2-1/3"<<endl<<"3-1/4"<<endl;
    cin>>choose;
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            blackimage[i][j]=255;
        }
    }

    for (int i = 0; i < SIZE; i++) 
    {
        for(int j=0;j<SIZE;j++)
        {
            image2[(i/(choose+1))][(j/(choose+1))]=image[i][j];
        }
    }

}


void Blur_Image()
{
    int avg = 0 ;
    for (int i = 0; i < SIZE; i++)
     {
        for (int j = 0; j< SIZE; j++)
        {
            avg = ((image[i+1][j]+image[i-1][j]+image[i][j+1]+image[i][j-1])/3);
            image[i][j]=avg;
        }
    }

}






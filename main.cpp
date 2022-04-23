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
void ShuffleImage();
void InvertImage();
void black_and_white();
void RotateImage();
void FlipImage();
void EnlargeImage();
void doSomethingForImage ();
void Merge_Images  ();
void Darken_and_Lighten_Image ();
void Shrink_Image ();
void Blur_Image ();
void detect_edges();
void Miror_filter();

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
			black_and_white();
            break;

        case '2':
            // Invert filter call
            InvertImage();
            break;

        case '3':
            // Merge filter call
            Merge_Images  ();
            break;

        case '4':
            // Flip filter call
			FlipImage();

            break;

        case '5':
            // Rotate filter call
            RotateImage();
            break;

        case '6':
            // Darken and Lighten filter call
            Darken_and_Lighten_Image  ();
            break;

        case '7':
            // Detect Edges filter call
			void detect_edges();
            break;

        case '8':
            // Enlarge filter call
            EnlargeImage();

            break;

        case  '9':
            // Shrink filter call
            Shrink_Image  ();

        case 'a':
            // Miror filter call
			Miror_filter();
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
        case '5':
        case '8':
        case '9':
        case 'b':
            writeGSBMP(imageFileName, image2);
            break;

        default:
            writeGSBMP(imageFileName, image);

    }
}



void Merge_Images()
{
    char image_name2[100];
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
    cout << "Choose: " << endl << "(L)ighter " << endl << "(d)arker" << endl;
    cin >> choose;
    switch (tolower(choose) )
    {
        case 'l':
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    if (image[i][j] * 1.5 <= 255)
                    {
                        image[i][j] *= 1.5;
                    }
                    else
                    {
                        image[i][j] = 255;
                    }
                }
            }
            break;

         case 'd':
             for (int i = 0; i < SIZE; i++)
             {
                 for (int j = 0; j < SIZE; j++)
                 {
                     if (image[i][j] / 1.5 >= 0)
                     {
                         image[i][j] /= 1.5;
                     }
                     else
                     {
                         image[i][j] = 0;
                     }
                 }
             }
            break;




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
            image2[i][j]=255;
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

void InvertImage()
{
    for (int i = 0; i <SIZE ; ++i)
    {
        for (int j = 0; j <SIZE; ++j)
        {
            image[i][j] -= 255;
        }
    }
}

void RotateImage()
{
    cout<<"Rotate (90), (180) , (270) or (360) degrees?"<<endl;
    int rotateAngle;
    cin>>rotateAngle;
    switch (rotateAngle)
    {
        case 90:
            for (int i = 0; i < SIZE; ++i)
            {
                for (int j = 0; j < SIZE; ++j)
                    image2[j][i] = image[255 - i][j];
            }
            break;

        case 180:
            for (int i = 0; i < SIZE; ++i)
            {
                for (int j = 0; j < SIZE; ++j)
                {
                    image2[i][j] = image[255 - i][255 - j];
                }
            }
            break;

        case 270:
            for (int i = 0; i < SIZE; ++i)
            {
                for (int j = 0; j < SIZE; ++j)
                    image2[j][i] = image[i][255 - j];
            }
     }
}
void EnlargeImage()
{
    int numQuarter,istart,jstart ,iend,jend;
    cout<<" Which quarter to enlarge 1, 2, 3 or 4?"<<endl;
    cin>>numQuarter;
    switch (numQuarter)
    {
        case 1:
            istart = 0;
            jstart = 0;
            iend = 128;
            jend = 128;
            break;

        case 3:
            istart = 128;
            jstart = 0;
            iend = 256;
            jend = 128;
            break;

        case 2:
            istart = 0;
            jstart = 128;
            iend = 128;
            jend = 256;
            break;


        case 4:
            istart = 128;
            jstart = 128;
            iend = 256;
            jend = 256;
            break;
    }
    for (int i = istart ,posi=0 ; i <iend ; ++i,posi+=2)
    {
        for (int j = jstart, posj=0 ; j <jend; ++j,posj+=2)
        {
            image2[posi][posj] = image[i][j] ;
            image2[posi][posj+1] = image[i][j] ;
            image2[posi+1][posj] = image[i][j] ;
            image2[posi+1][posj+1] = image[i][j] ;
        }
    }

}



void ShuffleImage()
{
    char suffleWay[4];
    int istart,jstart ,iend,jend;
    cout<<" New order of quarters ?"<<endl;
    cin>>suffleWay;
    for (int n = 0; n < 4 ; ++n)
    {
        int iquartar ;
        int jquartar ;
        switch (n+1)
        {
            case 1:
                iquartar = 0;
                jquartar = 0;
                break;

            case 2:
                iquartar = 0;
                jquartar = 128;
                break;

            case 3:
                iquartar = 128;
                jquartar = 0;
                break;

            case 4:
                iquartar = 128;
                jquartar = 128;
                break;

        }
        switch (suffleWay[n])
        {
            case '1':
                istart = 0;
                jstart = 0;
                iend = 128;
                jend = 128;
                break;

            case '3':
                istart = 128;
                jstart = 0;
                iend = 256;
                jend = 128;
                break;

            case '2':
                istart = 0;
                jstart = 128;
                iend = 128;
                jend = 256;
                break;


            case '4':
                istart = 128;
                jstart = 128;
                iend = 256;
                jend = 256;

                break;


        }
        for (int i = istart ,posi = iquartar ; i <iend ; ++i,posi++)
        {
            for (int j = jstart, posj = jquartar ; j <jend; ++j,posj++)
            {
                image2[posi][posj] = image[i][j] ;
            }
        }




    }
}
void black_and_white(){
for (int i = 0; i < SIZE; i++) {
	for (int j = 0; j < SIZE; j++) {
		if (image[i][j] > 127)
			image[i][j] = 255;
		else
			image[i][j] = 0;
	}
} }
void FlipImage() {
	int n;
	cout << "1 for down flip" << endl << "2 for side flip";
	cin >> n;
	switch (n)
	{
	case 1: {
		unsigned char image2[SIZE][SIZE];
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				image2[i][j] = image[255 - i][j];
			}
		}
		break;

	}
	case 2: {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				image2[i][j] = image[i][255 - j];
			}
		}
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				image[i][j] = image2[i][j];
			}
		}
	}
	}
	void detect_edges() {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				image2[i][j] = 255;
				if (image[i][j] > 128 && image[i + 1][j] < 128)
					image2[i][j] = 0;
				if (image[i][j] < 128 && image[i + 1][j]>128)
					image2[i][j] = 0;
				if (image[i][j] > 128 && image[i][j + 1] < 128)
					image2[i][j] = 0;
				if (image[i][j] < 128 && image[i][j + 1]>128)
					image2[i][j] = 0;
			}
		}
	}
	void Miror_filter() {
		int n;
		cout << "1-Left 1/2 " << endl << "2-Right 1/2 " << endl << "3-Upper 1/2 " << endl << "4-Lower 1/2" << endl << "choose ya hapipyyy " << endl;
		cin >> n;
		switch (n)
		{	
		case 1:
			for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				image[i][j] = image[255 - i][j];

			}
		}
			break;
		case 2:
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					image[i][j] = image[i][255 - j];

				}
			}
			break;
		}
	case 3:
		for (int i = SIZE; i >= 0; i--) {
			for (int j = SIZE; j >= 0; j--) {
				image[i][j] = image[255 - i][j];

			}
		}
		break;
	case 4:
		for (int i = SIZE; i >= 0; i--) {
			for (int j = SIZE; j >= 0; j--) {
				image[i][j] = image[i][255 - j];

			}
		}
	
	
	
	
	}



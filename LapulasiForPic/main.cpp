#include <iostream>
#include "Lapulasi.h"

using namespace std;

int main()
{
    IplImage* img = cvLoadImage("test.jpg");
    cvNamedWindow( "test", 0 );
    cvShowImage("test", img);
    cvWaitKey(0);
    cvReleaseImage( &img );
    cvDestroyWindow( "test" );
    return 0;
}

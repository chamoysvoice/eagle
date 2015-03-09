#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv){
    if (argc != 2){
        std::cerr << "usage ./main <IMAGE_PATH>";
        return -1;
    }

    Mat image;
    image = imread( "testing/iphone.jpg", 1 );

    if ( !image.data )
    {
        std::cerr << "No image data \n";
        return -1;
    }


}
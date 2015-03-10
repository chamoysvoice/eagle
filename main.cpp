#include<iostream>
#include<opencv2/opencv.hpp>
#include "includes/Filters.cpp"

using namespace cv;

/*
 * This is the main template where you can test
 * the functions within the library and ****
 * remember namespace for eagle is EGL::x
 */


int main(int argc, char** argv){
    if (argc != 2){
        std::cerr << "usage ./main <IMAGE_PATH>";
        return -1;
    }

    Mat image;
    image = imread( argv[1], 1 );

    if ( !image.data )
    {
        std::cerr << "No image data \n";
        return -1;
    }

    cv::imshow("Output", EGL::to_binary(image, (float)0.5));


    cv::waitKey();
    return 0;
}

#include<iostream>
#include<opencv2/opencv.hpp>
#include "includes/Filters.cpp"

using namespace cv;

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

    cv::imshow("Enseñando imagen", EGL::to_grayscale(image));


    cv::waitKey();
    return 0;
}

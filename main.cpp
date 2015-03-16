#include<iostream>
#include<opencv2/opencv.hpp>
#include "includes/eagle.hpp"

using namespace cv;

/*
 * This is the main template where you can test
 * the functions within the library and ****
 * remember namespace for eagle is EGL::x
 */


int main(int argc, char** argv){
    if (argc < 2){
        std::cerr << "usage ./main <IMAGE_PATH> [<OUTPUT_PATH>]";
        return -1;
    }

    Mat image, grey_image;
    image = imread( argv[1], 1 );

    if ( !image.data )
    {
        std::cerr << "No image data \n";
        return -1;
    }

    cv::cvtColor(image, grey_image, CV_BGR2GRAY);


    Mat newImage = egl::histogram(grey_image);

    imshow("Original image", grey_image);
    imshow("Output", newImage);

    if(argc == 3){
    	imwrite(argv[2], newImage);
    }


    cv::waitKey();
    return 0;
}

#include<iostream>
#include "includes/eagle.hpp"

using namespace cv;
using namespace std;
/*
 * This is the main template where you can test
 * the functions within the library and ****
 * remember namespace for eagle is x
 */


int main(int argc, char** argv){
    if (argc < 2){
        std::cerr << "usage ./main <IMAGE_PATH> [<OUTPUT_PATH>]";
        return -1;
    }

    Mat image, grey_image, newImage;
    image = imread( argv[1], 1 );

    if ( !image.data )
    {
        std::cerr << "No image data \n";
        return -1;
    }

    unsigned char **alpha;

    //imshow("Original image", image);
    gaussian_profile(image);
    imshow("Mean Filter Image", image);

    newImage = cv::Mat(image);

    if(argc == 3){
    	imwrite(argv[2], newImage);
    }


    waitKey();
    return 0;
}

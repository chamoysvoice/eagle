#ifndef FILTERS_HEADER
#define FILTERS_HEADER

#include<opencv2/opencv.hpp>

namespace EGL{

cv::Mat to_grayscale(cv::Mat image);
cv::Mat to_binary(cv::Mat image, float threshold);
}

#endif

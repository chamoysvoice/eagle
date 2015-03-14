#ifndef FILTERS_HEADER
#define FILTERS_HEADER

#include<opencv2/opencv.hpp>

namespace egl{
	cv::Mat to_grayscale(cv::Mat image);
	cv::Mat to_binary(cv::Mat image, float threshold);
	cv::Mat add_to_pixels(cv::Mat image, int quantity);
	cv::Mat cry(cv::Mat image);
}

#endif

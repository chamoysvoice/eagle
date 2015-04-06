#ifndef UTILS_HEADER

#include "utils.hpp"
#endif

#ifndef FILTERS_HEADER
#define FILTERS_HEADER
#include "filters.cpp"


int **getNeighbors(cv::Mat &src, int x, int y);
cv::Mat to_grayscale(cv::Mat image);
cv::Mat to_binary(cv::Mat image, float threshold);
cv::Mat add_to_pixels(cv::Mat image, int quantity);
void mean_filter(cv::Mat &src);
void gaussian_profile(cv::Mat &src);
#endif

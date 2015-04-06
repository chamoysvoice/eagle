#ifndef UTILS_HEADER
#define UTILS_HEADER

#include "utils.cpp"

cv::Mat bw_histogram(cv::Mat src, int buckets);
cv::Mat rgb_histogram(cv::Mat src, int buckets);
cv::Mat histogram(cv::Mat src, int buckets);
cv::Mat cry(cv::Mat image);



#endif

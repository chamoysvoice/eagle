#ifndef UTILS_HEADER
#define UTILS_HEADER

namespace egl{
	cv::Mat histogram(cv::Mat src, int buckets);
	cv::Mat bw_histogram(cv::Mat src, int buckets);
	cv::Mat rgb_histogram(cv::Mat src, int buckets);
}

#endif

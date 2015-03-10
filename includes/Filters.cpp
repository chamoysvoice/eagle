#include "Filters.hpp"
#include <climits>

cv::Mat EGL::to_grayscale(cv::Mat image){
	//if image already in grayscale dont process
	if(image.channels()==1){
		return image;
	}



	cv::Vec3b colors;
	unsigned int gray_tone;
	unsigned char channels = image.channels();
	cv::Mat new_image;
	new_image.create(image.rows,image.cols, CV_8UC3);


	for (int i = 0; i < image.rows - 1; ++i) {
		for (int j = 0; j < image.cols - 1; ++j) {
			gray_tone = 0;
			 colors = image.at<cv::Vec3b>(i,j);
			 for (int k = 0; k < channels; ++k) {
       			gray_tone += colors[k];
			}
			 gray_tone /= channels;
			 new_image.at<cv::Vec3b>(i,j) = cv::Vec3b(gray_tone,gray_tone,gray_tone);
		}
	}

	return new_image;
}

cv::Mat EGL::to_binary(cv::Mat image, float threshold){
	/*
	 * The intention of this functions it to transform any image into
	 * a binary simulated format, that way is easier to process
	 * in further algorithms
	 */

	if(threshold < 0) threshold = 0;
	if(threshold > 1) threshold = 1;

	cv::Vec3b colors;
		unsigned int gray_tone;
		unsigned char channels = image.channels();
		cv::Mat new_image;
		new_image.create(image.rows,image.cols, CV_8UC3);
		unsigned char binary;

		for (int i = 0; i < image.rows - 1; ++i) {
			for (int j = 0; j < image.cols - 1; ++j) {
				gray_tone = 0;
				 colors = image.at<cv::Vec3b>(i,j);
				 for (int k = 0; k < channels; ++k) {
	       			gray_tone += colors[k];
				}
				 gray_tone /= channels;
				 binary = (gray_tone < UCHAR_MAX * threshold)? 0 : UCHAR_MAX;

				 new_image.at<cv::Vec3b>(i,j) = cv::Vec3b(binary ,binary ,binary);
			}
		}

		return new_image;
}


#include "Filters.hpp"
#include <climits>
#include <iostream>
#define RED_CHANNEL 0
#define GREEN_CHANNEL 1
#define BLUE_CHANNEL 2
#define COLOR_UPLIMIT 255
#define COLOR_DOWNLIMIT 0

cv::Mat egl::to_grayscale(cv::Mat image){
	//if image already in grayscale dont process it
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

cv::Mat egl::to_binary(cv::Mat image, float threshold){
	/*
	 * The intention of this functions it to transform any image into
	 * a simulated binary format, that way is easier to process
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
/* The intensity is a value from -255 to 255, where 255 is add total white
 * and -255 is make black */
cv::Mat egl::add_to_pixels(cv::Mat image, int quantity){
	if (quantity < -255 || 255 < quantity){
		std::cerr << "egl::add_to_pixels second parameter must be between -254 and 255";
		return image;
	}
	cv::Vec3b colors;
	cv::Mat new_image;
	new_image.create(image.rows,image.cols, CV_8UC3);
	int rchannel, gchannel, bchannel;
	for (int i = 0; i < image.rows - 1; ++i) {
		for (int j = 0; j < image.cols - 1; ++j) {
			 colors = image.at<cv::Vec3b>(i,j);
			 rchannel = colors[RED_CHANNEL] + quantity;
			 gchannel = colors[GREEN_CHANNEL] + quantity;
			 bchannel = colors[BLUE_CHANNEL] + quantity;
			 // check for white excess
			 rchannel = (rchannel > COLOR_UPLIMIT)? COLOR_UPLIMIT: rchannel;
			 gchannel = (gchannel > COLOR_UPLIMIT)? COLOR_UPLIMIT: gchannel;
			 bchannel = (bchannel > COLOR_UPLIMIT)? COLOR_UPLIMIT: bchannel;
			 // check for black excess
			 rchannel = (rchannel < COLOR_DOWNLIMIT)? COLOR_DOWNLIMIT: rchannel;
			 gchannel = (gchannel < COLOR_DOWNLIMIT)? COLOR_DOWNLIMIT: gchannel;
			 bchannel = (bchannel < COLOR_DOWNLIMIT)? COLOR_DOWNLIMIT: bchannel;



			 new_image.at<cv::Vec3b>(i,j) = cv::Vec3b(rchannel, gchannel, bchannel);
		}
	}


	return new_image;
}

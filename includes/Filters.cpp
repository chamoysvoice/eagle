#include "Filters.hpp"

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



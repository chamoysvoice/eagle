#include<iostream>
#define PIXEL_UPLIMIT 255



cv::Mat cry(cv::Mat image){
	cv::Mat dst(image.rows, image.cols, CV_8UC3);

	cv::Vec3b colors;
	int max_r, max_g, max_b;
	for (int j = 0; j < image.cols - 1; ++j) {
		max_r = max_g = max_b = 0;
		for (int i = 0; i < image.rows - 1; ++i) {
			 colors = image.at<cv::Vec3b>(i,j);
			 if(max_r < colors[0]) max_r = colors[0];
			 if(max_g < colors[1]) max_g = colors[1];
			 if(max_b < colors[2]) max_b = colors[2];

			 dst.at<cv::Vec3b>(i,j) = cv::Vec3b(max_r, max_g, max_b);
		}
	}


	return dst;
}

cv::Mat bw_histogram(cv::Mat src, int buckets){
	std::vector<int> bw_buckets (buckets,0);

	float bucket_size = 256.0 / buckets;
	int max;
	max = 0;
	bool add_bw;
	add_bw = false;
	cv::Vec3b colors;
	for (int i = 0; i < src.rows - 1; ++i) {
		for (int j = 0; j < src.cols - 1; ++j) {
			 colors = src.at<cv::Vec3b>(i,j);
			 add_bw = false;
			 for(int k = 0; k < buckets; k++){
				 if(colors[0] < bucket_size * k && !add_bw){
					 add_bw = true;
					 bw_buckets.at(k) += 1;
					 if(max < bw_buckets.at(k)) max = bw_buckets.at(k);
				 }

			 }
		}
	}


	int hist_w = 512; int hist_h = 360;
	cv::Mat histImage( hist_h, hist_w, CV_8UC3, cv::Scalar( 0,0,0) );


	for(int i = 1; i < buckets; i++){
		cv::line( histImage, cv::Point( 2 * bucket_size * (i-1), hist_h - cvRound(bw_buckets.at(i-1) * hist_h  / max  )) ,
			   cv::Point( 2 * bucket_size * (i), hist_h - cvRound(bw_buckets.at(i)  * hist_h / max )),
			   cv::Scalar( 255, 255, 255), 2, 2, 0  );
	}

	return histImage;
}

cv::Mat rgb_histogram(cv::Mat src, int buckets){

	std::vector<int> r_buckets (buckets,0);
	std::vector<int> g_buckets (buckets,0);
	std::vector<int> b_buckets (buckets,0);


	float bucket_size = 256.0 / buckets;
	int max;
	max = 0;
	bool add_r, add_g, add_b;
	add_r = add_g = add_b = false;
	cv::Vec3b colors;
	for (int i = 0; i < src.rows - 1; ++i) {
		for (int j = 0; j < src.cols - 1; ++j) {
			 colors = src.at<cv::Vec3b>(i,j);
			 add_r = add_g = add_b = false;
			 for(int k = 0; k < buckets; k++){
				 if(colors[0] < bucket_size * k && !add_r){
					 add_r = true;
					 r_buckets.at(k) += 1;
					 if(max < r_buckets.at(k)) max = r_buckets.at(k);
				 }
				 if(colors[1] < bucket_size * k && !add_g){
					 add_g = true;
					 g_buckets.at(k) += 1;
					 if(max < g_buckets.at(k)) max = g_buckets.at(k);
				 }
				 if(colors[2] < bucket_size * k && !add_b){
					 add_b = true;
					 b_buckets.at(k) += 1;
					 if(max < b_buckets.at(k)) max = b_buckets.at(k);
				 }
			 }
		}
	}


	int hist_w = 512; int hist_h = 360;
	cv::Mat histImage( hist_h, hist_w, CV_8UC3, cv::Scalar( 0,0,0) );


	for(int i = 1; i < buckets; i++){
		cv::line( histImage, cv::Point( 2 * bucket_size * (i-1), hist_h - cvRound(r_buckets.at(i-1) * hist_h  / max  )) ,
			   cv::Point( 2 * bucket_size * (i), hist_h - cvRound(r_buckets.at(i)  * hist_h / max )),
			   cv::Scalar( 255, 0, 0), 2, 2, 0  );
		cv::line( histImage, cv::Point( 2 * bucket_size * (i-1), hist_h - cvRound(g_buckets.at(i-1) * hist_h  /  max  )) ,
			   cv::Point( 2 * bucket_size * (i), hist_h - cvRound(g_buckets.at(i)  * hist_h / max )),
			   cv::Scalar( 0, 255, 0), 2, 2, 0  );
		cv::line( histImage, cv::Point( 2 * bucket_size * (i-1), hist_h - cvRound(b_buckets.at(i-1) * hist_h / max  )) ,
			   cv::Point( 2 * bucket_size * (i), hist_h - cvRound(b_buckets.at(i)  * hist_h / max )),
			   cv::Scalar( 0, 0, 255), 2, 2, 0  );
	}

	return histImage;
}


cv::Mat histogram(cv::Mat src, int buckets = 256){
	cv::Mat dst, tmp;
	if(src.channels() == 1){
		dst = bw_histogram(src, buckets);
	} else {
		dst = rgb_histogram(src, buckets);
	}
	return cry(dst);
}


#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	Mat src;
	if (argv[1]) {
		src = imread(argv[1], IMREAD_GRAYSCALE);
	} 
	else {
		src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	}

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}
	
	Mat dst(src.rows, src.cols, src.type());

/* "+/-" 를 이용한 밝기 조절 */
#if 0
	dst = src - 100;

#endif

/* 픽셀 값 접근 방법을 이용한 밝기 조절 */
#if 0
	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			// 이렇게만 할 경우 saturate 가 안됨
			dst.at<uchar>(j, i) = src.at<uchar>(j, i) + 100; 

			// 아래 처럼 경우에 따라 나눠주도록 한다.
			int v = src.at<uchar>(j, i) + 100;
			dst.at<uchar>(j, i) = v > 255 ? 255 : v < 0 ? 0 : v;

			// 혹은 saturate_cast 함수 사용
			dst.at<uchar>(j, i) = saturate_cast<uchar>(src.at<uchar>(j, i) + 100);
		}
	}
#endif

/* 평균 밝기 조절 */
#if 1
	int s = 0;
	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			s += src.at<uchar>(j, i);
		}
	}
	int m1 = s / (src.rows * src.cols);
	// sum과 mean 은 scalar 값이므로 0번째를 가져온다.
	int m2 = sum(src)[0] / src.total();
	int m3 = mean(src)[0];

	dst = src + (128 - m3);
#endif

	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}

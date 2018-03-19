#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	Mat dst;
	dst = 255 - src;

	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);

	return 0;
}

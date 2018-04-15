#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int gBrightness = 100; // 최댓값 지정
Mat src, dst;

void on_brightness(int pos, void* data) {
	Mat* pSrc = (Mat*)data; // data를 받을 수 도 있다. (전역변수 사용 안할 시)
	cout << gBrightness << ", " << pos << endl; // 전역변수 사용해도 되고 pos 변수를 이용해도 된다. (pos 와 Brightness 는 동일하게 나온다.)
	dst = src + (gBrightness - 100); // 최솟값 지정
	imshow("dst", dst);
}

int main(void)
{
	src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}
	
	dst;
	dst.create(src.rows, src.cols, src.type());
	namedWindow("dst");
	imshow("src", src);

	// 반드시 createTrackbar는 imshow 혹은 namedWindow뒤에 해주어야 trackbar가 이용 가능한다.
	createTrackbar("Brightness", "dst", &gBrightness, 200, on_brightness,0);
	on_brightness(0, 0); // 처음에 나올 부분을 만들어 준다.
	imshow("dst", dst);

	waitKey(0);
	return 0;
}

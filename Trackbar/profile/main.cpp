#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void on_trackbar(int, void*);
Mat src, dst, profile;
int row = 0;

int main(void)
{
	src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("dst");
	namedWindow("profile");

	profile.create(src.rows, src.cols, CV_8U);

	createTrackbar("Profile", "dst", &row, src.rows-1, on_trackbar, NULL);
	on_trackbar(0, 0);

	waitKey(0);
	return 0;
}

void on_trackbar(int pos, void* data) {
	// trackbar가 움직이면 dst 와 profile 을 리셋
	src.copyTo(dst);
	profile.setTo(255);

	uchar* pSrc = (uchar*)src.ptr<uchar>(row);
	uchar* pDst = (uchar*)dst.ptr<uchar>(row);
	for (int i = 1; i < src.cols; i++) {
		// 프로파일에 점이 아닌 라인으로 보여줌(0 : 검정색)
		line(profile, Point(i - 1, 255 - pSrc[i - 1]), Point(i, 255 - pSrc[i]), 0);

		// dst 영상에서 어느 위치인지 표시하기 위해 밝은색으로 라인 설정
		pDst[i] = saturate_cast<uchar>(pSrc[i] + 50);
	}

	imshow("profile", profile);
	imshow("dst", dst);
}

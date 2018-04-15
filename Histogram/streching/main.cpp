#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat getHistogram(const Mat& src);

int main(void)
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	double gMax, gMin;
	minMaxLoc(src, &gMin, &gMax);
	
	Mat dst;

#if 1
	// 히스토그램 스트레칭 이용
	dst = (src - gMin) / (gMax - gMin) * 255;
# else
	// 픽셀에 접근하여 구현
	dst = Mat::zeros(src.row, src.cols, src.type());
	for (int j = 0; j < src.rows; j++) {
		uchar* pSrc = src.ptr<uchar>(j);
		uchar* pDst = dst.ptr<uchar>(j);
		for (int i = 0; i < src.cols; i++) {
			pDst[i] = saturate_cast<uchar>((pSrc[i] - gMin) / (gMax - gMin) * 255);
		}
	}
#endif
	Mat histSrc = getHistogram(src);
	Mat histDst = getHistogram(dst);

	imshow("src", src);
	imshow("dst", dst);
	imshow("histSrc", histSrc);
	imshow("histDst", histDst);

	waitKey(0);
	return 0;
}

Mat getHistogram(const Mat& src) {
	CV_Assert(src.type() == CV_8U);
	
	Mat hist;
	const int channel[] = { 0 };
	int dims = 1;
	const int histSize[] = { 256 };
	float graylevel[] = { 0,256 };
	const float* ranges[] = { graylevel };

	calcHist(&src, 1, channel, noArray(), hist, dims, histSize, ranges);

	// 그레이 스케일로
	Mat imgHist(100, 256, CV_8U, Scalar(255));

	double maxHist;

	minMaxLoc(hist, 0, &maxHist);
	for (int i = 0; i < 256; i++) {
		line(imgHist, Point(i, 100), Point(i, 100 - cvRound(hist.at<float>(i) * 100 / maxHist)), Scalar(0));
	}

	return imgHist;
}
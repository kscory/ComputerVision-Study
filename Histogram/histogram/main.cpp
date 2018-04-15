#include "opencv2/opencv.hpp"
#include <iostream>


using namespace cv;
using namespace std;

Mat histogram_1(const Mat& src);
Mat histogram_2(const Mat& src);
Mat histoTest(const Mat& src);

int main(void)
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	Mat his1 = histogram_1(src);

	Mat his2 = histogram_2(src);
	imshow("hist2",his2);

	imshow("src", src);

	waitKey(0);
	return 0;
}

// 일반 배열로 직접 구하기
Mat histogram_1(const Mat& src) {
	int hist[256] = { 0, };
	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			// 각 픽셀에 맞는 값에 1씩 더함
			hist[src.at<uchar>(j, i)]++;
		}
	}

	// 화면에 나타내기 위한 적절한 최댓값 구하기
	int maxHist = 0;
	for (int i = 0; i < 256; i++) {
		if (maxHist < hist[i]) maxHist = hist[i];
	}

	// 화면에 보여주기 위한 영상 생성 (세로 100, 가로 256)
	Mat imgHist(100, 256, CV_8U, Scalar(255));
	for (int i = 0; i < 256; i++) {
		line(imgHist, Point(i, 100), Point(i, 100 - cvRound(hist[i] * 100 / maxHist)), Scalar(0));
	}

	return imgHist;

}

// calcHist() 함수를 이용해서 구하기
Mat histogram_2(const Mat& src) {
	// 1. hist 만들기
	CV_Assert(src.type() == CV_8U); // 이미지 타입이 다르다면 에러를 발생

	Mat hist;
	int channels[] = { 0 };
	int dims = 1;
	const int histSize[] = { 256 };
	float graylevel[] = { 0,256 };
	const float* ranges[] = { graylevel };

	calcHist(&src, 1, channels, Mat(), hist, dims, histSize, ranges);

	// 2. grayscale 히스토그램 영상 만들어서 반환
	CV_Assert(hist.type() == CV_32F);
	CV_Assert(hist.size() == Size(1, 256));

	// 최댓값을 구함
	double histMax;
	minMaxLoc(hist, 0, &histMax);

	Mat imgHist(100, 256, CV_8U, Scalar(255));
	for (int i = 0; i < 256; i++) {
		line(imgHist, Point(i, 100), Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)), Scalar(0));
	}

	return imgHist;
}
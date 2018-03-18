#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void func1();
void func2();
void func3();
void func4();

int main(void)
{
	func1(); getchar();
	func2(); getchar();
	func3(); getchar();
	func4(); getchar();

	return 0;
}

/**
	Mat 클래스 객체 새성 & 행렬 정보 얻어오기 예제
*/
void func1() {
	// Mat 클래스 객체 생성
	int rows = 480, cols = 640;
	Mat img1(rows, cols, CV_8U);			// unsigned char
	Mat img2(rows, cols, CV_8UC3);			// unsigned char, 3 channel
	Mat img3(Size(cols, rows), CV_8UC3);	// Size(width, height)
	img3.create(rows, cols, CV_32F);		// float

	Mat img4 = imread("lenna.bmp");

	// 특정 영상의 행,열 갯수 얻어오기
	cout << "Width: " << img4.cols << endl;
	cout << "Height: " << img4.rows << endl;

	// 특정 영상의 채널 개수 불러오기
	cout << "Channels: " << img4.channels() << endl;

	// 특정 영상의 타입 불러오기
	if (img4.type() == CV_8UC1)
		cout << "img4 is a grayscale image" << endl;
	else if (img4.type() == CV_8UC3)
		cout << "img4 is a truecolor image" << endl;
}

void func2() {
	// 생성과 동시에 원소 값 설정
	int nRows = 3, nCols = 4;
	Mat img1(nRows, nCols, CV_8U, Scalar(128));		// 128로 초기화된 행렬 생성
	Mat img2 = Mat::ones(3, 4, CV_8U);				// 1로 초기화된 행렬 생성
	Mat img3 = Mat::zeros(3, 4, CV_8U);				// 0으로 초기화된 행렬 생성
	Mat img4 = Mat::ones(480, 640, CV_8U) * 255;	// 255로 초기화되어 있는 행렬 생성

	// img1 의 원소 값을 0 (혹은 다른 수)로 초기화
	img1.setTo(0);

	// 행렬에 각각 정해진 값으로 초기화 가능 
	float data[] = { 1,2,3,4,5,6 };
	Mat img5(2, 3, CV_32F, data);
	cout << "img5:\n" << img5 << endl;	// [ 1 2 3 형식으로 나온다.
										//	 4 5 6 ]

	Mat mat5 = (Mat_<double>(2, 3) << 1, 2, 3, 4, 5, 6);
}

void func3() {
	// 영상 참조 & 복사
	Mat img1 = imread("lenna.bmp", IMREAD_GRAYSCALE);

	Mat img2 = img1;			// 참조 (얖은 복사)
	Mat img3 = img1.clone();	// (깊은) 복사
	Mat img4;			
	img1.copyTo(img4);			// (깊은) 복사

	// 부분 영상 참조 & 복사
	Mat img5 = img1(Rect(100, 100, 200, 200));
	Mat img6 = img4(Rect(100, 100, 200, 200)).clone();

	img5.setTo(0);
	img6.setTo(255);

	imshow("img1", img1); imshow("img2", img2); imshow("img3", img3); 
	imshow("img4", img4); imshow("img5", img5); imshow("img6", img6);
	waitKey();
	destroyAllWindows();
}

void func4() {
	float data[] = { 1,1,2,3 };
	Mat mat1(2, 2, CV_32F, data);
	cout << "mat:\n" << mat1 << endl;

	// 역행렬
	Mat mat2 = mat1.inv();
	cout << "mat2:\n" << mat2 << endl;

	// 전치행렬
	cout << "mat1.t():\n" << mat1.t() << endl;

	// 사칙연산
	cout << "mat1 + 3:\n" << mat1 + 3 << endl;
	cout << "mat1 + mat2:\n" << mat1 + mat2 << endl;
	cout << "mat1 * mat2:\n" << mat1 * mat2 << endl;
}
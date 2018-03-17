// OpenCV 관련 헤더 파일을 #include
#include "opencv2/opencv.hpp"
#include <iostream>

// OpenCV & STL 네임 스페이스 지정
using namespace cv;
using namespace std;

int main(void) {
	cout << "Hello OpenCV " << CV_VERSION << endl;

	// 입력 저장할 변수 선언
	Mat img;

	// lenna.bmp 파일을 불러오기
	img = imread("lenna.bmp");

	// 영상 파일 불로오기 실패 시 에러 메시지 출력 후 프로그램 종료
	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	// "image" 라는 이름의 새 창을 만들고, 여기에 img 영상 출력
	namedWindow("image");
	imshow("image", img);
	// 키보드 입력이 있을 때까지 프로그램을 멈추고 대기 ( waitkey(2000) 이면 2초 후 종료 )
	waitKey(0);
	return 0;
}

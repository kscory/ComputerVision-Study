#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	// 인자가 3개 보다 작다면 에러 호출
	if (argc < 3) {
		cout << "Usage: ocvrt.exe <src_image> <dst_image> [JPEG_QUALITY]" << endl;
		return 0;
	}
	
	// 입력한 파일을 읽어옴
	Mat img = imread(argv[1], IMREAD_UNCHANGED);

	// 파일이 비어 있다면 에러 호출
	if (img.empty()) {
		cerr << "image load failed" << endl;
		return -1;
	}

	// 파일 저장 옵션 지정(3개보다 많은 경우 지정, 아님 디폴트)
	vector<int> params;
	if (argc == 4) {
		params.push_back(IMWRITE_JPEG_QUALITY);
		params.push_back(atoi(argv[3]));
	}

	// 영상 저장하기
	bool ret = imwrite(argv[2], img, params);

	if (ret) {
		cout << argv[1] << " is successfully saved ad " << argv[2] << endl;
	}
	else {
		cout << "File save failed!" << endl;
	}

	return 0;
}

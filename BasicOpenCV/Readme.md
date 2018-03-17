# OpenCV Setting
  - 영상 불러와서 출력
  - OpenCV API
    - imread / imwrite
    - namedWindow
    - destroyWindow / destroyAlWindows
    - moveWindow / resizeWindow
    - imshow / waitKey
  - 영상 파일 형식 변환

---

## 영상 불러와서 출력
  ### 1. 영상 출력
  - 변수 선언 → 파일 불러오고 → 새창에 출력
  - namedWindow 를 안해주어도 생성되기는 한다. (imshow + waitKey 조합을 주로 사용)
  - destroyWindow 를 특별하게 선언하지 않는다면 프로그램이 종료할때 자동으로 종료시켜 준다.

  ```cpp
  // OpenCV 관련 헤더 파일을 #include
  #include "opencv2/opencv.hpp"
  #include <iostream>

  // OpenCV & STL 네임 스페이스 지정
  using namespace cv;
  using namespace std;

  int main(void) {
    // Hello OpenCV + 버전을 출력
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
  ```

  - 결과

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/BasicOpenCV/picture/result1.png)

---

## OpenCV API
  ### 1. imread
  - 영상 불러오기

  ### 2. imwrite
  - 영상 저장하기

  ### 3. namedWindow
  - 새 창 띄우기

  ### 4. destroyWindow & destroyAlWindows
  - 창 닫기

  ### 5. moveWindow
  - 창 위치 변경

  ### 6. resizeWindow
  - 창 크기 지정

  ### 7. imshow
  - 영상 출력

  ### 8. waitKey
  - 키보드 입력 대기

---

## 영상 파일 형식 변환
  ### 1. 영상 파일 형식 변환
  -

---

## 참고
  ### 1. Image Watch 사용하기
  - ㅇㅇㅇ

  ### 2. OpenCV API 도움말 찾기
  - [OpenCV 최신 도움말 링크](https://docs.opencv.org/master/)
  - 우측 상단 검색창 이용 (가장 상단은 내부에서 구글 검색용)

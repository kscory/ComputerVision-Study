# OpenCV Setting
  - Basic OpenCV API
    - imread / imwrite
    - namedWindow
    - destroyWindow / destroyAlWindows
    - moveWindow / resizeWindow
    - imshow / waitKey
  - 영상 불러와서 출력
  - 영상 파일 형식 변환

---

## OpenCV API
  ### 1. 영상 불러오기 ( imread )

  ```cpp
  Mat cv::imread( const String & filename,
                  int flags = IMREAD_COLOR );
  ```

  - `filename` : 불러올 파일 이름(ex> "lenna.bmp" / "C:\\\\lenna.bmp")
    - 상대경로 및 절대경로로 불러올 수 있음
  - `flags` : 영상 불러오기 방식 지정 (디폴트는 트루컬러)
    - `IMREAD_UNCHANGED` : 영상 속성 그대로 읽기
    - `IMREAD_GRAYSCALE` : 1채널 그레이스케일 영상으로 읽기
    - `IMREAD_COLOR` : 3채널 트루컬러(BGR) 영상으로 읽기

  ### 2. 영상 저장하기 ( imwrite )

  ```cpp
  bool cv::imwrite( const String & filename,
                    InputArray img ,
                    const std ::vector<int>& params = std ::vector<int>() );
  ```

  - `params` : 파일 저장 옵션 지정(속성 & 값의 정수 쌍)
    - ex> vector<int> params(IMWRITE_JPEG_QUALITY, 95);

  ### 3. namedWindow
  - 새 창 띄우기

  ```cpp
  void cv::namedWindow( const String & winname,
                        int flags = WINDOW_AUTOSIZE );
  ```

  - `winname` : 창 고유 이름
  - `flags` : 창 옵션
    - `WINDOW_NORMAL` : 창 크기 지정 가능
    - `WINDOW_AUTOSIZE` : 창 크기가 자동으로 지정됨
    - `WINDOW_OPENGL` : OpenGL 지원

  ### 4. destroyWindow & destroyAlWindows
  - 창 닫기

  ```cpp
  void cv::destroyWindow( const String & winname );
  void cv::destroyAlWindows();
  ```

  - `winname` : 닫고자 하는 창 이름
  - 일반적인 경우 프로그램 종료 시 운영체제에 의해 열려 있는 모든 창이 자동으로 닫힘

  ### 5. moveWindow
  - 창 위치 변경

  ```cpp

  ```

  ### 6. resizeWindow
  - 창 크기 지정

  ```cpp

  ```

  ### 7. imshow
  - 영상 출력

  ```cpp

  ```

  ### 8. waitKey
  - 키보드 입력 대기

  ```cpp

  ```

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

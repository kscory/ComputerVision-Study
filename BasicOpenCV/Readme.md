# OpenCV Setting
  - Basic OpenCV API
    - imread / imwrite
    - namedWindow
    - destroyWindow / destroyAlWindows
    - moveWindow / resizeWindow
    - imshow / waitKey
    - [OpenCV API 도움말](https://docs.opencv.org/master/) 에서 다른 Api 도 검색 가능
  - 영상 불러와서 출력
  - 영상 파일 형식 변환
  - Image Watch 사용

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

  ### 3. 새 창 띄우기 ( namedWindow )

  ```cpp
  void cv::namedWindow( const String & winname,
                        int flags = WINDOW_AUTOSIZE );
  ```

  - `winname` : 창 고유 이름
  - `flags` : 창 옵션
    - `WINDOW_NORMAL` : 창 크기 지정 가능
    - `WINDOW_AUTOSIZE` : 창 크기가 자동으로 지정됨
    - `WINDOW_OPENGL` : OpenGL 지원

  ### 4. 창 닫기 ( destroyWindow & destroyAlWindows )

  ```cpp
  void cv::destroyWindow( const String & winname );
  void cv::destroyAlWindows();
  ```

  - `winname` : 닫고자 하는 창 이름
  - 일반적인 경우 프로그램 종료 시 운영체제에 의해 열려 있는 모든 창이 자동으로 닫힘

  ### 5. 창 위치 변경 ( moveWindow )

  ```cpp
  void cv::moveWindow( const String & winname,
                      int x, int y );
  ```

  - `winname` : 윈도우 이름
  - `x`, `y` : 이동할 윈도우 좌표

  ### 6. 창 크기 지정 ( resizeWindow )

  ```cpp
  void cv::resizeWindow( const String & winname,
                        int width, int height);
  ```

  - `winname` : 윈도우 이름
  - `width`, `height` : 변경할 윈도우 크기
  - 참고사항
    - "WINDOW_AUTOSIZE" 속성으로 만들면 동작하지 않는다.
    - 영상 출력 부분의 크기만을 고려하며 툴바는 고려되지 않는다.

  ### 7. 영상 출력( imshow )

  ```cpp
  void cv::imshow( const String & winname,
                  InputArray mat );
  ```

  - `winname` : 출력 창 이름
  - `mat` : 출력할 영상 (Mat 객체)
  - 출력 방식
    - 8-bit unsigned : 픽셀 값을 그대로 사용하여 출력
    - 16-bit unsigned or 32-bit integer : 픽셀 값을 255 로 나눠서 출력
    - 32-bit or 64-bit floating point : 픽셀 값에 255를 곱해서 출력
  - 참고 사항
    - 만약 winname 에 해당하는 창이 없으면 자동으로 WINDOW_AUTOSIZE 속성의 창을 만들고 영상을 출력한다.
    - Window 운영체제에서는 `Ctrl + C`(복사) & `Ctrl + S`(저장) 지원한다.
    - 실제로는 waitKey() 함수를 호출해야 화면에 영상이 나타난다.

  ### 8. 키보드 입력 대기( waitKey )

  ```cpp
  int cv::waitKey( int delay = 0);
  ```

  - `delay` : 밀리초 단위 대기시간, (0이면 무한히 기다림 - 디폴트)
  - 반환 값 : 눌러진 키 값(ex> ESC는 27). 키가 눌리지 않으면 -1.
  - 참고 사항
    - waitKey 함수는 OpenCV 창이 하나라도 있을 때 동작
    - imshow 함수 호출 후에 waitKey 함수를 호출해야 영상이 화면에 나타남

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
  	// 키보드 입력이 있을 때까지 프로그램을 멈추고 대기 ( waitKey(2000) 이면 2초 후 종료 )
  	waitKey(0);
  	return 0;
  }
  ```

  - 결과

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/BasicOpenCV/picture/result1.png)

---

## 영상 파일 형식 변환
  ### 1. 영상 파일 형식 변환
  - 명령행 인자로 입력 받은 영상 파일을 다른 형식으로 변환하여 저장
  - 경로에서 `cmd` 를 입력하여 커멘드 창을 열고 `ocvrt.exe [원본] [바꿀형식]` 으로 입력
  - `argc` : 입력되는 인자 개수
  - `argv` : 각각 입력된 파일을 가져온다.

  ```cpp
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
  ```

  - 실행 방법 및 결과

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/BasicOpenCV/picture/result2.png)

---

## 참고
  ### 1. Image Watch 사용하기
  - Image Watch란 OpenCV Mat 데이터를 영상 형태로 보여주는 디버깅 툴
  - 설치 방법
    - Visual Studio 도구 -> 확장 및 업데이트 -> 온라인 항목 -> Image Watch 검색 및 다운로드(OpenCV 용으로)
  - 사용하기
    - 중단점(F9) 설정 후 디버깅 시작(F5)
    - [보기] -> [다른 창] -> [Image Watch] 선택
  - 예시

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/BasicOpenCV/picture/result3.png)

  ### 2. OpenCV API 도움말 찾기
  - [OpenCV 최신 도움말 링크](https://docs.opencv.org/master/)
  - 우측 상단 검색창 이용 (가장 상단은 내부에서 구글 검색용)

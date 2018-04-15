# Trackbar & Profile
  - OpenCV API
    - 트랙바 생성 함수
    - 직선 그리기
  - 트랙바 사용법
  - 프로파일 사용법

---
## OpenCV API
  ### 1. 트랙바 생성 함수

  ```cpp
  int cv::createTrackbar( const String & trackbarname,
                          const String & winname,
                          int * value,
                          int count,
                          TrackbarCallback onChange = 0,
                          void * userdata = 0
  );
  ```

  - `trackbarname` : 트랙바 이름
  - `winname` : 트랙바를 생성할 윈도우 이름
  - `value` : 트랙바 위치 값을 받을 정수형 변수의 주소
  - `count` : 슬라이더 최댓값, 최솟값은 항상 0
  - `onChange` : 슬라이더 위치가 바뀔 때 실행될 __콜백함수__
    - 콜백함수 형식 : `void function (int, void*)`
  - `userdata` : 콜백 함수에 전달할 데이터(전역변수 대체 가능)

  ### 2. 직선 그리기

  ```cpp
  void cv::line( InputOutputArray img,
                Point pt1,
                Point pt2,
                const Scalar & color,
                int thickness = 1,
                int lineType = LINE_8,
                int shift = 0
  );
  ```

  - `img` 영상에 `pt1` 좌표부터 `pt2` 좌표까지 `color` 색상으로 thickness 두께로 직선을 그린다.
  - `lineType` 의 디폴트는 LINE_8 로 매끄러운 직선을 뜻함

---

## Trackbar
  ### 1. 트랙바란?
  - 프로그램 동작 중 밝기 혹은 명암비 등 어떤 값을 조절하면서 결과를 보고 싶을 때 사용
  - 아래와 같은 bar를 이야기함

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Trackbar/picture/trackbar.png)

  ### 2. 트랙바 사용 방법
  - 전역변수를 사용할 수도, 안할수도 있다.
  - trackbar의 범위를 정할 수 있다.
  - 콜백함수를 강제로 한번 호출시켜 처음 영상을 보여주도록 한다.(안하면 처음 화면은 빈화면이 나온다.)

  ```cpp
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
  ```
  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Trackbar/picture/trackbar2.png)

---

## Profile
  ### 1. 프로파일 이란?
  - 영상에서 특정 경로(라인 혹은 곡선) 에 있는 픽셀의 밝기 값을 그래프 형태로 나타낸 것
    - 어두우면 아래로, 밝으면 위로 나타난다.
  - 영상의 특성을 분석하는 용도로 사용됨
  - 아래와 같이 나오는 것을 프로파일이라고 한다.

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Trackbar/picture/profile.png)

  ### 2. 프로파일 코딩 (with trackbar)
  - 영상의 특정 행의 프로파일을 그래프 형태로 출력한다.
  - 트랙바의 범위는 영상의 세로크기, 트랙바를 이동하면 프로파일 그래프를 갱신한다.
  - OpenCV 의 라인함수 사용

  ```cpp
  void on_trackbar(int, void*);
  Mat src, dst, profile;
  int row = 0;

  int main(void)
  {
  	src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    ...

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
  ```

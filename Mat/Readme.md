# 행렬의 기본 연산과 Mat class
  - 행렬의 기본 연산
  - Mat 클래스
  - OpenCV API (Mat class)
    - ptr / at
    - operator
    - coverTo
  - Mat 클래스 예제

---

## 행렬의 기본 연산
  ### 1. 행렬이란?
  - 수나 기호, 수식 등을 네모꼴로 배열한 것. 괄호로 묶어 표시한다.
  - 가로가 행, 세로가 열
  - 행의 개수가 1인 것을 행벡터라 하며 열의 개수가 1인 것을 열벡터라 한다.

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Mat/picture/matrix1.png)

  ### 2. 덧셈 과 곱셈
  - 덧셈 : 같은 행과 같은 열을 더한다.
  - 곱셈 : 앞의 열과 뒤의 행을 곱해서 더한 후 앞의 열번째 자리, 뒤의 행번째 자리에 놓는다.

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Mat/picture/matrix2.png)

  ### 3. 역행렬(Inverse Matrix)과 전치 행렬(Transpose Matrix)
  - 역행렬이란 AX=E 일 때 X 를 A 의 역행렬이라 한다.
  - 전치행렬이란 행과 열을 바꿔서 표기하는 것을 의미한다.

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Mat/picture/matrix3.png)

---

## Mat 클래스
  ### 1. Mat 클래스 란
  - n 차원 1채널 혹은 다채널 행렬 표현을 위한 OpenCV 내장 클래스
    - 실수 혹은 복소수 행렬, 그레이스케일 혹은 트루컬러 영상, 벡터 필드, 히스토그램, 텐서 등을 표현
  - 다양한 형태의 행렬 생성방법을 제공
    - 생성자, 복사 생성자 등
    - create(), clone(), copyTo(), zeros(), ones(), eye() 등
    - Mat_ 클래스와 << 연산자, 쉼표(,)로 구분된 초기값을 사용
  - 생성된 행렬은 참조계수(reference counting) 방법으로 관리됨
    - ※ 주의 : 대입 연산자는 얕은 복사 수행
    - 깊은 복사는 `copyTo()` 혹은 `clone()` 함수 이용
  - 행렬의 원소(픽셀 값) 접근 방법
    - `Mat::data` 멤버 변수에 실제 대에터가 저장된다.
      - addr(Mij) = M.data + M.step[0]\*i + M.step[1]\*j
    - `Mat::at<type>(int y, int x)` 함수를 통해 원소에 접근 가능


  ### 2. Mat 클래스 특징
  - Mat 클래스는 아래와 같이 구성된다.
    - 생성자 & 소멸자
    - 멤버 함수 연산자 재정의
    - 멤버 변수

  > Mat 클래스

  ```cpp
  public:
    // 생성자 & 소멸자
    Mat();
    Mat(int rows, int cols, int type);
    /* ... */

    // 멤버 함수 연산자 재정의
    void create(int rows int cols, int type);
    Mat& operator = (const Mat& m);
    Mat clone() const;
    void copyTo(OutputArray m) const;

    template<typename _TP> _TP* ptr(int i0 = 0);
    template<typename _TP> _TP& at(int row, int col);
    /* ... */

    // 멤버변수
    int dims;
    int rows, cols;
    uchar* data;
    /* ... */
  ```

  ### 3. Mat 클래스 타입 & 깊이
  - Mat 클래스 타입(CV_{비트수}{부호}{채널 갯수}) 로 구성
    - ex> `CV_8UC1` : 8(8bit), U(unsigned char), C1(1 channel)
    - 참고 : 채널갯수 입력 시  `C1` 은 그레이스케일이며 생략 가능( ex> `CV_8U` )
  - Mat 클래스 깊이(depth)

  ```cpp
  /* Mat 클래스 깊이 */
  #define CV_8U  0  // uchar uchar, unsigned char
  #define CV_8S  1  // schar, signed char
  #define CV_16U 2  // ushort, unsigned short
  #define CV_16S 3  // short
  #define CV_32S 4  // int
  #define CV_32F 5  // float
  #define CV_64F 6  // double
  ```

---

## Mat class 에서의 OpenCV API
  ### 1. 특정 행의 시작 주소 반환 (ptr)

  ```cpp
  tempate<typename _TP>
  _TP* Mat::ptr(int y);
  ```

  - `y` : 참조할 행 번호
  - 반환값 : (\_TP\* 타입으로 캐스팅된) y번째 행의 시작 주소

  ### 2. 특정 원소의 참조 반환 (at)

  ```cpp
  tempate<typename _TP>
  _TP& Mat::at(int i0, int i1);
  ```

  - `i0` : 참조할 행 번호
  - `i1` : 참조할 열 번호
  - 반환값 : (\_TP& 타입으로 캐스팅된)i0번 행, i1번 열의 원소 값 (참조)

  ### 3. 부분 행렬 / 부분 영상 추출 또는 ROI 설정 (operator)

  ```cpp
  // Rect 혹 은 roi 받는 경우
  Mat cv::Mat::operator() (const Rect & roi) const;
  // 범위를 받는 경우
  Mat cv::Mat::operator() (Range rowRange, Range colRange) const;
  ```
  - `roi` : 사각형 관심 영역
  - `rowRange` : 관심 행 범위(start, end)
  - `colRange` : 관심 열 범위(start, end)
  - 반환값 : rot 부분 행렬/영상 (참조)

  ### 4. 행렬 데이터의 타입 변환 (coverTo)

  ```cpp
  void cv::Mat::converTo( OutputArray m,
                          int rtype,
                          double alpha = 1,
                          double beta = 0) const;
  ```

  - `m` : 출력 행렬, 만약 지정된 행렬이 같은 크기나 타입이 아니면 새로 할당
  - `rtype` : 원하는 출력 행렬 타입 또는 깊이
    - 출력행렬의 채널 수는 원본 행렬과 동일
    - rtype == -1 인 경우 같은 타입의 행렬을 생성
  - `alpha` : (optional) 추가적으로 곱하는 값
  - `beta` : (optional) 추가적으로 더하는 값

---

## Mat 클래스 예제
  ### 1. Mat 클래스 생성 & 행렬 정보 얻어오기
  - Mat 클래스 생성 (주로 8U 형식으로 생성함)
  - 특정 정보 얻어오기 (by Api or variable)

  ```cpp
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
  ```

  ### 2. Mat 클래스 생성 & 원소 값 설정
  - 영상을 생성할 때 원하는 값으로 초기화 시킬 수 있다.
  - 또한 영상의 원소값을 변경시킬 수 있다.

  ```cpp
  void func2() {
  	// 생성과 동시에 원소 값 설정
  	int nRows = 3, nCols = 4;
  	Mat img1(nRows, nCols, CV_8U, Scalar(128));		// 128로 초기화된 행렬 생성
  	Mat img2 = Mat::ones(3, 4, CV_8U);				// 1로 초기화된 행렬 생성
  	Mat img3 = Mat::zeros(3, 4, CV_8U);				// 0으로 초기화된 행렬 생성
  	Mat img4 = Mat::ones(480, 640, CV_8U) * 255;	// 255로 초기화되어 있는 행렬 생성

  	// img1 의 원소 값을 0 (혹은 다른 수)로 초기화
  	img1.setTo(0);

  	// 행렬에 각각 정해진 값으로 초기화 가능 (열부터 채우고 행으로 내려감)
  	float data[] = { 1,2,3,4,5,6 };
  	Mat img5(2, 3, CV_32F, data);
  	cout << "img5:\n" << img5 << endl;

  	Mat mat5 = (Mat_<double>(2, 3) << 1, 2, 3, 4, 5, 6);
  }
  ```

  ### 3. Mat 클래스 참조 & 복사
  - Mat 클래스를 사용할 때는 복사를 할지 참조를 할지 생각해야 한다.
  - clone 및 copyTo 를 통해 깊은 복사를 할 수 있다.

  ```cpp
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
  ```

  - 결과

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Mat/picture/result1.png)

  ### 4. Mat 클래스 기본 행렬 연산
  - Mat 클래스는 행렬 연산이 가능하다.

  ```cpp
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
  ```

---

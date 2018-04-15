# 영상의 산술 연산
  - ㅇㅇ

---

## 영상의 산술 연산
  ### 1. 덧셈 연산
  - `h(x,y) = f(x,y) + g(x,y)`
  - 두 영상의 같은 위치에 존재하는 픽셀 값을 더하여 결과 영상의 픽셀 값으로 설정
  - 연산은 Saturate 연산이 적용되므로 Maximum 255

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Arithmetic/picture/add.png)

  ### 2. 뺄셈 연산
  - `h(x,y) = f(x,y) - g(x,y)`
  - 두 영상의 같은 위치에 존재하는 픽셀 값을 뺀 후 결과 영상의 픽셀 값으로 설정
  - 연산은 Saturate 연산이 적용되므로 Minimun 0

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Arithmetic/picture/subtract.png)

  ### 3. 평균 연산 (weighted sum)
  - weighted sum 연산

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Arithmetic/picture/mean.png)

  - 덧셈에 비중을 주면 영상이 전체적으로 밝아지지만, 평균연산의 경우 입력 영상의 밝기 정도를 그대로 유지한다.
  - 아래와 같이 잡음제거를 할 수 있다.

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Arithmetic/picture/mean2.png)

  ### 4. 차이 연산 (절댓값)
  - `h(x,y) = |f(x,y) - g(x,y)|`
  - 두 입력 연산에 대한 차이(절댓값)을 이용하여 결과 영상을 생성
  - 뺄셈 연산과 달리 입력 영상의 순서에 영향을 받지 않는다.
  - 차이 연산은 새로운 부분을 확인하는 가장 간단한 형태의 침임자 검침 확인 방법

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Arithmetic/picture/diff.png)

  ### 5. 구현
  - 연산을 수행할 때는 반드시 Matrix 들의 타입과 크기가 같아야만 한다.
  아래의 함수 사용
    - `add()` : 덧셈
    - `subtract()` : 뺄셈
    - `addWeighted()` : 평균(가중치)
    - `absdff()` : 차이(절댓값)

  ```cpp
  int main(void)
  {
  	Mat src1 = imread("lenna.bmp", IMREAD_GRAYSCALE);
  	Mat src2 = imread("aero2.bmp", IMREAD_GRAYSCALE);

  	if (src1.empty() || src2.empty()) {
  		cerr << "Image load failed!" << endl;
  		return -1;
  	}

  	// 영상의 크기와 타입이 같은지 확인
  	if (src1.rows != src2.rows || src1.cols != src2.cols || src1.type() != src2.type()) {
  		cerr << "Two images are not the same dimension" << endl;
  		return -1;
  	}

  	imshow("src1", src1);
  	imshow("src2", src2);

  	Mat dst(src1.rows, src1.cols, src1.type());

  	// 덧셈
  	add(src1, src2, dst);
  	imshow("dst", dst);
  	waitKey();

  	// 뺄셈
  	subtract(src1, src2, dst);
  	imshow("dst", dst);
  	waitKey(0);

  	// 평균
  	addWeighted(src1, 0.5, src2, 0.5, 0, dst);
  	imshow("dst", dst);
  	waitKey(0);

  	// 차이
  	absdiff(src1, src2, dst);
  	imshow("dst", dst);
  	waitKey(0);

  	return 0;
  }
  ```

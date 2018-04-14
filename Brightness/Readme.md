# Brightness
  - 밝기 조절 수식
  - 밝기 조절 예제
    - +/- 연산자 재정의
    - 픽셀 값 접근
    - 평균 밝기 보정 방법

---

## 밝기 조절 기본
  ### 1. 밝기 조절 이란?
  - 영상 전체 밝기를 일괄적으로 밝게 만들거나 어둡게 만드는 연산
  - 평균 밝기를 이용한 밝기 조절도 가능
  - 밝기 조절 예시

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Brightness/picture/brightness.png)

  ### 2. 밝기 조절 수식
  - 픽셀값은 0~255 까지 밖에 없기 때문에 0보다 작다면 0, 255보다 크다면 255로 맞추어야 한다. (Saturate 연산)
  - 수식 : `g(x,y) = f(x,y) + n`

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Brightness/picture/brightness1.png)

---

## 밝기 조절 예제
  ### 1. +/- 연산자 재정의 사용 방법
  - `+/-` 연산자에는 saturate 연산이 포함되어 있다.

  ```cpp
  int main(int argc, char* argv[])
  {
  	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

  	Mat dst(src.rows, src.cols, src.type());
  	dst = src + 100;

  	imshow("src", src);
  	imshow("dst", dst);

  	waitKey(0);
  	return 0;
  }
  ```

  ### 2. 픽셀 값 접근 방법 사용
  - unsigned character 타입은 255 까지 세팅이 되기 때문에 256 이 대입될 경우 0 이 리턴되므로 경우에 따라 나눠주어야 한다.
    - unsigned char 는 8bit(0000 0000) 으로 비트가 사용되는데 256 의 경우 (1 0000 0000) 이므로 a = 256 을 넣으면 a 에는 8비트만 저장이 되고 이는 `0` 이 리턴된다.
    - ex> 따라서 257 은 1, 258은 2 를 리턴하므로!! __saturate__ 를 조심해서 연산해야 한다!!
  - 혹은 `saturate_cast` 함수를 이용할 수 있다.

  ```cpp
  int main(int argc, char* argv[])
  {
  	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

  	Mat dst(src.rows, src.cols, src.type());

  	for (int j = 0; j < src.rows; j++) {
  		for (int i = 0; i < src.cols; i++) {
  			// 주의 : 이렇게만 할 경우 saturate 가 안됨
  			dst.at<uchar>(j, i) = src.at<uchar>(j, i) + 100;

  			// 1. 아래 처럼 경우에 따라 나눠주도록 한다.
  			int v = src.at<uchar>(j, i) + 100;
  			dst.at<uchar>(j, i) = v > 255 ? 255 : v < 0 ? 0 : v;

  			// 2. saturate_cast 함수 사용
  			dst.at<uchar>(j, i) = saturate_cast<uchar>(src.at<uchar>(j, i) + 100);
  		}
  	}
    ...
  }
  ```

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Brightness/picture/brightness2.png)

  ### 3. 평균 밝기 보정 프로그램
  - 입력 영상의 평균 밝기를 특정 조건으로 보정할 수 있다.
    - ex> 아래는 그레이스케일이 128이 되도록 보정
  - 평균 밝기 보정하는 방법
    - 루프를 돌려서 평균을 구하는 방법
    - OpenCV 함수를 이용한 방법

  ```cpp
  int main(int argc, char* argv[])
  {
  	Mat src;
  	if (argv[1]) {
  		src = imread(argv[1], IMREAD_GRAYSCALE);
  	}
  	else {
  		src = imread("lenna.bmp", IMREAD_GRAYSCALE);
  	}

  	Mat dst(src.rows, src.cols, src.type());

    // 방법 1
  	int s = 0;
  	for (int j = 0; j < src.rows; j++) {
  		for (int i = 0; i < src.cols; i++) {
  			s += src.at<uchar>(j, i);
  		}
  	}
  	int m1 = s / (src.rows * src.cols);

    // 방법 2
  	int m2 = sum(src)[0] / src.total(); // sum과 mean 은 scalar 값이므로 0번째를 가져온다.
    // 방법 3
  	int m3 = mean(src)[0];

  	dst = src + (128 - m3);

  	imshow("src", src);
  	imshow("dst", dst);

  	waitKey(0);
  	return 0;
  }
  ```

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Brightness/picture/brightness3.png)

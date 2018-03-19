# Inverse & Pixel Access
  - 영상의 반전(inverse)
  - 픽셀값 접근 방법 (with OpenCV)
  - 연산 시간 측정 방법 (with OpenCV)
  - (참고_pdf)OpenCV 프로젝트 템플릿 만들기

---

## 영상의 반전(Inverse)
  ### 1. 영상의 반전(inverse)이란?
  - 영상 내의 모든 픽셀 값을 각각 반전
  - 밝을 픽셀 → 어둡게 / 어두운 픽셀 → 밝게

  ### 2. 영상의 반전 수식 및 코드
  - 수식 : `dst(x,y) = 255 - src(x,y)`
  - int 와 Mat 값을 직접 빼는 것은 operator가 overloading 되어 있기 때문에 가능하다.
    - 즉, int 가 Scalar 타입으로 변하고 Mat 타입으로 변해서 같은 위치의 픽셀끼리 연산을 하도록 만든다.

  ```cpp
  Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	Mat dst;
	dst = 255 - src;

	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);

	return 0;
  ```

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master//Inverse%26PixelAccess/picture/inverse.png)

---

## 픽셀값 접근 방법
  ### 1. 행 단위 포인터 접근
  - `Mat::ptr()` 이용
  - 가장 빠르다

  ```cpp
  void inverse1(Mat& img)
  {
      for(int j = 0; j < img.rows; j++){
          uchar* p = img.ptr<uchar>(j);

          for(int i = 0; i < img.cols; i++){
              p[i] = 255 - p[i];
          }
      }
  }
  ```

  ### 2. 임의 접근 연산자 사용
  - `Mat::at()` 이용
  - 가장 직관적이다.

  ```cpp
  void inverse2(Mat& img)
  {
      for(int j =0; j< img.rows; j++) {
          for(int i=0; i < img.cols; i++){
              img.at<uchar>(j, i) = 255 - img.at<ucahr>(j, i);
          }
      }
  }
  ```

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master//Inverse%26PixelAccess/picture/access.png)

  ### 3. iterator 사용
  - `Matlterator_<T>` 이용
  - 거의 사용하지 않으므로 참고할 것

  ```cpp
  void inverse3(Mat& img)
  {
      MatIterator_<ucahr> it, end;
      for (it = img.begin<uchar>(), end = img.end<uchar>(); it != end; it++){
          *it = 255 - *it;
      }
  }
  ```

  ### 4. 픽셀값 접근 방법 시간 비교
  - `getTickCount();` 메소드를 이용하여 시간을 잴 수 있다.

  ```cpp
  int main(int argc, char* argv[])
  {
      Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

      int64 t1 = getTickCount();
      inverse1(src);
      int64 t2 = getTickCount();

      // ms 에 함수 실행 시간이 저장
      double ms = (t2 - t1) * 1000 / getTickFrequency();
  }
  ```

  - 결과

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master//Inverse%26PixelAccess/picture/time.png)

---

## (참고) OpenCV 프로젝트 템플릿 만들기
  ### 1. 프로젝트 템플릿이란?
  - 프로젝트 속성, 기본 소스 코드 등이 미리 설정된 프로젝트를 자동으로 샌성하는 기능
  - Visual Studio의 템플릿 내보내기 마법사를 통하여 Zip 파일로 패키징된 자신만의 템플릿 파일을 새성할 수 있음

  ### 2. OpenCV 프로젝트 템플릿이란?
  - OpenCV 기본 소스 코드, OpenCV 헤더 파일 디렉토리 및 라이브러리 파일 설정이 미리 설정되어 있는 프로젝트 템플릿
  - 프로젝트 생성만으로 디폴트로 특정 이미지 포함시키거나 코드를 미리 만들 수 있다.

  ### 3. 프로젝트 템플릿 만들기
  - [OpenCV 프로젝트 템플릿 만들기 링크](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Inverse%26PixelAccess/pdf/OpenCVtemplate.pdf) 참고

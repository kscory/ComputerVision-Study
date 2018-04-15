# Histogram
  - OpenCV API
    - 히스토그램 구하기 (calcHist)
    - 행렬의 최솟값/최댓값 & 해당 위치 구하기 (minMaxLoc)
    - Assert 매크로 함수
    - 히스토그램 평활화 함수 (equalizeHist)
  - 히스토그램 기본
  - 히스토그램 스트레칭
  - 히스토그램 평활화
  - 참고 - 히스토그램 스트레칭 vs 평활화

---

## OpenCV API
  ### 1. 히스토그램 구하기 (calcHist)

  ```cpp
  void cv::calcHist( const Mat * images,
                     int nimages,
                     const int * channels,
                     InputArray mask,
                     OutputArray hist,
                     int dims,
                     const int * histSize,
                     cosnt float ** ranges,
                     bool uniform = true,
                     bool accumulate = false

  );
  ```

  - `calcHist()` 함수는 여러개 영상의 히스토그램을 구할 수 있다.
  - `images` : 입력 영상의 배열
    - 모두 같은 깊이와 같은 크기를 가져야 한다. (ex> CV_8U, CV_16U, CV_32F)
  - `nimages` : 영상 배열의 갯수
  - `channels` : 히스토그램을 구할 채널을 나타내는 정수형 배열
    - 그레이에는 1개의 채널, color 에는 3 채널이 존재하는데 이를 지정하는 것!!
    - ex> 만약 image1은 R, image2 는 B 영상을 원한다면 {2,3} 을 대입
  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Histogram/picture/channel.png)
  - `mask` : 마스크 영상 (원소의 값이 0이 아닌 원소 위치에서 연산 수행)
    - __Mat()__ 혹은 __noArray()__ 를 지정하여 입력 영상 전체에서 히스토그램을 구할 수 있다.
  - `hist` : 출력되는 히스토그램 (dims-차우너 배열)으로 Mat or SparseMat
  - `dims` : 출력 히스토그램 차원
  - `histSize` : 히스토그램 각 차원의 크기
    - 각 차원의 `bin` 의 갯수를 나타내는 배열 (빈도수를 분류할 칸의 개수)
  - `ranges` : 히스토그램 각 차원의 최솟값과 최댓값을 원소로 갖는 배열의 배열 (uniform = true 인 경우)
  - `uniform` : `bin` 의 간격을 균등 분할할 지 결정
  - `accumulate` : 누적 플래그

  ### 2. 행렬의 최솟값/최댓값 & 해당 위치 구하기 (minMaxLoc)

  ```cpp
  void cv::minMaxLoc( InputArray src,
                      double * minVal,
                      double * maxVal = 0,
                      Point * minLoc = 0,
                      Point * maxLoc = 0,
                      InputArray mask = noArray()
  );
  ```

  - `src` : 입력 영상. 단일 채널
  - `minVal` / `maxVal` : 최솟값 / 최댓값 변수 포인터 (필요 없다면 NULL)
  - `minLoc` / `maxLoc` : 최솟값 / 최댓값 위치 변수 포인터 (필요 없다면 NULL)
  - `mask` : 행렬 일부분에서 최솟값/최댓값(위치) 를 구할 때 사용
    - 원소의 값이 0 이 아닌 부분에서만 연산을 수행

  ### 3. Assert 매크로 함수 (CV_Assert / CV_Dbg_Assert)

  ```cpp
  #define CV_Assert (expr) ...
  #define CV_Dbg_Assert (expr) ...
  ```

  - 실행 시 조건을 판단하여, 실패 시 에러를 발생
  - CV_Dbg_Assert() 매크로는 디버그 모드에서만 동작한다.

  ### 4. 히스토그램 평활화 함수(equalizeHist)

  ```cpp
  void cv::equalizeHist	(	InputArray src,
                          OutputArray dst
  )
  ```

  - 입력영상을 받아 출력영상에 평활화를 해주는 함수
  - 단 8비트 1채널 영상만 입력

---

## 히스토그램 기본
  ### 1. 히스토그램이란?
  - 영상의 픽셀 값 분포를 그래프의 형태로 표현
  - ex1> 그레이 스케일 값의 개수를 구하고 이를 막대 그래프로 나타냄
    - `h(g) = N_g`
  - ex2> 0\~3, 4\~7 등을 뭉쳐서 그 범위의 갯수를 구하고 그래프로 나타냄

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Histogram/picture/histogram.png)

  ### 2. 정규화된 히스토그램
  - 각 픽셀의 개수를 영상 전체 픽셀 개수로 나눈 것

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Histogram/picture/histogram1.png)

  - 해당 그레이 스케일 값을 갖는 피셀이 나타날 __확률__ 을 뜻함

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Histogram/picture/histogram2.png)

  ### 3. 영상과 히스토그램
  - 히스토그램을 보면 어떤 밝기가 어디서 사용되었는지를 알 수 있다.
  - 여러 영상에 따라 히스토그램이 다르게 나타난다.
    - __밝은 영상__ : 오른쪽으로 치우쳐짐
    - __어두운 영상__ : 왼쪽으로 치우쳐짐
    - __명암비가 높은 영상__ : 전체적으로 퍼져있음
    - __명암비가 낮은 영상__ : 가운데에 몰려 있음

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Histogram/picture/histogram3.png)

  ### 4. 구현
  - 먼저 hist 영상을 만들고
    - 그레이스케일 1 채널
    - 1차원 배열의 히스토그램
    - 빈도수는 256개로 분류
    - 범위는 0 에서 256 까지 지정
  - 그 뒤 grayscale 히스토그램 영상을 만들어서 반환 한다.
  - 직접 구현은 [코드](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Histogram/histogram/main.cpp) 참고

  ```cpp
  Mat histogram_2(const Mat& src) {
      // 1. hist 만들기
      CV_Assert(src.type() == CV_8U); // 이미지 타입이 다르다면 에러를 발생

      Mat hist;
      int channels[] = { 0 };
      int dims = 1;
      const int histSize[] = { 256 };
      float graylevel[] = { 0,256 };
      const float* ranges[] = { graylevel };

      calcHist(&src, 1, channels, Mat(), hist, dims, histSize, ranges);

      // 2. grayscale 히스토그램 영상 만들어서 반환
      CV_Assert(hist.type() == CV_32F);
      CV_Assert(hist.size() == Size(1, 256));

      // 최댓값을 구함
      double histMax;
      minMaxLoc(hist, 0, &histMax);

      Mat imgHist(100, 256, CV_8U, Scalar(255));

      for (int i = 0; i < 256; i++) {
          line(imgHist, Point(i, 100), Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)), Scalar(0));
      }

      return imgHist;
  }
  ```

---

## 히스토그램 스트레칭
  ### 1. 히스토그램 스트레칭이란?
  - 영상의 히스토그램이 그레이스케일 전 구간에서 걸쳐 나타나도록 변경하는 선형 변환 기법

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Histogram/picture/streching3.png)

  ### 2. 히스토그램 스트레칭 변환 함수 및 유도
  - 최소를 0으로, 최대를 255로 바꿔서 특정 비율을 각각 곱해준다.
  - 수식 (grayscale은 0 - 255 값을 가짐)

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Histogram/picture/streching1.png)


  - 아래 그림과 같이 직선의 방정식을 구해서 유도

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Histogram/picture/streching2.png)

  ### 3. 구현
  - 픽셀 접근하여 구하는 법은 [코드](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Histogram/streching/main.cpp) 참고

  ```cpp
  int main(void)
  {
      Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

      ...

      double gMax, gMin;
      minMaxLoc(src, &gMin, &gMax);

      Mat dst;
      // 히스토그램 스트레칭 이용
      dst = (src - gMin) / (gMax - gMin) * 255;

      imshow("src", src);
      imshow("dst", dst);

      waitKey(0);
      return 0;
  }
  ```

---

## 히스토그램 평활화(균등화, 평탄화)
  ### 1. 히스토그램 평활화란?
  - 히스토그램의 누적 분포 특성에 근거해서 히스토그램의 분포를 변경시키는 방법
  - 히스토그램 누적 분포 함수의 경우 직선과 거의 비슷해진다.

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Histogram/picture/equalization.png)

  ### 2. 히스토그램 평활화 변환 함수 및 계산 방법
  - 히스토그램 평활화 함수

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Histogram/picture/equalization2.png)

  - 평활화 계산 방법

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Histogram/picture/equalization3.png)

  ### 3. 구현
  - equalizeHist() 함수를 이용해 쉽게 구현 가능
  - 공식을 이용해 구하는 건 [코드](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Histogram/equalization/main.cpp) 참고

  ```cpp
  int main(void)
  {
      Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

      Mat dst(src.rows, src.cols, src.type());

      // equalizeHist 함수 이용
      equalizeHist(src, dst);
      imshow("src", src);
      imshow("dst", dst);

      waitKey(0);
      return 0;
  }
  ```

---

## 참고
  ### 1. 히스토그램 스트레칭 vs 히스토그램 평활화
  - 스트레칭의은 빈칸이 일정하지만 평활화는 빈칸이 균일하다.
  - (1) 번의 경우 평활화가 더 좋다
  - (2) 번의 경우 둘 다 별로다.
  - 보통 (1) 과 같이 평활화가 좋게 나타나는 경우가 많지만 (2) 와 같이 많이 안좋아질 때가 있다.
  - 반면 스트레칭의 경우는 좋을 때와 안좋을 때가 차이가 많이 나지 않는다.

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Histogram/picture/compare.png)

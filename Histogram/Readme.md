# Histogram
  - OpenCV API
    - 히스토그램 구하기 (calcHist)
    - 행렬의 최솟값/최댓값 & 해당 위치 구하기 (minMaxLoc)
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
  - `mask` : 마스크 영상 (원소의 값이 0이 아닌 원소 위치에서 연산 수행)
    - __Mat()__ 혹은 __noArray()__ 를 지정하여 입력 영상 전체에서 히스토그램을 구할 수 있다.
  - `hist` : 출력되는 히스토그램 (dims-차우너 배열)으로 Mat or SparseMat
  - `dims` : 출력 히스토그램 차원
  - `histSize` : 히스토그램 각 차원의 크기
    - 각 차원의 `bin` 의 갯수를 나타내는 배열
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

---

## 히스토그램 기본
  ### 1. 히스토그램이란?
  - 영상의 픽셀 값 분포를 그래프의 형태로 표현
  - ex1> 그레이 스케일 값의 개수를 구하고 이를 막대 그래프로 나타냄
    - `h(g) = N_g`
  - ex2> 0~3, 4~7 등을 뭉쳐서 그 범위의 갯수를 구하고 그래프로 나타냄

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Histogram/picture/histogram.png)

  ### 2. 정규화된 히스토그램
  - 각 픽셀의 개수를 영상 전체 픽셀 개수로 나눈 것

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Histogram/picture/histogram1.png)

  - 해당 그레이 스케일 값을 갖는 피셀이 나타날 __확률__ 을 뜻함

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Histogram/picture/histogram2.png)

  ### 3. 다양한 영상에 따른 히스토그램
  - ㅇㅇ

  ### 4. 구현
  - ㅇㅇ

---

## 히스토그램 스트레칭
  ### 1. 히스토그램 스트레칭이란?
  - ㅇㅇ

  ### 2. 히스토그램 스트레칭 변환 함수
  - ㅇㅇ

  ### 3. 구현
  - ㅇㅇ

---

## 히스토그램 평활화
  ### 1. 히스토그램 평활화란?
  - ㅇㅇ

  ### 2. 히스토그램 평활화 변환 함수 및 계산 방법
  - ㅇㅇ

  ### 3. 히스토그램 누적 분포 함수 비교
  - ㅇㅇ

  ### 4. 구현

---

## 참고
  ### 1. 히스토그램 스트레칭 vs 히스토그램 평활화
  - (1) 번의 경우 평활화가 더 좋다
  - (2) 번의 경우 둘 다 별로다.
  - 보통 (1) 과 같이 평활화가 좋게 나타나는 경우가 많지만 (2) 와 같이 많이 안좋아질 때가 있다.
  - 반면 스트레칭의 경우는 좋을 때와 안좋을 때가 차이가 많이 나지 않는다.

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Histogram/picture/compare.png)

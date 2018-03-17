# Basic Computer Vision 2
  - 영상의 표현 방법
  - 영상 파일 형식
  - 영상 처리 프로그래밍 기초

---

## 영상의 표현 방법
  ### 1. 그레이스케일(Gray Scale)과 트루컬러(True Color)
  - 픽셀(Pixel)
    - 영상의 기본 단위, 화소라고 불린다.
  - 그레이스케일(GrayScale) 영상
    - 색상 정보가 없이 오직 밝기 정보만으로 구성된 영상
    - 밝기 정보를 256 단계로 표현 (0 : 검정, 255 : 흰색)
    - C/C++ 에서 unsigned char 로 표현(1byte)

    ```cpp
    // unsigned char 로 표현한다
    typedef unsigned char uchar;
    typedef unsigned char BYTE;
    ```

  - 트루컬러(TrueColor) 영상
    - 컬러 사진처럼 색상 정보를 가지고 있어 다양한 색상 표현 가능
    - RGB 색상을 가지며 각각 모두 256 단계로 표현 (256³ 색상 표현 가능)
    - 0 : 해당 색상 성분이 없는 상태 / 255 : 해당 색상 성분이 가득찬 상태

  ### 2. 영상 좌표계와 픽셀값 분포
  - 영상에서 사용되는 좌표계
    - `w × h 영상` : w 가 가로, h 가 세로
    - `M × N 행렬` : M이 행, N 이 열
    - 두 가지 표현법에서 가로세로가 반대로 되어 있으므로 의사소통을 위해서는 어떤 좌표계를 사용했는지 반드시 설명이 필요하다.
  - 그레이스케일과 트루컬러 픽셀값 분포는 다음과 같이 표현할 수 있다.

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Basic%20ComputerVision2/picture/xy.png)

  ### 3. 함수로서의 영상
  - `z = f(x,y)` : (x,y) 좌표에서의 픽셀값을 z축 값으로 표현한다.
  - 3차원 등 형태학적 표현

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Basic%20ComputerVision2/picture/functionpx.png)

---

## 영상 파일 형식
  ### 1. 영상 파일 종류 및 특징
  - dd

  ### 2. 영상 파일 용량 비교
  - dd

  ### 3. 영상 파일 구조
  - dd

## 영상 처리 프로그래밍 기초
  ### 1. 2차원 배열의 생성 및 초기화
  - dd

  ### 2. 대용량 1차원 메모리 할당
  - ㅇㅇ

  ### 3. 영상 데이터 저장을 위한 영상 클래스 설계
  - ㅇㅇ
---

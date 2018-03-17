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
  - BMP
    - 데이터를 압축하지 않고 그대로 저장 (파일 용량이 큰 편)
    - 파일 구조가 간단해서 별도의 라이브러리 도움 없이 직접 파일 입출력 프로그래밍 가능
  - GIF
    - 256 이하의 색상을 가진 영상을 저장
    - 무손실 압축(lossless compression)
    - 움직이는 GIF 지원 (이것 빼고는 거의 사용하지 않음)
  - JPG
    - 트루컬러 영상을 저장하기 위해 사용
    - 손실 압축(lossy compression)
    - 압축률이 좋아서 파일 용량이 크게 감소 (디지털 카메라 사진포멧으로 주로 사용)
  - PNG
    - Portable Network Graphics
    - 트루컬러 영상을 포함하여 무손실 압축(lossless compression)을 수행

  ### 2. 영상 파일 용량 비교
  - 아래와 같이 BMP 파일의 경우 픽셀값이 동일하면 용량이 같음
  - 조금 색이 복잡할 수록 용량이 적게 감소하며 특히 JPG의 경우 크게 나타남

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Basic%20ComputerVision2/picture/formatcom.png)

  ### 3. 영상 파일 구조
  - 영상 파일 형식은 보통 헤더와 픽셀 데이터로 나뉜다.
  - 아래는 BMP 파일 구조의 예

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Basic%20ComputerVision2/picture/format2.png)

## 영상 처리 프로그래밍 기초
  ### 1. 2차원 배열의 생성 및 초기화
  - dd

  ### 2. 대용량 1차원 메모리 할당
  - ㅇㅇ

  ### 3. 영상 데이터 저장을 위한 영상 클래스 설계
  - ㅇㅇ
---

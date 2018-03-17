# OpenCV Setting
  - OpenCV 개요
  - OpenCV 설치 (pdf)
  - 프로젝트 설정 (pdf)
  - 비주얼 스튜디오 설치 (pdf)

---

## OpenCV 개요
  ### 1. OpenCV 란
  - 컴퓨터 비전 관련 알고리즘을 모아둔 오픈소스 라이브러리
  - 관련 사이트
    - [공식홈페이지](https://opencv.org/)
    - [document_공식 홈페이지](http://docs.opencv.org/master/)
    - [질문 사이트_공식 홈페이지](http://answers.opencv.org/questions/)
    - [깃헙 오픈소스 사이트](https://github.com/opencv/opencv/)
    - [Extra module 깃헙 (contrib)](https://github.com/opencv/opencv_contrib/)
    - [페이스북 페이지](https://www.facebook.com/opencvlibrary)

  ### 2. OpenCV 의 장점
  - 여러 인터페이스 존재 (C, C++, JAVA, Python, etc..)
  - 여러 플랫폼에 사용 가능(Windows, Linux, Mac OS, Android, IOS)
  - 유명하며 오픈소스로 되어 있고, 사용하기 편리
  - etc.....

  ### 3. OpenCV 주요 모듈
  - Algorithmic
    - core : 기본자료구조 및 연산함수
    - imgproc : 주요 영상처리 함수
    - video : 움직임추정, 특징추적, 전경추출
    - objdetect : 얼굴과 사람 검출기 등의 객체 검출기
    - ml : 기계학습
    - flann : 계산 기하학 알고리즘
    - photo : 계산사진학
    - 그외 다른 모듈 : features2d, calib3d,  dnn, stitching, superress, videostab, bgsegm,  optflow, xfeatures2d, etc..
  - GPU
    - cudaarithm, cudabgsegm, cudacodec, cudafeatures2d, cudafilters, cudaimgproc, cudalegacy, cudaobjdetect, cudaoptflow, cudastereo, cudawarping, T-API
  - Infrastructure
    - highgui (일부 사용자 인터페이스), world
    - python, java
    - ts, androidcamera

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Setting/picture/module.png)

  ### 4. OpenCV 구성
  - OpenCV 는 아래와 같이 구성되어 있다.
  - 출처 : https://opencv.org/wp-content/uploads/2013/icvs/ICVS2013%20-%20OpenCV%203.0.pdf

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Setting/picture/structure.png)

---

## OpenCV 설치
  ### 1. OpenCV 설치 및 프로젝트 설정 방법
  - [OpenCV 설치 및 프로젝트 설정 방법 ](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Setting/pdf/OpenCV%20install.pdf) 에서 확인 가능 (copyright by 패스트캠퍼스_황선규)

  ### 2. 주의사항 및 특이 사항
  - 소스코드 다운로드
    - 옵션 선택을 위해 소스 코드를 직접 다운받아 사용한다.
    - 설치경로는 임의로 정해도 되지만 실습에서는 파일에 나와 있는 대로 진행했다.
  - CMake 설치
    - CMake 설정에서 CUDA를 선택하면 시간이 오래걸릴 수 있다. (대략 8시간~9시간)
    - CMake 설정 시 모든 화면이 하얀색이 나오지 않는다면 [Generate] 버튼을 클릭하지 않도록 한다.
  - 빌드
    - 반드시 Debug 모드와 Release 모드에서 모두 빌드하도록 한다.
  - 환경 변수 등록
    - 환경 변수 등록 시 Path 를 시스템 변수에 등록하면 dll 파일을 찾지 못할 수도 있으니 주의
  - 프로젝트 설정
    - Visual Studio의 경우 `$(OPENCV_DIR)` 과 같이 주로 사용한다.
    - But> 일반적으로는 `%OPENCV_DIR%` 과 같이 "%" 를 이용한다.
    - debug 모드와 release 모드에서 lib 파일을 다르게 추가하는 것에 주의

---

## 참고
  ### 1. Visual Studio 설치
  - [Visual Studio 설치](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Setting/pdf/Visual%20Studio%20install.pdf) 에서 확인 가능 (copyright by 패스트캠퍼스_황선규)

  ### 2. Visual Studio 주요 단축키(C++ 개발 환경)
  - `F7` : 솔루션 빌드
  - `Ctrl + F5` : 디버그하지 않고 시작
  - `F9` : 중단점 설정 /해제
  - `F5` : 디버깅 시작
  - `Shift + F5` : 디버깅 중지
  - `F10` : 프로시저 단위 실행
  - `F11` : 한 단계씩 코드 실행
  - `Shift + F11` : 프로시저 나가기
  - `F12` : 정의로 이동

# Basic Computer Vision 1
  - 컴퓨터 비전 개요
  - 컴퓨터 비전 응용 분야

---

## 컴퓨터 비전 개요
  ### 1. 컴퓨터 비전과 영상처리
  - 컴퓨터 비전과 영상처리는 비슷하게 쓰이며 컴퓨터 비전이 조금 더 high-level 이라고 볼 수 있다.
    - 영상처리 : 영상 자체의 quality 를 높이기 위한 방법을 연구하는 학문
    - 컴퓨터 비전 : 영상에서부터 유용한 정보를 뽑아내는 기법을 연구하는 학문
  - 관점에 따라 아래와 같이 생각할 수 있다.
    - 유용한 정보 안에 quality 가 포함 vs quality가 높은 것에 유용한 정보 포함
    - 즉, 둘은 뗄 수 없는 관계에 있다고 생각할 수 있다.
  - ※ 여기서 영상은 video 가 아니라 video를 포함한 image와 관련된 모든 것들을 영상이라고 한다.

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Basic%20ComputerVision/picture/csip.png)

  ### 2. 컴퓨터 비전의 역사 및 관련분야
  - 컴퓨터 비전은 아날로그 방식에서 부터 최근에는 딥러닝에 이용되고 있다.
  - 컴퓨터 비전은 수학, 데이터 과학, 프로그래밍 등 다양한 분야와 연관되어 있다.

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Basic%20ComputerVision/picture/history.png)

  ### 3. 컴퓨터 비전과 휴먼 비전
  - 아래 그림의 경우와 같이 컴퓨터 비전과 휴면비전은 여러 환경에 의해 차이가 있다.
  - 첫번째 그림
    - 사람 : 착시현상으로 인해 A와 B 가 다르다고 인식한다.
    - 컴퓨터 : 같은 색으로 인지하며 같은 값을 출력한다.
  - 두번째 그림
    - 사람 : 위를 보면 아래가 색상이 다르다고 인식(반대도 동일)
    - 컴퓨터 : 같은 색으로 인지한다.

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Basic%20ComputerVision/picture/cvhv.png)

---
## 컴퓨터 비전 응용 분야
  ### 1. 영상의 화질 개선
  - 카메라로 찍은 사진을 더욱 선명하게 하거나 색상을 원하는 형태로 변경하는 작업
  - ex> HDR(High Dynamic Range), 인스타그램의 필터, 잡음 제거 등

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Basic%20ComputerVision/picture/imagepix.png)

  ### 2. 얼굴 검출 및 얼굴 인식
  - 얼굴 검출(face detection)
    - 주어진 영상에서 얼굴의 위치 혹은 크기를 찾는 작업
    - ex> 카메라에서 얼굴을 찾아 초점을 맞춰주는 것
  - 얼굴 인식(face recognition)
    - 얼굴을 보고 누구인지 판별(얼굴 검출보다 어려우며 다양한 표정을 감지해야 함)
    - ex> 페이스북 딥 페이스, 구글 포토, MS Cognitive Face API

  

# Contrast
  - dd

---

## 명암비 조절 기본
  ### 1. 명암비란?
  - 밝은 곳과 어두운 곳 사이에 드러나는 밝기 정도의 차이
  - 대부분의 명암비는 높이려고 하는 경우가 많다.
  - 컨트라스트, 대비
  - 예시

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Contrast/picture/contrast.png)

  ### 2. 기본 명암비 조절 방법
  - `g(x,y) = s * f(x,y)`
  - 기본적인 방법은전체적으로 어두워지거나, 전체적으로 밝아지는 문제가 생길 수 있다. 또한 saturate 되는 경우도 많다.

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Contrast/picture/contrast1.png)

  ### 3. 중심을 이용한 명암비 조절 방법
  - `g(x, y) = f (x, y) + ( f (x, y) * 128) * α`
  - 밝기의 중심인 128을 기준으로 명암비를 조절
  - 두 가지 방법으로 코딩 가능
    - Mat 연산자 재정의
    - 픽셀 접근 방법
  - 그러나 대부분의 픽셀이 밝은쪽에 모두 있거나 어두워진쪽에 있다면 보기 힘들어지는 경우가 생긴다. (따라서 평균 밝기를 이용)

  ```cpp
  int main(int argc, char* argv[])
  {
  	Mat src = imread(argv[1], IMREAD_GRAYSCALE);

  	float alpha = 1.5f;
  	Mat dst;

  #if 0
  	// Mat 연산자 재정의 사용
  	dst = src + (src - 128)*alpha; // 공식 이용
  #else
  	// Mat 픽셀 포인터 연산 사용
  	dst = Mat::zeros(src.rows, src.cols, src.type());

  	for (int j = 0; j < src.rows; j++) {
  		uchar* pSrc = src.ptr<uchar>(j);
  		uchar* pDst = dst.ptr<uchar>(j);
  		for (int i = 0; i < src.cols; i++) {
  			// 공식 이용
  			pDst[i] = saturate_cast<uchar>(pSrc[i] + (pSrc[i] - 128)*alpha);
  		}
  	}
  #endif
      ...
  }
  ```

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Contrast/picture/contrast2.png)

  ### 4. 평균 밝기를 고려한 명암비 조절 방법
  - 영상의 평균 밝기 m 을 구하고 (m,m)을 지나는 직선을 변환 함수로 사용
  - `g(x, y) = f (x, y) + ( f (x, y) - m) * α`

  ```cpp
  int main(int argc, char* argv[])
  {
  	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

      ...

  	float alpha = 1.5f;

  	// 평균 밝기를 고려한 명암비 조절
  	int m = mean(src)[0];
  	Mat dst = src + (src - m)*alpha; // 풀면 src * (1+alpha) - m * alpha 와 동일

      ...
  }
  ```

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Contrast/picture/contrast3.png)

---
## 참고
  ### 1. 중심 고려 vs 평균 밝기 고려
  - 아래와 같이 나올 수 있다.

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Contrast/picture/contrast4.png)

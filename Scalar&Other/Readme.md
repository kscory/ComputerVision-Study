# Scalar 클래스와 다른 클래스들
  - Scalar 클래스
  - InputArray & OutputArray 클래스
  - 기타 자료형
    - Point_ 클래스
    - Size_ 클래스
    - Rect_ 클래스

---

## Scalar 클래스
  ### 1. Scalar 클래스란?
  - Scalar_ 클래스는 Vec 클래스에서 상속받은 4개의 요소를 갖는 템플릿 클래스
  - Scalar 클래스는 4개의  double형 데이터를 갖는 자료형

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Scalar%26Other/picture/scalar.png)

  ### 2. 예제

  ```cpp
  Scalar gray = 128;
	cout << "gray: " << gray << endl;

	Scalar yellow(0, 255, 255);
	cout << "yellow: " << yellow << endl;

  // data의 기본형태로 넣을 수 있다.
	Mat img1(256, 256, CV_8UC3, yellow);

	for (int i = 0; i < 4; i++)
    // val을 통해서 값을 호출 가능
		cout << yellow.val[i] << ", " << yellow[i] << endl;
  ```

  - 결과

  ![](https://github.com/Lee-KyungSeok/ComputerVision-Study/blob/master/Scalar%26Other/picture/scalar2.png)

---

## InputArray & OutputArray 클래스
  ### 1. InputArray 클래스

  ```cpp
  typedef const _InputArray& InputArray;
  typedef InputArray InputArrayOfArrays;
  ```

  - OpenCV 함수에서 입력 인자로 자주 사용
  - 주로 Mat 클래스를 대체하는 proxy class
  - 주로 Mat 타입을 전달하고, Mat_<T>, Matx<T,m,n>, vector<T> 등 다양한 타입 전달 가능
  - 함수의 인자에 비어 있는 행렬을 전달할 경우에는 noArray() 또는 Mat() 전달
  - ※ 사용자가 명시적으로 \_InputArray 클래스의 인스턴스 또는 변수를 생성하여 사용하는 것은 금지!!

  ### 2. OutputArray 클래스

  ```cpp
  typedef const _OutputArray& OutputArray;
  typedef OutputArray OutputArrayOfArrays;
  ```

  - OpenCV 함수에서 출력 인자로 자주 사용
  - \_OutputArray 클래스는 \_InputArray 크래스를 상속받아 만들어 졌으며, 새로운 행렬을 생성하는 create() 같은 함수가 추가적으로 정의되어 있음

---

## 기타 자료형
  ### 1. Point_ 클래스
  - ㅇㅇ

  ### 2. Size_ 클래스
  - ㅇㅇ

  ### 3. Rect_ 클래스
  - ㅇㅇ

---

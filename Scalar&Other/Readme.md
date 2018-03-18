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

  ```cpp
  template<typename _Tp> class Point_
  {
  public :
      /*...*/
      _Tp x, y; // < the point coordinates
  };

  typedef Point_<int>    Point2i ;
  typedef Point_<int64>  Point2l ;
  typedef Point_<float>  Point2f ;
  typedef Point_<double> Point2d ;
  typedef Point2i        Point;
  ```

  - 2차원 점의 좌표 표현을 위한 템플릿 클래스
  - 멤버변수 : `x`, `y`
  - 멤버 함수 : `dot()`, `ddot()`, `cross()`, `inside()` 등
  - 다양한 사칙 연산에 대한 연산자 재정의가 되어 있음
  - 여기서 template 으로 정의되어 있기 때문에 타입을 정해주어야 한다. (타입을 미리 지정해 놓았기 때문에 두가지 방법으로 사용 가능)
    - `Point_<float> p;` 혹은 `Point2f p;` 으로 선언
    - `p.x = 100.5f; p.y = 200.3f;` 로 값을 넣는다

  ### 2. Size_ 클래스

  ```cpp
  template<typename _Tp> class Size_
  {
  public :
      /*...*/
      _Tp width, height; // < the width and the height
  };

  typedef Size_<int>    Size2i ;
  typedef Size_<int64>  Size2l ;
  typedef Size_<float>  Size2f ;
  typedef Size_<double> Size2d ;
  typedef Size2i        Size;
  ```

  - 영상 또는 사각형의 크기 표현을 위한 템플릿 클래스
  - 멤버 변수 : `width`, `height`
  - 멤버 함수 : `area()`
  - 다양한 사칙 연산에 대한 연산자 재정의가 되어 있음

  ### 3. Rect_ 클래스

  ```cpp
  template<typename _Tp> class Rect_
  {
  public :
      /*...*/
      _Tp x, y, width, height;
  };

  typedef Rect_<int>    Rect2i ;
  typedef Rect_<float>  Rect2f ;
  typedef Rect_<double> Rect2d ;
  typedef Rect2i        Rect;
  ```

  - 2차원 사각형 표현을 위한 템플릿 클래스
  - 멤버 변수 : `x`, `y`, `width`, `height`
  - 멤버 함수 : `tl()`, `br()`, `size()`, `area()`, `contains()`
  - 다양한 사칙 연산에 대한 연산자 재정의가 되어 있음

---

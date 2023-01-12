#include <iostream>
#include <string>	// 문자열 관련 라이브러리
#include <array>	// 배열의 사이즈를 가져오기 위한 라이브러리

using namespace std; // C++ 표준 라이브러리를 사용한다.


struct Rectangle {
	int width;
	int height;
};

struct Fruit
{
	string name;
	int count;
};


int main() {

	// 배열 (Array)는 같은 자료형을 여러 개 저장할 수 있는 자료형
	// 다음과 같은 변수가 있다고 가정하자.

	int score0;
	int score1;
	int score2;
	// ...

	// 이런 비효율적인 변수 선언 ! ! 
	// 배열을 통해 쉽고 효율적으로 작업해보자.

	int score[30]; // 자료형 배열명[배열 길이];
	// int 타입을 여러 개 저장할 수 있는 자료형 배열로 선언. 
	// 요소를 30개 초기화한다.
	// 대괄호 [] = 배열 변수에 할당할 배열 길이
	// 소괄호 (), 중괄호 {}, 대괄호 [], 각괄호 <>

	// 배열에 있는 각 변수를 요소(element)라고 합니다.
	// 요소에는 고요한 이름이 존재하지 않습니다. 
	// 배열의 개별 요소에 접근하려면 배열 이름을 하위 연산자 ([])와 함꼐 사용하며
	// 원하는 요소를 알려주는 인덱스(index)라는 매개 변수를 사용한다.

	// 프로그래밍 언어에서 숫자는 0부터 시작
	// string 타입을 여러 개 저장할 수 있는 names라는 이름의 배열 변수를 선언.
	// 사이즈는 5로 지정해서 초기화를 함.
	string names[5];
	names[0] = "John";
	names[1] = "Jane";
	names[2] = "Tom";
	names[3] = "Smith";
	names[4] = "James";

	cout << "for문 : " << endl;
	for (int i = 0; i < size(names); i++) // (1) sizeof가 아니라 size임...
	{
		cout << names[i] << " ";
	}
	cout << endl;
	cout << endl;

	cout << "foreach문 : " << endl;
	for (string name : names) // (2) foreach문 작성법
	{
		cout << name << " ";
	}

	cout << endl;
	cout << endl;
	

	/////////////////////////////////////////////////////////////////
	// 모든 자료형을 배열로 만들 수 있음.
	// 구조체도 배열로 만들어보자.
	// Rectangle이라는 이름의 구조체를 상단에 정의.

	Rectangle rectangles[5];
	rectangles[0].width = 20;
	rectangles[0].height = 10;
	rectangles[1].width = 20;
	rectangles[1].height = 10;
	rectangles[2].width = 22;
	rectangles[2].height = 30;
	rectangles[3].width = 55;
	rectangles[3].height = 60;

	rectangles[10].width = 20; // 빌드는 되는데 이러지 마셈여
	rectangles[10].height = 10;

	cout << "for문 : " << endl;
	for (int i = 0; i < size(rectangles); i++) // (2) foreach문 작성법
	{
		cout << "width : " << rectangles[i].width << ", height : " << rectangles[i].height << endl;
	}
	cout << endl;


	cout << "foreach문 : " << endl;
	for (Rectangle rec : rectangles)
	{
		cout << "width : " << rec.width << ", height : " << rec.height << endl;
	}
	cout << endl;

	/////////////////////////////////////////////////////////////////
	// 고정 배열(fixed array)을 선언할 때 배열의 길이는 컴파일 타임 상수여야 한다.
	// 상수(constant)란?
	//  값이 변하지 않는 것
	//  상수에 넣는 Data로는 숫자뿐 아니라 Class나 struct 같은 객체도 올 수 있다 ! ! ! ! !!!!
	// 정말 그럴까? 테스트를 위해서 구조체를 정의해보자.

	Fruit fruit1 = {"Apple", 10};
	fruit1.name = "Banana";
	fruit1.count = 30;

	const Fruit fruit2 = { "Apple", 20 };
	// fruit2.name = "Banana";
	// fruit2.count = 30;
	// 구조체 안의 변수들의 값을 상수화했기 때문에 에러가 난다.

	
	// 리터럴(Literal)이란?
	// 데이터(값) 그 자체를 의미한다.
	// 즉 변수에 넣는 변하지 않는 데이터를 의미한다.

	const int intValue1 = 1;
	// intValue1은 상수 변수, 1은 리터럴 값
	const string stringValue1 = "Jane";
	// stringValue1은 상수 변수, "Jane"은 리터럴 값 

	
	/////////////////////////////////////////////////////////////////
	// 고정 배열을 선언하는 방법 4가지
	// 1. 리터럴 상수를 이용한다.
	int intArr1[5];

	// 2. 매트로 기호 상수를 사용한다.
#define ARRAY_LENGTH 5
	int intArr2[ARRAY_LENGTH];

	// 3. 상수 변수를 사용
	const int arrayLength = 5;
	int intArr3[arrayLength];

	// 4. 열거형을 사용한다.
	enum EArrayLength {MaxArrayLength = 10};
	int intArr4[EArrayLength:: MaxArrayLength];

	/////////////////////////////////////////////////////////////////
	// 좋지 않은 예
	// 1. 비상수 변수 사용
	int arrayLength1 = 10;
	// int intArr5[arrayLength1];

	// 2. 런타임 상수 변수 사용
	// arrayLength3 값은 컴파일 타임에서는 알 수 없으므로 런타임 상수이다. 
	int arrayLength2 = 5;
	const int arrayLength3 = arrayLength2;
	

	/////////////////////////////////////////////////////////////////
	// 배열은 선언과 동시에 초기값을 줄 수 있다.
	// 일부만 초기화해도 됨. 나머지는 기본값으로 채워진다.
	string friend1[5] = { "John", "Tom", "Jane", "Smith", "James" };
	int intArr7[10] = {10, 20};

	cout << "intArr7 : ";

	for (int i : intArr7)
	{
		cout << i << " ";
	}

	cout << endl;
	cout << endl;

	// 요소의 개수로 사이즈를 알 수 있기 때문에 사이즈를 명시하지 않아도 됨
	string friend2[] = { "John", "Tom", "Jane", "Smith", "James" };


	// 대입 연산자 없이도 배열 선언 및 초기화 가능
	int intArr8[3]{ 10, 20, 30 };
	cout << "intArr 8 : ";
	for (int i : intArr8)
	{
		cout << i << " ";
	}

	cout << endl;
	cout << endl;
	
	
	// 보통 C언어 스타일로 사용하는데
	// C++ 스타일로 사용할 수도 있긴 함. 잘 안 씀
	array<int, 5> intArr14 = { 1, 2, 3, 4, 5 };

	cout << "intArr14 : ";

	for (int i : intArr14)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << endl;



}
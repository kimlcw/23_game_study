#include <iostream>
#include <string>

using namespace std;


int main() {

	// 포인터 : 주소를 저장하는 변수
	// 일반적인 변수는 데이터를 저장하는 데 반하여 포인터는 메모리 공간의 주소를 저장한다.
	// 포인터 변수가 주소를 저장하려면 변수의 주소를 알아야겠지!!1

	// 1. 변수 이름 앞에 앰퍼샌트(주소 연산자, &)를 붙이면 해당 변수의 "시작" 주소를 가리킴.
	// 2. 포인터 변수가 저장하는 변수의 주소에 저장된 값을 참조하려면 *(역참조 연산자)를 사용하면 됨.

	// int 포인터 타입의 intPtr이라는 이름의 포인터 변수 선언
	// 포인터 변수가 당장 대상이 없으면 nullptr을 대입해 초기화를 하자.

	int* intPtr1 = nullptr;
	int intValue1 = 10;
	intPtr1 = &intValue1;

	cout << "intValue1의 주소값 : " << &intValue1 << endl;
	cout << "intValue1의 값 : " << intValue1 << endl;

	cout << "intPtr1에 저장된 값 : " << intPtr1 << endl;
	cout << "intPtr1의 주소값 : " << &intPtr1 << endl;
	cout << "intPtr1 주소에 담긴 값 : " << *intPtr1 << endl;

	// 실제 하드웨어 RAM의 값에 접근하기 때문에 속도가 빠르다.


	// 포인터와 배열의 관계는 무엇일까?
	// 배열 이름은 배열의 주소를 반환한다 (X)
	// 배열 이름은 배열의 시작 주소를 반환한다 (O)
	// 배열 이름은 배열의 0번째 인덱스값의 주소를 반환한다. (O)
	// Arr == &Arr[0]

	// Arr + i는 Arr이 포인터이므로 배열 시작 주소에 i 배열요소의 크기가 더해진다.
	// 따라서 Arr + i == &Arr[i]
	// *(Arr + i) == Arr[i]
	 
	int intArr1[] = { 10, 20, 30, 40, 50 };

	cout << "intArr1[0] address : " << intArr1 << endl;
	cout << "intArr1[0] address : " << &intArr1[0] << endl;

	cout << "intArr1[1] address : " << intArr1 + 1 << endl;
	cout << "intArr1[1] address : " << &intArr1[1] << endl;

	cout << "intArr1[0] value : " << *intArr1 << endl;
	cout << "intArr1[0] value : " << intArr1[0] << endl;

	cout << "intArr1[1] value : " << *(intArr1 + 1) << endl;
	cout << "intArr1[1] value : " << intArr1[1] << endl;

	cout << endl;
	cout << endl;

}
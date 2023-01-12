#include <iostream>
#include <string>

using namespace std;


int main() {

	// ������ : �ּҸ� �����ϴ� ����
	// �Ϲ����� ������ �����͸� �����ϴ� �� ���Ͽ� �����ʹ� �޸� ������ �ּҸ� �����Ѵ�.
	// ������ ������ �ּҸ� �����Ϸ��� ������ �ּҸ� �˾ƾ߰���!!1

	// 1. ���� �̸� �տ� ���ۻ�Ʈ(�ּ� ������, &)�� ���̸� �ش� ������ "����" �ּҸ� ����Ŵ.
	// 2. ������ ������ �����ϴ� ������ �ּҿ� ����� ���� �����Ϸ��� *(������ ������)�� ����ϸ� ��.

	// int ������ Ÿ���� intPtr�̶�� �̸��� ������ ���� ����
	// ������ ������ ���� ����� ������ nullptr�� ������ �ʱ�ȭ�� ����.

	int* intPtr1 = nullptr;
	int intValue1 = 10;
	intPtr1 = &intValue1;

	cout << "intValue1�� �ּҰ� : " << &intValue1 << endl;
	cout << "intValue1�� �� : " << intValue1 << endl;

	cout << "intPtr1�� ����� �� : " << intPtr1 << endl;
	cout << "intPtr1�� �ּҰ� : " << &intPtr1 << endl;
	cout << "intPtr1 �ּҿ� ��� �� : " << *intPtr1 << endl;

	// ���� �ϵ���� RAM�� ���� �����ϱ� ������ �ӵ��� ������.


	// �����Ϳ� �迭�� ����� �����ϱ�?
	// �迭 �̸��� �迭�� �ּҸ� ��ȯ�Ѵ� (X)
	// �迭 �̸��� �迭�� ���� �ּҸ� ��ȯ�Ѵ� (O)
	// �迭 �̸��� �迭�� 0��° �ε������� �ּҸ� ��ȯ�Ѵ�. (O)
	// Arr == &Arr[0]

	// Arr + i�� Arr�� �������̹Ƿ� �迭 ���� �ּҿ� i �迭����� ũ�Ⱑ ��������.
	// ���� Arr + i == &Arr[i]
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
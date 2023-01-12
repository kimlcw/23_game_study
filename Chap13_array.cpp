#include <iostream>
#include <string>	// ���ڿ� ���� ���̺귯��
#include <array>	// �迭�� ����� �������� ���� ���̺귯��

using namespace std; // C++ ǥ�� ���̺귯���� ����Ѵ�.


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

	// �迭 (Array)�� ���� �ڷ����� ���� �� ������ �� �ִ� �ڷ���
	// ������ ���� ������ �ִٰ� ��������.

	int score0;
	int score1;
	int score2;
	// ...

	// �̷� ��ȿ������ ���� ���� ! ! 
	// �迭�� ���� ���� ȿ�������� �۾��غ���.

	int score[30]; // �ڷ��� �迭��[�迭 ����];
	// int Ÿ���� ���� �� ������ �� �ִ� �ڷ��� �迭�� ����. 
	// ��Ҹ� 30�� �ʱ�ȭ�Ѵ�.
	// ���ȣ [] = �迭 ������ �Ҵ��� �迭 ����
	// �Ұ�ȣ (), �߰�ȣ {}, ���ȣ [], ����ȣ <>

	// �迭�� �ִ� �� ������ ���(element)��� �մϴ�.
	// ��ҿ��� ����� �̸��� �������� �ʽ��ϴ�. 
	// �迭�� ���� ��ҿ� �����Ϸ��� �迭 �̸��� ���� ������ ([])�� �Բ� ����ϸ�
	// ���ϴ� ��Ҹ� �˷��ִ� �ε���(index)��� �Ű� ������ ����Ѵ�.

	// ���α׷��� ���� ���ڴ� 0���� ����
	// string Ÿ���� ���� �� ������ �� �ִ� names��� �̸��� �迭 ������ ����.
	// ������� 5�� �����ؼ� �ʱ�ȭ�� ��.
	string names[5];
	names[0] = "John";
	names[1] = "Jane";
	names[2] = "Tom";
	names[3] = "Smith";
	names[4] = "James";

	cout << "for�� : " << endl;
	for (int i = 0; i < size(names); i++) // (1) sizeof�� �ƴ϶� size��...
	{
		cout << names[i] << " ";
	}
	cout << endl;
	cout << endl;

	cout << "foreach�� : " << endl;
	for (string name : names) // (2) foreach�� �ۼ���
	{
		cout << name << " ";
	}

	cout << endl;
	cout << endl;
	

	/////////////////////////////////////////////////////////////////
	// ��� �ڷ����� �迭�� ���� �� ����.
	// ����ü�� �迭�� ������.
	// Rectangle�̶�� �̸��� ����ü�� ��ܿ� ����.

	Rectangle rectangles[5];
	rectangles[0].width = 20;
	rectangles[0].height = 10;
	rectangles[1].width = 20;
	rectangles[1].height = 10;
	rectangles[2].width = 22;
	rectangles[2].height = 30;
	rectangles[3].width = 55;
	rectangles[3].height = 60;

	rectangles[10].width = 20; // ����� �Ǵµ� �̷��� ������
	rectangles[10].height = 10;

	cout << "for�� : " << endl;
	for (int i = 0; i < size(rectangles); i++) // (2) foreach�� �ۼ���
	{
		cout << "width : " << rectangles[i].width << ", height : " << rectangles[i].height << endl;
	}
	cout << endl;


	cout << "foreach�� : " << endl;
	for (Rectangle rec : rectangles)
	{
		cout << "width : " << rec.width << ", height : " << rec.height << endl;
	}
	cout << endl;

	/////////////////////////////////////////////////////////////////
	// ���� �迭(fixed array)�� ������ �� �迭�� ���̴� ������ Ÿ�� ������� �Ѵ�.
	// ���(constant)��?
	//  ���� ������ �ʴ� ��
	//  ����� �ִ� Data�δ� ���ڻ� �ƴ϶� Class�� struct ���� ��ü�� �� �� �ִ� ! ! ! ! !!!!
	// ���� �׷���? �׽�Ʈ�� ���ؼ� ����ü�� �����غ���.

	Fruit fruit1 = {"Apple", 10};
	fruit1.name = "Banana";
	fruit1.count = 30;

	const Fruit fruit2 = { "Apple", 20 };
	// fruit2.name = "Banana";
	// fruit2.count = 30;
	// ����ü ���� �������� ���� ���ȭ�߱� ������ ������ ����.

	
	// ���ͷ�(Literal)�̶�?
	// ������(��) �� ��ü�� �ǹ��Ѵ�.
	// �� ������ �ִ� ������ �ʴ� �����͸� �ǹ��Ѵ�.

	const int intValue1 = 1;
	// intValue1�� ��� ����, 1�� ���ͷ� ��
	const string stringValue1 = "Jane";
	// stringValue1�� ��� ����, "Jane"�� ���ͷ� �� 

	
	/////////////////////////////////////////////////////////////////
	// ���� �迭�� �����ϴ� ��� 4����
	// 1. ���ͷ� ����� �̿��Ѵ�.
	int intArr1[5];

	// 2. ��Ʈ�� ��ȣ ����� ����Ѵ�.
#define ARRAY_LENGTH 5
	int intArr2[ARRAY_LENGTH];

	// 3. ��� ������ ���
	const int arrayLength = 5;
	int intArr3[arrayLength];

	// 4. �������� ����Ѵ�.
	enum EArrayLength {MaxArrayLength = 10};
	int intArr4[EArrayLength:: MaxArrayLength];

	/////////////////////////////////////////////////////////////////
	// ���� ���� ��
	// 1. ���� ���� ���
	int arrayLength1 = 10;
	// int intArr5[arrayLength1];

	// 2. ��Ÿ�� ��� ���� ���
	// arrayLength3 ���� ������ Ÿ�ӿ����� �� �� �����Ƿ� ��Ÿ�� ����̴�. 
	int arrayLength2 = 5;
	const int arrayLength3 = arrayLength2;
	

	/////////////////////////////////////////////////////////////////
	// �迭�� ����� ���ÿ� �ʱⰪ�� �� �� �ִ�.
	// �Ϻθ� �ʱ�ȭ�ص� ��. �������� �⺻������ ä������.
	string friend1[5] = { "John", "Tom", "Jane", "Smith", "James" };
	int intArr7[10] = {10, 20};

	cout << "intArr7 : ";

	for (int i : intArr7)
	{
		cout << i << " ";
	}

	cout << endl;
	cout << endl;

	// ����� ������ ����� �� �� �ֱ� ������ ����� ������� �ʾƵ� ��
	string friend2[] = { "John", "Tom", "Jane", "Smith", "James" };


	// ���� ������ ���̵� �迭 ���� �� �ʱ�ȭ ����
	int intArr8[3]{ 10, 20, 30 };
	cout << "intArr 8 : ";
	for (int i : intArr8)
	{
		cout << i << " ";
	}

	cout << endl;
	cout << endl;
	
	
	// ���� C��� ��Ÿ�Ϸ� ����ϴµ�
	// C++ ��Ÿ�Ϸ� ����� ���� �ֱ� ��. �� �� ��
	array<int, 5> intArr14 = { 1, 2, 3, 4, 5 };

	cout << "intArr14 : ";

	for (int i : intArr14)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << endl;



}
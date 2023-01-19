#include <iostream>

/** ���ڿ� ���� ���̺귯��*/
#include <string>

/** C++ ǥ�� ���̺귯���� ����մϴ�. */
using namespace std;

/**
������ ���� ���� ����� const�����ڷ� �����ϸ� "�ӽú���"�� ����鼭 ������ �����մϴ�.
�׷��ٸ� �� ���� const �����ڱ��� ����ϸ鼭 ����� �����ұ��?
�׽�Ʈ�� ���ؼ� Add() �Լ��� ������ �ֵ��� �մϴ�.
*/
/** const �������� �Ű������� ������ �ֽ��ϴ�. */
int Add(const int& value1, const int& value2)
{
    return value1 + value2;
}

/**
���࿡ const �����ڰ� ���ٸ�?
�Լ��� �߰��� �ݴϴ�.
*/
/** ��-��� �������� �Ű� ������ ������ �ֽ��ϴ�. */
int Add(int& value1, int& value2)
{
    return value1 + value2;
}

class Sample
{
private:
    string apple;
    string banana;
public:
    /** const�� �Ű� ������ ������ �Ű� ������ ���� �������� ���մϴ�. */
    void ConstParameter(const int intValue)
    {
        // intValue = 200; // (X)
    }
    /** const�� �Լ� ���� ������ ��� ������ ���� �������� ���մϴ�. */
    void ConstFunction() const
    {
        // apple = "Apple"; // (X)
    }
};

int main()
{
    /**
    �����Ͷ�?
    �����ʹ� �ּҸ� �����ϴ� �����Դϴ�.
    �Ϲ����� ������ �����͸� �����ϴµ� ���Ͽ� �����ʹ� �޸� ������ �ּҸ� �����մϴ�.
    ������ ������ �ּҸ� �����Ϸ��� ������ �ּҸ� �˾ƾ� �ϴµ�
    1. ���� �̸� �տ� &(�ּ� ������) �����ڸ� ���̸� �ش� ������ ���� �ּҸ� ��ȯ�մϴ�.
    2. ������ ������ �����ϴ� ������ �ּҿ� ����� ���� �����Ϸ��� *(������ ������) �����ڸ� ����մϴ�.
    */

    /** int������ Ÿ���� intPtr1�̶�� �̸��� ������ �����ϰ� nullptr���� intPtr1 ������ ������ �����߽��ϴ�. */
    int* intPtr1 = nullptr;

    int intValue1 = 10;
    /** intValue1������ �ּҰ��� intPtr1������ ������ �����߽��ϴ�. */
    intPtr1 = &intValue1;
    /** intValue1 ������ �ּҰ�*/
    cout << "intValue1 address : " << &intValue1 << endl;
    /** intPtr1 ������ ������ �ּҰ�*/
    cout << "intPtr1 address : " << intPtr1 << endl;
    /** intPtr1 ������ ������ �ּҰ�*/
    cout << "intPtr1 address : " << &intPtr1 << endl;
    /** intPtr1 ������ ������ ����Ű�� ��*/
    cout << "intPtr1 value : " << *intPtr1 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    �����Ϳ� �迭�� ���迡 ���ؼ� �˾ƺ����� �մϴ�.
    ������ �߰��� �ݴϴ�.
    */

    /**
    int Ÿ���� ������ ������ �� �ִ� �迭Ÿ������ intArr1�̶�� �̸��� ������ �����߽��ϴ�.
    10, 20, 30, 40, 50�� ���� intArr1 �迭�� ���������ν� �ʱ�ȭ �߽��ϴ�.
    */
    int intArr1[] = { 10, 20, 30, 40,50 };

    /**
    �����Ϳ� �迭�� ���� ������ ���踦 ������ �ֽ��ϴ�.
    �迭 �̸��� �迭�� ���� �ּҸ� ��ȯ�մϴ�.
    �迭 �̸��� �迭�� 0��° �ε������� �ּҸ� ��ȯ�մϴ�.
    intArr1 �� & intArr1[0]    intArr1�� 0��° �ε����� �ּҰ� �Դϴ�.

    �迭 �̸��� �����Ͷ� �����ϰ� intArr1�� ����� ���� intArr1[0]�� ��µ˴ϴ�.
    ���� intArr1 + i�� intArr1�� �������̹Ƿ� �迭 ���� �ּҿ�(i �迭����� ũ��)�� �������ϴ�.
    ���� intArr1 + i �� & intArr1[i]�� ����
    * (intArr1 + i)�� intArr1[i]�� ������ �����մϴ�.
     */

    cout << "intArr1[0] address : " << intArr1 << endl;
    cout << "intArr1[0] address : " << &intArr1[0] << endl;

    cout << "intArr1[1] address : " << intArr1 + 1 << endl;
    cout << "intArr1[1] address : " << &intArr1[1] << endl;

    cout << "intArr1[0] value : " << intArr1 << endl;
    cout << "intArr1[0] value : " << intArr1[0] << endl;

    cout << "intArr1[1] value : " << *(intArr1 + 1) << endl;
    cout << "intArr1[1] value : " << intArr1[1] << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    �迭�� ����� �˾ƿ��� ���� ���̺귯���� �߰��մϴ�.
    #include <array>
    */

    for (int i = 0; i < size(intArr1); i++)
    {
        cout << "intArr1 value : " << intArr1[i] << ", intArr1 address : " << &intArr1[i] << endl;
        cout << "intArr1 value : " << *(intArr1 + i) << ", intArr1 address : " << intArr1 + i << endl;
        cout << "" << endl;
    }

    cout << "" << endl;
    cout << "" << endl;

    /**
    ������ ���� ������ ��

    ������ ���� ����� �ʱ�ȭ �ϱ�
    ���� �����Ͱ� ���� �ǰ� �ʱ�ȭ���� ������ �����ʹ� ������ ���� ������ �˴ϴ�.
    �̷� ���¿��� �����͸� ����Ͽ� �޸��� ������ �����Ѵٸ� ������ ����ϴ�.
    */

    /**
    nullptr �������� ���

    �����Ͱ� �ƹ��͵� ����Ű�� ���� ���� nullptr�� �����ϴ� ���� �����ϴ�.
    */
    /**
    �����͸� �����ϱ� ���ؼ��� �ּҰ��� �������� �˾ƾ� �մϴ�.
    ������ �����͸� �����ϱ� ���� �޸𸮿��� ������ ������ �Ҵ� �޽��ϴ�.
    �� �����͸� ã�Ƽ� ȣ���ϱ� ���ؼ��� �� �����Ͱ� �޸� ��� �κп� ����Ǿ� �ִ� ���� �˾ƾ� �մϴ�.
    �̶� �����Ͱ� ����� �޸��� ���� �ּҸ� �ּҰ��̶�� �մϴ�.
    */

    /** intŸ���� �����͸� �����ϱ� ���� ������ �����ߴٸ� 4 bytes ũ��� �޸𸮿� �Ҵ�˴ϴ�.*/

    /**
    ������ ������ �̿��ϸ鼭 2���� �����ڰ� ���˴ϴ�.
    1. & : �ּ� ������, ���� �̸� �տ� ����Ͽ� �ش� ������ �޸� �ּ� ���� ��ȯ�մϴ�.
    2. * : ������ ������, �������� �̸��̳� �ּ� �տ� ����ϸ� �ش� �ּҸ� �����Ͽ� �ּҿ� ����Ǿ� �ִ�
            ���� ��ȯ�մϴ�.
    */

    /** ������ �߰��� �ݴϴ�. */
    int intValue2 = 10;
    /**
    int������ Ÿ���� intPtr2��� �̸��� ������ ������ �����߽��ϴ�.
    intValue2������ �ּҰ��� intPtr2 ������ ������ ���������ν� �ʱ�ȭ �߽��ϴ�.
    */
    int* intPtr2 = &intValue2;

    cout << "�ּ� ������ : " << &intValue2 << endl;
    cout << "������ ������ : " << *intPtr2 << endl;
    cout << "�ּ� �����ڿ� ������ �����ڸ� ���� ��� : " << *&intValue2 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    �ڷ����� ������� ��� Ʋ���ϴ�. ������ ������ ������ ������� 4 bytes�� �����մϴ�.
    ������ �߰��� �ݴϴ�.
    */
    int intValue3 = 10;
    int* intPtr3 = &intValue3;
    cout << "intPtr3 value : " << *intPtr3 << ", intPtr3 address : " << intPtr3 << endl;

    char charValue3 = 'L';
    char* charPtr3 = &charValue3;
    cout << "charPtr3 value : " << *charPtr3 << ", charPtr3 address : " << charPtr3 << endl; // ���� ��� �ִ� �ּ�
    cout << "charPtr3 value : " << *charPtr3 << ", charPtr3 address : " << &charPtr3 << endl; // ���� ��� �ִ� ����Ʈ �ּ�

    float floatValue3 = 1.414f;
    float* floatPtr3 = &floatValue3;
    cout << "floatPtr3 value : " << *floatPtr3 << ", floatPtr3 address : " << floatPtr3 << endl;

    double doubleValue3 = 3.1415;
    double* doublePtr3 = &doubleValue3;
    cout << "doublePtr3 value : " << *doublePtr3 << ", doublePtr3 address : " << doublePtr3 << endl;

    string stringValue3 = "Friend";
    string* stringPtr3 = &stringValue3;
    cout << "stringPtr3 value : " << *stringPtr3 << ", stringPtr3 address : " << stringPtr3 << endl;

    bool boolValue3 = true;
    bool* boolPtr3 = &boolValue3;
    cout << "boolPtr3 value : " << *boolPtr3 << ", boolPtr3 address : " << boolPtr3 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    ������ �������� ��� ���� ũ��� ���ɴϴ�.
    ������ ������ �޸𸮿��� ������ ��ġ�� ��Ÿ���� �ּҸ� �ٷ�� �����̹Ƿ�
    �� ũ��� ������ Ÿ�Կ� ���� �������� �ʽ��ϴ�.
    �޸� �ּҿ� �����ϴµ� �ʿ��� ��Ʈ���� �����ϸ� CPU�� ���� �����˴ϴ�.
    */

    cout << "int�� ������ ũ�� : " << sizeof(intValue3) << " bytes" << endl;
    cout << "int�� ������ ������ ũ�� : " << sizeof(intPtr3) << " bytes" << endl;

    cout << "char�� ������ ũ�� : " << sizeof(charValue3) << " bytes" << endl;
    cout << "char�� ������ ������ ũ�� : " << sizeof(charPtr3) << " bytes" << endl;

    cout << "float�� ������ ũ�� : " << sizeof(floatValue3) << " bytes" << endl;
    cout << "float�� ������ ������ ũ�� : " << sizeof(floatPtr3) << " bytes" << endl;

    cout << "double�� ������ ũ�� : " << sizeof(doubleValue3) << " bytes" << endl;
    cout << "double�� ������ ������ ũ�� : " << sizeof(doublePtr3) << " bytes" << endl;

    cout << "string�� ������ ũ�� : " << sizeof(stringValue3) << " bytes" << endl;
    cout << "string�� ������ ������ ũ�� : " << sizeof(stringPtr3) << " bytes" << endl;

    cout << "bool�� ������ ũ�� : " << sizeof(boolValue3) << " bytes" << endl;
    cout << "bool�� ������ ������ ũ�� : " << sizeof(boolPtr3) << " bytes" << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** ���� �����Ϳ� ���ؼ� �˾� ���ϴ�. */

    /** ������ �߰��� �ݴϴ�. */
    int intValue4 = 10;
    int* intPtr4 = &intValue4;   // ���� ��� �ִ� ���ּ�
    int** intDoublePtr4 = &intPtr4; // ���� ��� �ִ� ����Ʈ �ּ�

    cout << "intValue4 : " << intValue4 << endl;
    cout << "&intValue4 : " << &intValue4 << endl;  // ���� ��� �ִ� ���ּ�
    cout << "" << endl;

    cout << "intPtr4 : " << intPtr4 << endl;        // ���� ��� �ִ� ���ּ�
    cout << "*intPtr4 : " << *intPtr4 << endl;
    cout << "&intPtr4 : " << &intPtr4 << endl;      // ���� ��� �ִ� ����Ʈ �ּ�
    cout << "" << endl;

    /**
    **intDoublePtr4 => *(*intDoublePtr4) => *(intPtr4�� �ּ�) => intValue4�� ������ �����Ͻø� �˴ϴ�.
    */

    cout << "intDoublePtr4 : " << intDoublePtr4 << endl;    // ���� ��� �ִ� ����Ʈ �ּ�
    cout << "&intDoublePtr4 : " << &intDoublePtr4 << endl;  // ���� ��� �ִ� ����Ʈ ���� �ּ�
    cout << "*intDoublePtr4 : " << *intDoublePtr4 << endl;  // ���� ��� �ִ� ����Ʈ �ּ�
    cout << "**intDoublePtr4 : " << **intDoublePtr4 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    �����Ϳ� �迭

    �迭���� �迭�� �̸��� ȣ���� ��� �迭�� ���� �ּҰ� ��ȯ�˴ϴ�.
    �迭 �̸��� �̿��ؼ� ���� ������ �� ���� ���� �ּ� ���� �����ϴ� ������ �����Ϳ� �����ϴ�.
    ���� �迭�� ������ó�� �̿��� �� �ֽ��ϴ�.

    ������ �߰��� �ݴϴ�.
    */

    int intArr5[3] = { 10, 20, 30 };
    int* intPtr5 = intArr5;

    cout << "�迭 �̸����� �迭�� ��� ��� : " << intArr5[0] << ", " << intArr5[1] << ", " << intArr5[2] << endl;

    /** �迭���� �̿��ؼ� ����ϴ� ��ó�� �����Ϳ� []�� �ٿ� ����ϸ� �迭��� ������ ����� ���� �� �ֽ��ϴ�. */
    cout << "�����ͷ� �迭�� ��� ��� : " << intPtr5[0] << ", " << intPtr5[1] << ", " << intPtr5[2] << endl;

    /** �����͸� �迭ó�� �̿��ϴ� ��ó�� �迭�� ������ó�� �̿��ϴ� ���� �����մϴ�. */
    cout << "�迭�� ������ó�� ��� ��� : " << *(intArr5) << ", " << *(intArr5 + 1) << ", " << *(intArr5 + 2) << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    �����͸� ����� �� ������ ��
    ������ �߰��� �ݴϴ�.
    */
    /** intPtr6�� ������ ����, intPtr7�� �Ϲ� ������ ������ �˴ϴ�. */
    // int* intPtr6, intptr7; // (X)
    /** ���� intPtr7 �տ��� *(������ ������)�� �ٿ� �־�� �մϴ�. */
    int* intPtr6, * intPtr7;

    /**
    int* intPtr6;   // C++ ��Ÿ��
    int *intPtr7;   // C��� ��Ÿ��
    int * intPtr8;
    */

    /**
    �����͸� ����� ���� ������ �����ڸ� ����ϱ� ���� �ݵ�� �����͸� ������ �ּҷ� �ʱ�ȭ ���� �־�� �մϴ�.
    �Ϲ� ������ ���������� �����ʹ� ����� �ʱ�ȭ ���� �ʽ��ϴ�.
    �ʱ�ȭ ���� �ʴ� ���� ������ ���Դϴ�.

    ������ �߰��� �ݴϴ�.
    */
    int* intPtr8;
    int* intPtr9 = nullptr; // C++ ��Ÿ��
    int* intPtr10 = NULL;   // C ��Ÿ��

    // *intPtr8 = 10; // (X)

    /**
    intPtr9, intPtr10�� ������ �ּҷ� �ʱ�ȭ ���� �ʾұ� ������ intPtr9���� ������ ���� ���� �˴ϴ�.
    ��Ÿ�� ������ �߻��մϴ�.
    */
    // *intPtr9 = 20; // (X)
    // *intPtr10 = 30; // (X)

    cout << "" << endl;
    cout << "" << endl;

    /**
    ������ ������ �Ҵ��� �Ŀ� �ٸ� �ּҰ����� ���Ҵ� �� �� �ֽ��ϴ�.
    �� �κ��� �޸� ������ ����� �ϴ� �κ��Դϴ�.
    �����ڴ� ����� �ѹ� ���ϸ� ����� �������� ���ϱ� ������ C++���� �����ڸ� ���� ���°� �����ϴ�.

    ������ �߰��� �ݴϴ�.
    */
    int intValue11 = 5;
    int intValue12 = 7;
    int* intPtr11;
    intPtr11 = &intValue11;
    cout << "intPtr11 value : " << *intPtr11 << ", intPtr11 address : " << intPtr11 << endl;
    cout << "" << endl;

    intPtr11 = &intValue12;
    cout << "intPtr11 value : " << *intPtr11 << ", intPtr11 address : " << intPtr11 << endl;
    cout << "" << endl;

    /** *ptr value�� ���� ��޵ǹǷ� ��ġ �������� ��ó�� ���� �Ҵ��� �� �ֽ��ϴ�. */

    /** ������ �߰��� �ݴϴ�. */
    int intValue13 = 5;
    int* intPtr13 = &intValue13;
    cout << "intPtr13 value : " << *intPtr13 << ", intPtr13 address : " << intPtr13 << endl;
    cout << "" << endl;

    *intPtr13 = 15;
    cout << "intPtr13 value : " << *intPtr13 << ", intPtr13 address : " << intPtr13 << endl;
    cout << "" << endl;

    /**
    �����ڿ� ���ؼ� �˾� ���ϴ�.

    ������(Reference)�� C++ �� ����Ѵٸ� �ݵ�� ������ �ϴ� �ſ� �߿��� �����Դϴ�.
    */

    /**
    �������� ����
    1. ��-��� ����(non-const reference) : ���� �����ڶ�� �ϸ� �̰��� �ǹ��մϴ�.
    2. ��� ����(const reference) : ����� �����ϱ� ���� �������� ��-��� ������ �����մϴ�.
    */

    /**
    �������� ��Ģ

    �����ڶ� ��󿡰� �� �ٸ� �̸��� �ٿ��ִ� ���� �ǹ��մϴ�.
    ���� �Ǵ� ��Ī�� �ٿ� �ִ� ���Դϴ�.

    ������ �߰��� �ݴϴ�.
    */
    int intValue14 = 1;
    cout << "intValue14 value : " << intValue14 << ", intValue14 address : " << &intValue14 << endl;
    cout << "" << endl;
    /**
    int������ Ÿ���� intRef14��� �̸��� ������ ������ �����߽��ϴ�.
    intRef14 �����ڴ� intValue14�� �������� �����߽��ϴ�.
    ���� intRef14�� intValue14�� �Ȱ����ϴ�.
    */

    /**
    int& intRef14 = intValue14;�� intValue14�� �����ϴ� ������ intRef14�� �����ϴ� ���Դϴ�.
    �׷� �� ������ �̸��� intValue14 �Ӹ��� �ƴϰ�, intRef14�� �Ǵ� ���Դϴ�.
    �� �ϳ��� �޸� ������ �̸��� 2�� ����� �ǰ� �� ���� �ּ� ���� ���ٴ� �ǹ��Դϴ�.

    intRef14 = 2;�� �ϰ� ���� �ּҸ� ��� ����� ���� intValue14�� intRef14 ��� 2�� ����ǰ�, �ּҵ� ���� ���� Ȯ���� �� �ֽ��ϴ�.
    */
    int& intRef14 = intValue14;
    intRef14 = 2;
    cout << "intValue14 value : " << intValue14 << ", intValue14 address : " << &intValue14 << endl;
    cout << "intRef14 value : " << intRef14 << ", intRef14 address : " << &intValue14 << endl;
    cout << "" << endl;

    /** �������� ������ �� �ʱ�ȭ�� �ʿ��մϴ�. ��� ������ ���� �ִ� ���̱� ������ ������ ����� �ʿ��մϴ�. */

    /** ������ �߰��� �ݴϴ�. */
    int intValue15 = 1;
    /** �����ڸ� �����մϴ�. */
    int& intRef15 = intValue15;
    /** �������� ������ �� �ʱ�ȭ�� �ʿ��մϴ�. ��� ������ ���� �ִ� ���̱� ������ ������ ����� �ʿ��մϴ�. */
    // int& intRef16; // (X)

    /**
    ���� ��� ���� �Ұ��� ���ؼ� �˾� ���ϴ�.
    ������ �߰��� �ݴϴ�.
    */
    int intValue16 = 1;
    int intValue17 = 2;
    /** intRef16�� intValue16�� �����ϴ�. */
    int& intRef16 = intValue16;
    cout << "intRef16 value : " << intRef16 << ", intRef16 address : " << &intRef16 << endl;
    cout << "intValue16 value : " << intValue16 << ", intValue16 address : " << &intValue16 << endl;
    cout << "" << endl;

    /**
    intRef16�� intValue17�� �������?
    intValue17�� �����ϴ� ���� �ƴϰ� intValue16 = intValue17; �� ���� �ǹ��Դϴ�.
    �ѹ� �������� ���������� ������ ����� ������ �� �����ϴ�.
    */
    intRef16 = intValue17;

    cout << "intRef16 value : " << intRef16 << ", intRef16 address : " << &intRef16 << endl;
    cout << "intValue16 value : " << intValue16 << ", intValue16 address : " << &intValue16 << endl;
    cout << "intValue17 value : " << intValue17 << ", intValue17 address : " << &intValue17 << endl;
    cout << "" << endl;


    /**
    ��� ������ ���ؼ� �˾ƺ����� �մϴ�.

    ������ �߰��� �ݴϴ�.
    */
    const int intValue18 = 10;

    /** ������ ����, ��-��� �����ڷ� ��� ������ �Ұ����մϴ�. */
    // int& intRef18 = intValue18; // (X)
    /**
    ��-��� �����ڷ� ����� ������ ���� ������ const�� ����ϸ� �����մϴ�.
    ���� const int& intRef20 = 100; ó�� ���ͷ�(�� ��ü) ����� ������ �� �ֽ��ϴ�.
    ���⼭ 100�̶�� ���ͷ� ����� �ӽ����� �����ν� �޸𸮿� �̸��� ���� �����ߴٰ� �Ҹ��մϴ�.
    �޸𸮿��� �̸��� ���� �ٷ� ������� �ӽ� ���Դϴ�.
    */
    const int& intRef19 = intValue18;
    const int& intRef20 = 100; // ������ ���Դϴ�. 

    /**
    ������ ���� ���� ����� const�����ڷ� �����ϸ� "�ӽú���"�� ����鼭 ������ �����մϴ�.
    �׷��ٸ� �� ���� const �����ڱ��� ����ϸ鼭 ����� �����ұ��?
    �׽�Ʈ�� ���ؼ� Add() �Լ��� ������ �ֵ��� �մϴ�.
    */

    /** ������ �߰��� �ݴϴ�. */

    /**
    �Ű� ������ ����� �����մϴ�.
    Add() �Լ��� �Ű� ������ const �����ڷ� �ް� �ֽ��ϴ�.
    Add(1, 2) ó�� ��ٷ� ����� �Լ� ȣ���� �����մϴ�.
    �� const int& value1 = 1; const int& value2 = 2; �� �Ǵ� ���Դϴ�.

    �ڵ�� ���� ��ġ���� �ִ� ���� �ϵ��ڵ��̶�� �մϴ�.
    ���ڹ��Դϴ�.
    */
    int intValue21 = Add(1, 2);
    cout << "intValue21 : " << intValue21 << endl;
    cout << "" << endl;

    /**
    ���࿡ const �����ڰ� ���ٸ�?
    �Լ��� �߰��� �ݴϴ�.
    */

    /** ������ �߰��� �ݴϴ�. */
    int intValue22 = 1;
    int intValue23 = 2;

    /**
    �Ű������� ������ �����մϴ�.
    ��õ�ϴ� ����Դϴ�.
    */
    int intValue24 = Add(intValue22, intValue23);
    cout << "intValue24 : " << intValue24 << endl;
    cout << "" << endl;

    /** �׷��ٸ� �����ڴ� NULL�� ������ �� ���� ���? */

    /** ������ �߰��� �ݴϴ�. */
    /**
    NULL�� ��� �� 0�� define �� ���� ���̹Ƿ� NULL�� 0�� �����ϴ�.
    ���� �Ϲ� �����ڴ� NULL������ �Ұ����մϴ�.
    */
    // int& intRef15 = NULL; // ��-��� �����ڷ� ��� ���� �Ұ����մϴ�. 
    const int& intRef30 = NULL; // ��� �����ڷ� ��� ������ ������ �մϴٸ�. 

    /**
    const�� ��ġ�ϴ� ���� ���� �ǹ��ϴ� �ٰ� ������ Ʋ���ϴ�.
    */
    /** 1. �ڷ��� �տ� const�� �ֽ��ϴ�. */
    int intValue100 = 1;
    /** const�� �ڷ��� �տ� ������ ������ ������ ����Ű�� ���� ���ȭ �մϴ�. */
    const int* intPtr100 = &intValue100;
    // *intPtr100 = 100; // (X)

    /** 2. �ڷ����� ���� �̸� ���̿� const�� �ֽ��ϴ�. */
    int intValue101 = 2;
    int intValue102 = 3;
    /** const�� �ڷ����� ���� �̸� ���̿� ������ ������ ���� ��ü�� ���ȭ �մϴ�. */
    int* const intPtr101 = &intValue101;
    // intPtr101 = &intValue102; // (X)

    /** 3. �ڷ��� �տ� const�� �ְ� �ڷ����� ���� �̸� ���̿��� const�� �ֽ��ϴ�. */
    int intValue103 = 4;
    int intValue104 = 5;
    /**
    const�� �ڷ��� �տ� ������ ������ ������ ����Ű�� ���� ���ȭ �մϴ�.
    const�� �ڷ����� ������ ���� �̸� ���̿� ������ ������ ���� ��ü�� ���ȭ �մϴ�.
    */
    const int* const intPtr103 = &intValue103;
    // *intPtr103 = 100; // (X)
    // intPtr103 = &intValue104; // (X)

    /**
    4. �Ű� ������ const ����� �ֽ��ϴ�.
    �����ϴ� �ٸ� �����ڰ� �Ű� ������ �������� ������ ���� ���Ѵٴ� ���� �����մϴ�.
    �����ϴ� �ٸ� �������� �Ǽ��� �̿��� �����մϴ�.
    �׽�Ʈ�� ���ؼ� ConstParameter��� �̸��� �Լ��� ������ �ݴϴ�.
    */

    /**
    5. �Լ� ���� const����� �ֽ��ϴ�.
    �����ϴ� �ٸ� �����ڰ� ��� ������ �������Ѵٴٴ� ���� �����մϴ�.
    �����ϴ� �ٸ� �������� �Ǽ��� �̿��� �����մϴ�.
    �׽�Ʈ�� ���ؼ� ConstFunction�̶�� �̸��� Ŭ������ ������ �ݴϴ�.
    */

}
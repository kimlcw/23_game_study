#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리를 사용합니다. */
using namespace std;

/**
하지만 위와 같이 상수를 const참조자로 참조하면 "임시변수"가 생기면서 참조가 가능합니다.
그렇다면 왜 굳이 const 참조자까지 사용하면서 상수를 참조할까요?
테스트를 위해서 Add() 함수를 정의해 주도록 합니다.
*/
/** const 참조자형 매개변수를 가지고 있습니다. */
int Add(const int& value1, const int& value2)
{
    return value1 + value2;
}

/**
만약에 const 참조자가 없다면?
함수를 추가해 줍니다.
*/
/** 비-상수 참조자형 매개 변수를 가지고 있습니다. */
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
    /** const가 매개 변수에 있으면 매개 변수의 값을 변경하지 못합니다. */
    void ConstParameter(const int intValue)
    {
        // intValue = 200; // (X)
    }
    /** const가 함수 끝에 있으면 멤버 변수의 값을 변경하지 못합니다. */
    void ConstFunction() const
    {
        // apple = "Apple"; // (X)
    }
};

int main()
{
    /**
    포인터란?
    포인터는 주소를 저장하는 변수입니다.
    일반적인 변수는 데이터를 저장하는데 반하여 포인터는 메모리 공간의 주소를 저장합니다.
    포인터 변수가 주소를 저장하려면 변수의 주소를 알아야 하는데
    1. 변수 이름 앞에 &(주소 연산자) 연산자를 붙이면 해당 변수의 시작 주소를 반환합니다.
    2. 포인터 변수가 저장하는 변수의 주소에 저장된 값을 참조하려면 *(역참조 연산자) 연산자를 사용합니다.
    */

    /** int포인터 타입의 intPtr1이라는 이름의 변수를 선언하고 nullptr값을 intPtr1 포인터 변수에 대입했습니다. */
    int* intPtr1 = nullptr;

    int intValue1 = 10;
    /** intValue1변수의 주소값을 intPtr1포인터 변수에 대입했습니다. */
    intPtr1 = &intValue1;
    /** intValue1 변수의 주소값*/
    cout << "intValue1 address : " << &intValue1 << endl;
    /** intPtr1 포인터 변수의 주소값*/
    cout << "intPtr1 address : " << intPtr1 << endl;
    /** intPtr1 포인터 변수의 주소값*/
    cout << "intPtr1 address : " << &intPtr1 << endl;
    /** intPtr1 포인터 변수가 가리키는 값*/
    cout << "intPtr1 value : " << *intPtr1 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    포인터와 배열의 관계에 대해서 알아보도록 합니다.
    문장을 추가해 줍니다.
    */

    /**
    int 타입을 여러개 저장할 수 있는 배열타입으로 intArr1이라는 이름의 변수를 선언했습니다.
    10, 20, 30, 40, 50의 값을 intArr1 배열에 대입함으로써 초기화 했습니다.
    */
    int intArr1[] = { 10, 20, 30, 40,50 };

    /**
    포인터와 배열은 서로 밀접한 관계를 가지고 있습니다.
    배열 이름은 배열의 시작 주소를 반환합니다.
    배열 이름은 배열의 0번째 인덱스값의 주소를 반환합니다.
    intArr1 은 & intArr1[0]    intArr1의 0번째 인덱스의 주소값 입니다.

    배열 이름을 포인터라 생각하고 intArr1를 출력해 보면 intArr1[0]이 출력됩니다.
    또한 intArr1 + i는 intArr1가 포인터이므로 배열 시작 주소에(i 배열요소의 크기)가 더해집니다.
    따라서 intArr1 + i 는 & intArr1[i]과 같고
    * (intArr1 + i)는 intArr1[i]와 완전히 동일합니다.
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
    배열의 사이즈를 알아오기 위한 라이브러리를 추가합니다.
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
    포인터 사용시 주의할 점

    포인터 변수 선언시 초기화 하기
    만약 포인터가 선언만 되고 초기화되지 않으면 포인터는 쓰레기 값을 가지게 됩니다.
    이런 상태에서 포인터를 사용하여 메모리의 내용을 변경한다면 문제가 생깁니다.
    */

    /**
    nullptr 포인터의 사용

    포인터가 아무것도 가리키지 않을 때는 nullptr로 설정하는 것이 좋습니다.
    */
    /**
    포인터를 이해하기 위해서는 주소값이 무엇인지 알아야 합니다.
    변수는 데이터를 저장하기 위해 메모리에서 저장할 공간을 할당 받습니다.
    이 데이터를 찾아서 호출하기 위해서는 이 데이터가 메모리 어느 부분에 저장되어 있는 지를 알아야 합니다.
    이때 데이터가 저장된 메모리의 시작 주소를 주소값이라고 합니다.
    */

    /** int타입의 데이터를 저장하기 위해 변수를 선언했다면 4 bytes 크기로 메모리에 할당됩니다.*/

    /**
    포인터 변수를 이용하면서 2가지 연산자가 사용됩니다.
    1. & : 주소 연산자, 변수 이름 앞에 사용하여 해당 변수의 메모리 주소 값을 반환합니다.
    2. * : 역참조 연산자, 포인터의 이름이나 주소 앞에 사용하며 해당 주소를 참조하여 주소에 저장되어 있는
            값을 반환합니다.
    */

    /** 문장을 추가해 줍니다. */
    int intValue2 = 10;
    /**
    int포인터 타입의 intPtr2라는 이름의 포인터 변수를 선언했습니다.
    intValue2변수의 주소값을 intPtr2 포인터 변수에 대입함으로써 초기화 했습니다.
    */
    int* intPtr2 = &intValue2;

    cout << "주소 연산자 : " << &intValue2 << endl;
    cout << "역참조 연산자 : " << *intPtr2 << endl;
    cout << "주소 연산자와 역참조 연산자를 같이 사용 : " << *&intValue2 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    자료형의 사이즈는 모두 틀립니다. 하지만 포인터 변수의 사이즈는 4 bytes로 동일합니다.
    문장을 추가해 줍니다.
    */
    int intValue3 = 10;
    int* intPtr3 = &intValue3;
    cout << "intPtr3 value : " << *intPtr3 << ", intPtr3 address : " << intPtr3 << endl;

    char charValue3 = 'L';
    char* charPtr3 = &charValue3;
    cout << "charPtr3 value : " << *charPtr3 << ", charPtr3 address : " << charPtr3 << endl; // 내가 살고 있는 주소
    cout << "charPtr3 value : " << *charPtr3 << ", charPtr3 address : " << &charPtr3 << endl; // 내가 살고 있는 아파트 주소

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
    포인터 변수들은 모두 같은 크기로 나옵니다.
    포인터 변수는 메모리에서 변수의 위치를 나타내는 주소를 다루는 변수이므로
    그 크기는 변수의 타입에 의해 결정되지 않습니다.
    메모리 주소에 접근하는데 필요한 비트수는 일정하며 CPU에 의해 결정됩니다.
    */

    cout << "int형 변수의 크기 : " << sizeof(intValue3) << " bytes" << endl;
    cout << "int형 포인터 변수의 크기 : " << sizeof(intPtr3) << " bytes" << endl;

    cout << "char형 변수의 크기 : " << sizeof(charValue3) << " bytes" << endl;
    cout << "char형 포인터 변수의 크기 : " << sizeof(charPtr3) << " bytes" << endl;

    cout << "float형 변수의 크기 : " << sizeof(floatValue3) << " bytes" << endl;
    cout << "float형 포인터 변수의 크기 : " << sizeof(floatPtr3) << " bytes" << endl;

    cout << "double형 변수의 크기 : " << sizeof(doubleValue3) << " bytes" << endl;
    cout << "double형 포인터 변수의 크기 : " << sizeof(doublePtr3) << " bytes" << endl;

    cout << "string형 변수의 크기 : " << sizeof(stringValue3) << " bytes" << endl;
    cout << "string형 포인터 변수의 크기 : " << sizeof(stringPtr3) << " bytes" << endl;

    cout << "bool형 변수의 크기 : " << sizeof(boolValue3) << " bytes" << endl;
    cout << "bool형 포인터 변수의 크기 : " << sizeof(boolPtr3) << " bytes" << endl;

    cout << "" << endl;
    cout << "" << endl;

    /** 이중 포인터에 대해서 알아 봅니다. */

    /** 문장을 추가해 줍니다. */
    int intValue4 = 10;
    int* intPtr4 = &intValue4;   // 내가 살고 있는 집주소
    int** intDoublePtr4 = &intPtr4; // 내가 살고 있는 아파트 주소

    cout << "intValue4 : " << intValue4 << endl;
    cout << "&intValue4 : " << &intValue4 << endl;  // 내가 살고 있는 집주소
    cout << "" << endl;

    cout << "intPtr4 : " << intPtr4 << endl;        // 내가 살고 있는 집주소
    cout << "*intPtr4 : " << *intPtr4 << endl;
    cout << "&intPtr4 : " << &intPtr4 << endl;      // 내가 살고 있는 아파트 주소
    cout << "" << endl;

    /**
    **intDoublePtr4 => *(*intDoublePtr4) => *(intPtr4의 주소) => intValue4의 값으로 이해하시면 됩니다.
    */

    cout << "intDoublePtr4 : " << intDoublePtr4 << endl;    // 내가 살고 있는 아파트 주소
    cout << "&intDoublePtr4 : " << &intDoublePtr4 << endl;  // 내가 살고 있는 아파트 단지 주소
    cout << "*intDoublePtr4 : " << *intDoublePtr4 << endl;  // 내가 살고 있는 아파트 주소
    cout << "**intDoublePtr4 : " << **intDoublePtr4 << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    포인터와 배열

    배열에서 배열의 이름만 호출할 경우 배열의 시작 주소가 반환됩니다.
    배열 이름만 이용해서 값을 변경할 수 없는 빼면 주소 값을 저장하는 변수인 포인터와 같습니다.
    따라서 배열을 포인터처럼 이용할 수 있습니다.

    문장을 추가해 줍니다.
    */

    int intArr5[3] = { 10, 20, 30 };
    int* intPtr5 = intArr5;

    cout << "배열 이름으로 배열의 요소 출력 : " << intArr5[0] << ", " << intArr5[1] << ", " << intArr5[2] << endl;

    /** 배열명을 이용해서 출력하는 것처럼 포인터에 []를 붙여 출력하면 배열명과 동일한 경과를 얻을 수 있습니다. */
    cout << "포인터로 배열의 요소 출력 : " << intPtr5[0] << ", " << intPtr5[1] << ", " << intPtr5[2] << endl;

    /** 포인터를 배열처럼 이용하는 것처럼 배열을 포인터처럼 이용하는 것이 가능합니다. */
    cout << "배열을 포인터처럼 요소 출력 : " << *(intArr5) << ", " << *(intArr5 + 1) << ", " << *(intArr5 + 2) << endl;

    cout << "" << endl;
    cout << "" << endl;

    /**
    포인터를 사용할 때 주의할 점
    문장을 추가해 줍니다.
    */
    /** intPtr6는 포인터 변수, intPtr7은 일반 변수로 생성이 됩니다. */
    // int* intPtr6, intptr7; // (X)
    /** 따라서 intPtr7 앞에도 *(포인터 연산자)를 붙여 주어야 합니다. */
    int* intPtr6, * intPtr7;

    /**
    int* intPtr6;   // C++ 스타일
    int *intPtr7;   // C언어 스타일
    int * intPtr8;
    */

    /**
    포인터를 사용할 때는 역참조 연산자를 사용하기 전에 반드시 포인터를 적절한 주소로 초기화 시켜 주어야 합니다.
    일반 변수와 마찬가지로 포인터는 선언시 초기화 되지 않습니다.
    초기화 되지 않는 값은 쓰레기 값입니다.

    문장을 추가해 줍니다.
    */
    int* intPtr8;
    int* intPtr9 = nullptr; // C++ 스타일
    int* intPtr10 = NULL;   // C 스타일

    // *intPtr8 = 10; // (X)

    /**
    intPtr9, intPtr10를 적절한 주소로 초기화 하지 않았기 때문에 intPtr9에는 쓰레기 값이 들어가게 됩니다.
    런타임 에러가 발생합니다.
    */
    // *intPtr9 = 20; // (X)
    // *intPtr10 = 30; // (X)

    cout << "" << endl;
    cout << "" << endl;

    /**
    포인터 변수는 할당한 후에 다른 주소값으로 재할당 할 수 있습니다.
    이 부분이 메모리 관리를 힘들게 하는 부분입니다.
    참조자는 대상을 한번 정하면 대상을 변경하지 못하기 때문에 C++에서 참조자를 많이 쓰는게 좋습니다.

    문장을 추가해 줍니다.
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

    /** *ptr value와 같이 취급되므로 마치 변수값인 것처럼 값을 할당할 수 있습니다. */

    /** 문장을 추가해 줍니다. */
    int intValue13 = 5;
    int* intPtr13 = &intValue13;
    cout << "intPtr13 value : " << *intPtr13 << ", intPtr13 address : " << intPtr13 << endl;
    cout << "" << endl;

    *intPtr13 = 15;
    cout << "intPtr13 value : " << *intPtr13 << ", intPtr13 address : " << intPtr13 << endl;
    cout << "" << endl;

    /**
    참조자에 대해서 알아 봅니다.

    참조자(Reference)는 C++ 을 사용한다면 반드시 익혀야 하는 매우 중요한 개념입니다.
    */

    /**
    참조자의 종류
    1. 비-상수 참조(non-const reference) : 보통 참조자라고 하면 이것을 의미합니다.
    2. 상수 참조(const reference) : 상수를 참조하기 위한 것이지만 비-상수 참조도 가능합니다.
    */

    /**
    참조자의 규칙

    참조자란 대상에게 또 다른 이름을 붙여주는 것을 의미합니다.
    별명 또는 별칭을 붙여 주는 것입니다.

    문장을 추가해 줍니다.
    */
    int intValue14 = 1;
    cout << "intValue14 value : " << intValue14 << ", intValue14 address : " << &intValue14 << endl;
    cout << "" << endl;
    /**
    int참조자 타입의 intRef14라는 이름의 참조자 변수를 선언했습니다.
    intRef14 참조자는 intValue14의 별명으로 선언했습니다.
    따라서 intRef14와 intValue14는 똑같습니다.
    */

    /**
    int& intRef14 = intValue14;는 intValue14를 참조하는 참조자 intRef14를 선언하는 것입니다.
    그럼 이 변수의 이름은 intValue14 뿐만이 아니고, intRef14도 되는 것입니다.
    즉 하나의 메모리 공간에 이름이 2개 생기게 되고 이 둘의 주소 값이 같다는 의미입니다.

    intRef14 = 2;를 하고 값과 주소를 모두 출력해 보면 intValue14와 intRef14 모두 2로 변경되고, 주소도 같은 것을 확인할 수 있습니다.
    */
    int& intRef14 = intValue14;
    intRef14 = 2;
    cout << "intValue14 value : " << intValue14 << ", intValue14 address : " << &intValue14 << endl;
    cout << "intRef14 value : " << intRef14 << ", intRef14 address : " << &intValue14 << endl;
    cout << "" << endl;

    /** 참조자의 선언은 꼭 초기화가 필요합니다. 대상에 별명을 지어 주는 것이기 때문에 무조건 대상이 필요합니다. */

    /** 문장을 추가해 줍니다. */
    int intValue15 = 1;
    /** 참조자를 선언합니다. */
    int& intRef15 = intValue15;
    /** 참조자의 선언은 꼭 초기화가 필요합니다. 대상에 별명을 지어 주는 것이기 때문에 무조건 대상이 필요합니다. */
    // int& intRef16; // (X)

    /**
    참조 대상 변경 불가에 대해서 알아 봅니다.
    문장을 추가해 줍니다.
    */
    int intValue16 = 1;
    int intValue17 = 2;
    /** intRef16과 intValue16은 같습니다. */
    int& intRef16 = intValue16;
    cout << "intRef16 value : " << intRef16 << ", intRef16 address : " << &intRef16 << endl;
    cout << "intValue16 value : " << intValue16 << ", intValue16 address : " << &intValue16 << endl;
    cout << "" << endl;

    /**
    intRef16과 intValue17은 같을까요?
    intValue17을 참조하는 것이 아니고 intValue16 = intValue17; 와 같은 의미입니다.
    한번 누군가를 참조했으면 참조의 대상을 변경할 수 없습니다.
    */
    intRef16 = intValue17;

    cout << "intRef16 value : " << intRef16 << ", intRef16 address : " << &intRef16 << endl;
    cout << "intValue16 value : " << intValue16 << ", intValue16 address : " << &intValue16 << endl;
    cout << "intValue17 value : " << intValue17 << ", intValue17 address : " << &intValue17 << endl;
    cout << "" << endl;


    /**
    상수 참조에 대해서 알아보도록 합니다.

    문장을 추가해 줍니다.
    */
    const int intValue18 = 10;

    /** 컴파일 에러, 비-상수 참조자로 상수 참조는 불가능합니다. */
    // int& intRef18 = intValue18; // (X)
    /**
    비-상수 참조자로 상수를 참조할 수는 없지만 const를 사용하면 가능합니다.
    또한 const int& intRef20 = 100; 처럼 리터럴(값 자체) 상수로 참조할 수 있습니다.
    여기서 100이라는 리터럴 상수는 임시적인 값으로써 메모리에 이름도 없이 존재했다가 소멸합니다.
    메모리에서 이름도 없이 바로 사라지는 임시 값입니다.
    */
    const int& intRef19 = intValue18;
    const int& intRef20 = 100; // 안좋은 예입니다. 

    /**
    하지만 위와 같이 상수를 const참조자로 참조하면 "임시변수"가 생기면서 참조가 가능합니다.
    그렇다면 왜 굳이 const 참조자까지 사용하면서 상수를 참조할까요?
    테스트를 위해서 Add() 함수를 정의해 주도록 합니다.
    */

    /** 문장을 추가해 줍니다. */

    /**
    매개 변수로 상수를 전달합니다.
    Add() 함수의 매개 변수로 const 참조자로 받고 있습니다.
    Add(1, 2) 처럼 곧바로 상수로 함수 호출이 가능합니다.
    즉 const int& value1 = 1; const int& value2 = 2; 가 되는 것입니다.

    코드상에 직접 수치값을 넣는 것을 하드코딩이라고 합니다.
    지뢰밭입니다.
    */
    int intValue21 = Add(1, 2);
    cout << "intValue21 : " << intValue21 << endl;
    cout << "" << endl;

    /**
    만약에 const 참조자가 없다면?
    함수를 추가해 줍니다.
    */

    /** 문장을 추가해 줍니다. */
    int intValue22 = 1;
    int intValue23 = 2;

    /**
    매개변수로 변수를 전달합니다.
    추천하는 방법입니다.
    */
    int intValue24 = Add(intValue22, intValue23);
    cout << "intValue24 : " << intValue24 << endl;
    cout << "" << endl;

    /** 그렇다면 참조자는 NULL을 참조할 수 있을 까요? */

    /** 문장을 추가해 줍니다. */
    /**
    NULL은 상수 값 0을 define 해 놓은 것이므로 NULL은 0과 같습니다.
    따라서 일반 참조자는 NULL참조가 불가능합니다.
    */
    // int& intRef15 = NULL; // 비-상수 참조자로 상수 참조 불가능합니다. 
    const int& intRef30 = NULL; // 상수 참조자로 상수 참조는 가능은 합니다만. 

    /**
    const는 위치하는 곳에 따라서 의미하는 바가 완전히 틀립니다.
    */
    /** 1. 자료형 앞에 const가 있습니다. */
    int intValue100 = 1;
    /** const가 자료형 앞에 있으면 포인터 변수가 가리키는 값을 상수화 합니다. */
    const int* intPtr100 = &intValue100;
    // *intPtr100 = 100; // (X)

    /** 2. 자료형과 변수 이름 사이에 const가 있습니다. */
    int intValue101 = 2;
    int intValue102 = 3;
    /** const가 자료형과 변수 이름 사이에 있으면 포인터 변수 자체를 상수화 합니다. */
    int* const intPtr101 = &intValue101;
    // intPtr101 = &intValue102; // (X)

    /** 3. 자료형 앞에 const가 있고 자료형과 변수 이름 사이에도 const가 있습니다. */
    int intValue103 = 4;
    int intValue104 = 5;
    /**
    const가 자료형 앞에 있으면 포인터 변수가 가리키는 값을 상수화 합니다.
    const가 자료형과 포인터 변수 이름 사이에 있으면 포인터 변수 자체를 상수화 합니다.
    */
    const int* const intPtr103 = &intValue103;
    // *intPtr103 = 100; // (X)
    // intPtr103 = &intValue104; // (X)

    /**
    4. 매개 변수에 const 지정어가 있습니다.
    협업하는 다른 개발자가 매개 변수로 전달해준 변수를 수정 못한다는 것을 보장합니다.
    협업하는 다른 개발자의 실수를 미연에 방지합니다.
    테스트를 위해서 ConstParameter라는 이름의 함수를 정의해 줍니다.
    */

    /**
    5. 함수 끝에 const지정어가 있습니다.
    협업하는 다른 개발자가 멤버 변수를 수정못한다다는 것을 보장합니다.
    협업하는 다른 개발자의 실수를 미연에 방지합니다.
    테스트를 위해서 ConstFunction이라는 이름의 클래스를 정의해 줍니다.
    */

}
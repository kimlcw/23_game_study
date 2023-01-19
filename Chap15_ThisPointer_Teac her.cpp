#include <iostream>

/** 문자열 관련 라이브러리*/
#include <string>

/** C++ 표준 라이브러리 사용합니다. */
using namespace std;

/** 테스트를 위해서 Student1이라는 이름의 클래스를 정의해 주도록 합니다. */
class Student1
{
private:
    int age;
public:
    Student1(int value)
    {
        age = value;
    }

    void SetInfo()
    {
        cout << age << "살 입니다. " << endl;
    }
};

/**
1. 클래스의 멤버 변수와 매개 변수의 이름이 같을 때 사용할 수 있습니다.
테스트를 위해서 Student2라는 이름의 클래스를 정의해 줍니다.
*/
class Student2
{
private:
    /**
    멤버 변수는 변수의 이름만 보더라도 멤버 변수인 것을 알 수 있도록 변수 이름 앞에 m, m_, _를 붙여 줍니다.
    지금은 테스트를 위해서 붙여 주지 않습니다.
    */
    // int m_Age;
    int age;
public:
    /**
    멤버 변수 age와 매개 변수 age가 같을 때가 있습니다.
    이 때 this->age 는 멤버 변수를 의미하고, age는 매개 변수를 의미합니다.
    하지만 매개 변수를 동일한 이름으로 하지 않는다면 굳이 this포인터를 쓸 필요는 없습니다.
    this 포인터는 명시적으로 멤버 변수임을 가리킬 수 있습니다.
    */
    Student2(int age)
    {
        // age = age; // (O)
        this->age = age;
    }
};

/**
2. 객체 자신의 주소를 반환할 때 사용할 수 있습니다.
테스트를 위해서 Student3라는 이름의 클래스를 정의해 줍니다.
*/
class Student3
{
private:
    int age;
public:
    Student3(int age)
    {
        this->age = age;
    }

    void SetInfo()
    {
        /** 자기 자신의 주소를 반환합니다. */
        cout << this << endl;
    }
};

/**
this는 자기 자신의 객체를 가리키는 포인터 변수입니다.
*this를 확인해 보기 위해서 Lion이라는 이름의 클래스를 정의해 주도록 합니다.
*/
class Lion
{
private:
    int num = 10;
public:
    /** 자기 자신을 출력하는 멤버 함수입니다. */
    void PrintThis()
    {
        cout << this << endl;
    }
    /** 자기 자신의 참조자를 반환하는 멤버 함수입니다. */
    Lion& ReturnThisAsReference()
    {
        return *this;
    }
};

/** 다음 테스트를 위해서 Tiger라는 이름의 클래스를 정의해 주도록 합니다. */
class Tiger
{
private:
    string m_Name;
public:
    Tiger(string name) : m_Name(name) {}

    void SetName()
    {
        cout << "Name : " << m_Name << endl;
    }

    Tiger& ReturnThis1()
    {
        return *this; // 가리키는 자기 자신이라서 참조가 가능합니다. 
    }

    Tiger ReturnThis2()
    {
        return *this; // 복사 생성자에 의해 주소값 다릅니다. 아직 이해가 안됩니다. 
    }

    Tiger& ReturnThis3()
    {
        // return this; // 주소 값에 대한 참조는 안되기 때문입니다. 
    }

    Tiger* ReturnThis4()
    {
        return this; // this가 자기 자신을 가리키는 포인터이미 포인터 리턴이 가능합니다. 
    }

    Tiger ReturnThis5()
    {
        // return this; // 포인터를 일반 변수로 리턴하면 안됩니다. 
    }
};

int main()
{
    /**
    This포인터

    클래스의 멤버 함수를 호출할 때 C++은 어떻게 호출할 객체(인스턴스, instance)를 찾을 까요?
    정답은 this라는 숨겨진 포인터를 사용한다는 것입니다.

    this포인터는 클래스의 실제 객체에 대한 주소를 가리키는 포인터입니다.
    클래스의 멤버 함수를 호출할 때 이 this라는 포인터를 이용해서 객체를 찾을 수 있습니다.
    */

    /** 테스트를 위해서 Student1이라는 이름의 클래스를 정의해 주도록 합니다. */

    /** 문장을 추가해 줍니다. */
    Student1 student1(22);
    cout << "student1 : ";
    student1.SetInfo();
    cout << "" << endl;

    /**
    메모리에 객체가 생성될 때 멤버 변수는 메모리에 올라가지만 멤버 함수는 올라가지 않습니다.
    여러개의 같은 객체가 메모리에 올라갈 때 멤버 변수는 다양하게 생성되지만
    멤버 함수는 하나만 생성되고, 구분을 위해서 this포인터가 쓰입니다.
    */
    cout << "sizeof(student1) : " << sizeof(student1) << " bytes" << endl;
    cout << "" << endl;

    /**
     student1.SetInfo(); 함수는 매개 변수 없이 호출하는 것처럼 보입니다.
     하지만 student1.SetInfo(&student1); 처럼 존재하고 있습니다.
     이 주소는 우리 눈에는 보이지 않을 뿐 존재하고 있으며
     첫 번째 매개 변수로 전달된 객체의 주소는 이름이 this인 포인터 변수에 저장되는 것입니다.

     &student1 : student1객체의 주소
     this : 객체의 주소

     컴파일러에 의해서 자동으로 추가가 됩니다.
     우리가 실제로 매개 변수로 넣어주는 것보다 하나 더 추가가 됩니다.
     이렇게 하면 호출된 멤버 함수는 자신을 호출한 객체가 무엇인지 정확하게 알 수 있습니다.
    */

    /** this포인터는 언제 사용할까요? */

    /**
    1. 클래스의 멤버 변수와 매개 변수의 이름이 같을 때 사용할 수 있습니다.
    테스트를 위해서 Student2라는 이름의 클래스를 정의해 줍니다.
    */

    /**
    2. 객체 자신의 주소를 반환할 때 사용할 수 있습니다.
    테스트를 위해서 Student3라는 이름의 클래스를 정의해 줍니다.
    */

    /** 문장을 추가해 줍니다. */
    Student3 student3(2);

    cout << "student3의 주소값 : " << &student3 << endl;
    cout << "" << endl;

    cout << "student3의 주소값 : ";
    student3.SetInfo();

    cout << "" << endl;

    /**
    this를 이용해서 출력한 값과 &student3 의 값이 같은 것을 알 수 있습니다.
    this는 자기 자신을 가리키는 포인터 입니다.
    */
    Student3 student4(2);
    cout << "student4의 주소값 : " << &student4 << endl;
    cout << "this의 주소값 : ";
    student4.SetInfo();
    cout << "" << endl;

    /**
    this포인터는 메모리에 생성된 객체 자신을 가리키는 포인터입니다.

    왜 this포인터를 만든 것일까요?
    클래스의 멤버 변수들은 객체가 생성되어질 때 마다 메모리에 할당이 됩니다.
    함수와 같이 크기가 큰 것들은 메모리에 굳이 반복해서 할당할 필요가 없습니다.
    함수를 메모리에 한 번만 할당해 놓고, 각 객체의 this포인터를 함수에 넘겨서
    어떤 객체가 함수를 호출했는지 알게 하는 것입니다.
    */

    //   *this는 뭘까요? 

    /**
    this포인터가 가리키는 주소의 실제값을 의미합니다.
    문장을 추가해 줍니다.
    */
    int intValue1 = 30;
    int* intPtr1 = &intValue1;
    cout << "*intPtr1 : " << *intPtr1 << endl;

    /**
    *intPtr1는 출력하면 30이 나옵니다.
    이것은 *intPtr1이 가리키는 값을 참조하기 때문입니다. 포인터의 참조입니다.
    int& intRef1 = *intPtr1;는
    int& intRef1 = intValue1;으로 생각할 수 있습니다.
    참조자는 포인터가 아닙니다. 별명입니다.

    int* (&intRef2) = intPtr1;는
    intPtr1이 가리키는 주소값을 받는 상황임에도 당연히 포인터로 받아야 하지만
    intRef2는 참조값으로 받는 것도 가능합니다.
    단 intRef2는 참조 변수이지만 포인터로 전달 받기 때문에 별도의 포인터 주소 값을 가지게 됩니다.
    */
    int& intRef1 = *intPtr1;
    int* (&intRef2) = intPtr1;

    /**
    참조자는 포인터가 아닙니다.
    *intRef1 : 참조자는 포인터가 아니니 역참조 연산자로 포인터가 가리키는 값을 알 수 없습니다.
    &intRef1 : 참조자는 포인터가 아니니 참조자가 가리키는 주소값을 알기 위해서는
            주소 연산자를 사용합니다.
    */
    // cout << "intRef1 value : " << *intRef1 << ", intRef1 address : " << &intRef1 << endl; // (X)
    cout << "intRef1 value : " << intRef1 << ", intRef1 address : " << &intRef1 << endl;
    cout << "" << endl;

    /**
    this는 자기 자신의 객체를 가리키는 포인터 변수입니다.
    *this를 확인해 보기 위해서 Lion이라는 이름의 클래스를 정의해 주도록 합니다.
    */

    /** 문장을 추가해 줍니다. */
    Lion lion1;
    /** 자기 자신을 출력해 봅니다. */
    lion1.PrintThis();
    cout << "" << endl;

    /** 참조자 변수 선언하고 참조자 리턴 받습니다. */
    Lion& lionRef = lion1.ReturnThisAsReference();
    /** 참조자의 자기 자신을 출력해 봅니다. */
    lionRef.PrintThis();

    /**
    this는 자기 자신을 가리키는 키워드이고

    포인터 변수에 역참조 연산자(*)를 붙여주면 포인터 변수가 가리키는 실제값입니다.
    객체일 때는 포인터 변수가 가리키는 객체의 멤버 변수, 멤버 함수를 가리킵니다.
    *this 자기 자신이 가리키는 값(멤버 변수, 멤버 함수)입니다.
    포인터의 참조 개념입니다.

    this는 자기 자신을 가리키는 포인터이고, *this 는 자기 자신의 객체 자체입니다.
    */
    cout << "lion1의 주소값 : " << &lion1 << endl;
    cout << "lionRef의 주소값 : " << &lionRef << endl;

    cout << "" << endl;

    /** 다음 테스트를 위해서 Tiger라는 이름의 클래스를 정의해 주도록 합니다. */

    /** 문장을 추가해 줍니다. */
    Tiger tiger1("Korea");

    Tiger* ReturnThis1 = &tiger1.ReturnThis1();
    Tiger ReturnThis2 = tiger1.ReturnThis2();
    Tiger* ReturnThis4 = tiger1.ReturnThis4();

    cout << "ReturnThis1 : " << ReturnThis1 << endl;
    cout << "ReturnThis2 : " << &ReturnThis2 << endl;
    cout << "ReturnThis4 : " << ReturnThis4 << endl;

    ReturnThis1->SetName();
    ReturnThis2.SetName();
    ReturnThis4->SetName();
}

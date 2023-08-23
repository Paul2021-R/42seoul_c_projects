# Coplien form in C++ 
Named Constructor Idiom 으로써 알려진 클래스들을 정의하기 위한 일련의 컨벤션 방식이다. 
좋은 소프트웨어 엔지니어링 습관, 예를 들어 캡슐화, 모듈화, 재 사용 가능한 코드 등을 촉진하기 위한 디자인 패턴이다. 
Coplien 양식은 다음 핵심 요소들로 구성되어 있다. 

1. 클래스는 public, private 영역에 대하여 생성자를 갖고 있다. private 생성자는 내부 목적을 위해 사용된다. 
2. 클래스는 정적 factory method 를 갖고있다. 종종 named constructor 라고 불리는 것이며, 이는 클래스의 인스턴스를 생성, 호출자에게 그것을 반환하는 역할을 한다. 이러한 정적 메서드들은 종종 create() 혹은 getInstance()라고 불린다. 보통 전형적으로 friend 함수로 지정되어 있으며, 이를 통해 private 생성자에 접근하는 것이 가능해지도록 설정된다. 
3. 클래스는 private 소멸자를 갖고 있다. 이는 클래스의 인스턴스를 직접적으로 제거하는 것이 사용자가 하지 못하도록 만드는 역할을 한다. 

```cpp
class Example {
public:
    static Example create(int x) {
        return Example(x);
    }

    // Public methods
    int getValue() const {
        return value;
    }

private:
    // Private constructors and destructor
    Example(int x) : value(x) {}
    ~Example() {}

    // Private member variables
    int value;
};

```

# const keyword 의 위치에 대해

C++ 에서는, 데이터 매개변수의 타입 전후에 있는 const 키워드 위치는 코드의 체계 상에서 어떠한 영향을 주지 않는다. 이는 개인의 취향이나 코딩 스타일의 문제라고 보면 된다. 


# 비 const 참조에 대한 초기값 lvalue 여야 한다 라는 메시지를 받았을 때 알아야 할 것

C++ 레퍼런스 타입에 대한 초기화 규칙이 존재한다. 
레퍼런스가 상수인지 비상수인지에 따라 다르다. 비 상수 레퍼런스는 lvalue 만 초기 값으로 가질 수 있다. 

예를 들어 nonConstRef는 비상수 레퍼런스이므로 lvalue 인 x를 초기 값으로 가져야 한다. 

여기서 lvalue란 메모리 주소를 갖는 변수나 객체를 의미한다. 즉, 공간에 제대로 할당된 객체를 의미한다.

```cpp
int x = 5;
int& nonConstRef = x; // 이건 가능 
```

하지만 아래와 같은 코드에서 'nonConstRef'에 10이라는 숫자를 바로 할당하면, lvalue 가 아니므로 컴파일러는 에러를 발생시킨다. 

```cpp
int& nonConstRef = 10; // error 
```

즉, 기본적으로 비 상수인 상태에서 레퍼런스를 변수를 작성하게 되면, 해당 내용은 컴파일러에의해 알아서 원본 메모리 저장소에있는 변수로 변환이 이루어진다. 그런데 실제 10은 현재 literal 로 stack에 저장되는 비상수형 변수가 아니기 때문에, 컴파일 과정에서 원본 포인터 연산으로 자동 변경을 시켜주지 못한다. 따라서 에러를 발생시키게 된다. 

따라서 class 에 대해서 본다고 할 때 인스턴스& 를 요구하는 operator= 에서는 return 값을 전달할 때, 컴파일 되는 과정에서 특정 위치를 가리켜야 하고, this 는 개체 값 자체를 의미하는 예약어 이므로, `*this`가 오는게 정상이다.이는 this 예약어는 -> 를 사용하고, 즉, this는 현재 클래스의 멤버 변수나 함수의 포인터 역할을 한다는 것이기에 실제 데이터를 가리키고 있는 변수가 아니다. 따라서 이는 lvalue가 아닌 것이므로 rvalue일것이다. 따라서 레퍼런스에 넣으려면 그것이 가리키는 실제 this가 저장한 메모리 값인 클래스 데이터위치를 가리켜야 한다. 

이와 반대로 상수 레퍼런스 는 lvalue, rvalue(메모리 주소를 갖지 않는 일시적인 값) 모두를 담을 수 있다. 
```cpp
const int& constRef1 = x; // 가능
const int& constRef2 = 10; // 가능
```

순수 가상 함수가 아닌 경우에는 해당 함수 자체를 지정해줘야한다. 

# canonical form 

canonical form 이란 정이된 멤버 함수 혹은 선언들의 일련의 형태를 나타낸다. 캐노니컬 form의 클래스는 `기본생성자`, `소멸자`, `복사 생성자`, `복사 할당 연산자`, `이동 생성자`, `이동 할당 연산자`를 포함하고 있어야 한다. 

구적으로 이러한 멤버 함수들을 정의내리거나, 선언함으로써 클래스는 동적 할당에서 조중 받으며 관리되거나, 객체의 오너십을 소유한체 적절한 관리가 가능해진다. 이것은 클래스가 사용하고, 관리되기 쉽다는 것을 보장해주며, 다른 문맥속에서도 예상된 대로 행동할 것이라는 것을 보장한다. 

메모리 자원을 관리하거나, 파일을 다루는 등의 클래스들을 위한 이러한 멤버 함수들을 구현하는 것에서 추천하는 디자인 가이드 라인의 다섯 번째 룰이다. canonical form 상에서 여섯번째 멤버 함수는 복사 생성자, 그리고 복사 할당 연산자를 포함하는데, 이는 정의하거나 클래스에 필요에 따라 delete 될 수도 있다. 

이동 생성자(move constructor) : 
C++ 에서 이미 존재하는 객체의 자원을 빼앗음으로서 새로운 객체를 생성하는 특수한 생성자이다. 이는 원본 객체에서 더 이상 필요시 되지 않거나, 혹은 소멸되기 직전에, 또 다른 객체에 자원의 소유권을 이전하는 형태로 구현된다. 해당 생송자는 다음 형태의 문법으로 구현된다. 

```cpp
class Example {
public:
    // Move constructor
    Example(Example&& other) {
        // Move the resources from the other object to this object
        // ...
    }
};
```

이 예시, 이동 생성자는 Example&& other 에 언지된 동일 클래스의 또다른 객체의 레퍼런스인 rvalue reference를 취한다. 이동 생성자 내부에서, 다른 객체의 리소스는 move semantics라고 불리는 특수한 기술을 활용하여 현재 객체로 이동된다. 이것은 두개의 객체 사이에서 포인터 혹은 다른 데이터를 스왑하는 것을 포함하고, 그래서 그 결과 최근 객체는 다른 객체에 의해 소유된 이전 리소스의 소유권을 현재 객체가 갖게 된다. 

canonical form의 클래스 예시는 다음과 같다. 

```cpp
class Example {
public:
    // Default constructor
    Example() {}

    // Destructor
    ~Example() {}

    // Copy constructor (deleted)
    Example(const Example&) = delete;

    // Copy assignment operator (deleted)
    Example& operator=(const Example&) = delete;

    // Move constructor
    Example(Example&& other) {
        // Move the resources from the other object to this object
        // ...
    }

    // Move assignment operator
    Example& operator=(Example&& other) {
        if (this != &other) {
            // Move the resources from the other object to this object
            // ...

            // Release the resources from the other object
            // ...
        }
        return *this;
    }
};
```

이 예시에서 클래스 Example 은 기본 생성자, 소멸자를 기본적으로 선언하고 있다. 그리고 복사 생성자와 복사 할당 연산자는 deleted 되어 있다. 이는 Example 객채의 사본을 생성할 필요가 없다는 것을 의미합니다. 

이 클래스는 이동 생성자, 이동 할당 연산자가 정의 되어 있으며, 하나의 객체의 자원을 또 다른 객체로 효율적으로 이동된다. 이동 생성자, 이동 할당 연산자는 move semantics로 구현되어 있다. 
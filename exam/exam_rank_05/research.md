# Coplien form in C++ 
Named Constructor Idiom 으로써 알려진 클래스들을 정의하기 위한 일련의 컨벤션 방식이다. 
좋은 소프트웨어 엔지니어링 습관, 예를 들어 캡슐화, 모듈화, 재 사용 가능한 코드 등을 촉진하기 위한 디자인 패턴이다. 
Coplien 양식은 다음 핵심 요소들로 구성되어 있다. 

1. 클래스는 public, private 영역에 대하여 생성자를 갖고 있다. private 생성자는 내부 목적 목적을 위해 사용된다. 
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
# cpp_module_oo
Assignment name : cpp_module_00
Expected files : Warlock.cpp, Warlock.hpp

Warlock 클래스를 만들자. 이 클래스는 Coplien의 형태로 존재 해야 한다. 

이 클래스는 다음 private attributes 들을 갖고 있다 : 
* name(string) 
* title(string)

이것들은 private 이므로, 이에 대응하는 getter들이 있어야 한다. 
- getName, const string 을 반환한다. 
- getTitle, const string 을 반환한다. 

이 두 함수들은 constant Warlock 상에서 호출될 수 있어야 한다. 

다음 setter들도 생성되어야 한다. 
- setTitle, const string 을 레퍼런스로 취하고, void 반환타입을 갖는다. 

당신의 Warlock 은 또한 Coplien의 형태에서 요구되는 것을 무엇이든지 갖고 있어야 한다. 이러한 룰 상에서 생성자는 name과 title을 갖고 있어야 한다. 당신의 Warlock은 복사가 불가능해야하고, 복사 할당이 되지 않거나 혹은 name, title이 없이 인스턴스화 되는 것은 불가능 하다. 

For example : 

Warlock bob; // compile x
Warlock bob("Bob", "the magnificent"); // compile o
Warlock jim("Jim", "the nauseating"); // compile o
bob = jim; // compile x
Warlock jack(jim); // compile x

생성 될 때, Warlock은 이렇게 말한다 : 
`<NAME>: This looks like another boring day.`

물론, 이름이나 타이틀과 같은 임의의 값을 사용할 때, 출력에서, 당신은 적절한 값으로 바꿔야 하며 꺽쇠는 빼야 한다. 

Warlock 이 죽었을 때도, 이렇게 말한다 : 
`<NAME>: My job here is done!`

우리의 Warlock 은 반드시 자기 스스로를 소개할 수도 있어야 하고, 그것의 전능함을 자랑해야 한다. 

그래서 당신은 다음 함수도 작성해야 한다. 
- void introduce() const;

이 함수는 다음과 같이 출력 한다. :
`<NAME>: I am <NAME>, <TITLE>!`

여기에 메인 함수들 그리고 이에 따른 출력의 예시가 있다. 

```cpp
int main()
{
  Warlock const richard("Richard", "Mistress of Magma");
  richard.introduce();
  std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

  Warlock* jack = new Warlock("Jack", "the Long");
  jack->introduce();
  jack->setTitle("the Mighty");
  jack->introduce();

  delete jack;

  return (0);
}
```

```shell
~$ ./a.out | cat -e
Richard: This looks like another boring day.$
Richard: I am Richard, Mistress of Magma!$
Richard - Mistress of Magma$
Jack: This looks like another boring day.$
Jack: I am Jack, the Long!$
Jack: I am Jack, the Mighty!$
Jack: My job here is done!$
Richard: My job here is done!$
~$
```


- - -
# cpp_module_01
Assignment name : cpp_module_01
Expected files : Warlock.cpp, Warlock.hpp ASpell.hpp ASpell.cpp
									ATarget.hpp ATarget.cpp
									Fwoosh.hpp Fwoosh.cpp
									Dummy.hpp Dummy.cpp

Warlock 클래스 상에서, switch 문장은 금지된다. 그리고 이것의 사용은 -42의 결과를 나타낼 것이다. 

Coplien의 폼 형태로 Aspell 이라는 추상 클래스를 만드시오. 다음 protected attribute 들을 가저야 한다 : 
- name(string)
- effects(string)

양 속성 모두 getter가 존재 해야 하며(getName, getEffects) string을 리턴한다. 

또한 ASpell을 가리키는 포인터를 반환하는 복사 순수 메소드를 추가해라. 
이러한 함수들 모두는 상수 객체 상에서도 호출이 되어야 한다. 

ASpell 은 name, effects를 취하는 생성자를 갖고 있다. 

이제 당신은 Coplien 의 양식에 따른 ATarget 이라는 추상 클래스를 생성하라. type 속성을 갖고 있는데 이는 string 이고, 이와 연계된 getter, getType으로 const string 레퍼런스를 반환해야한다. 

이 클래스는 ASpell 과 유사한 방식이며, 동일하게 clone() pure 메소드를 가진다. 
모든 이러한 함수들은 상수 객체에서도 호출이 되어야 한다. 
이 클래스는 type을 취하는 생성자가 있어야 한다. 

이제 당신의 ATarget에 `getHitBySpell` 함수를 추가해라. 이는 constant ASpell 의 레퍼런스를 취한다. 

이 함수는 다음처럼 출력한다. : 
`<TYPE> has been <EFFECTS>!`

`<TYPE>`은 그 ATarget의 타입을, `<EFFECTS>`는 ASpell의 getEffects 함수의 반환값이다. 

마침내 당신의 ASpell 클래스는 constant ATarget의 레퍼런스를 취하는 launch 함수를 추가한다. 
이것은 간단하게 전달된 객체의 getHitBySpell 을 호출하고, 매개변수로 현재의 인스턴스를 전달한다. 

이 모든 것이 끝나면, Fwoosh 라고 불리는 ASpell의 구현물을 작성하시오. 그것의 기본생성자는 name을 "Fwoosh"로 설정하며, effects에 "fwooshed" 를 취한다. 물론, 당신은 clone() 메소드도 구현해야 한다. Foowsh의 경우, 새로운 Fwoosh 객체의 포인터를 반환해야 한다. 

동일한 방식으로, Dummy 라는 이름의 구체적인 ATarget을 생성하시오. "Target Practice Dummy" 의 type을 가진다. 당신은 여기서도 clone() 메소드를 구현해야 한다. 

Warlock 의 다음 멤버 함수들을 추가하시오
- learnSpell, ASpell 의 포인터를 취한다. Warlock이 spell 을 배우도록 만든다. 
- forgetSpell, spell의 이름에 대응하는 string 취하고, Warlock이 이를 잊게 만들어야 한다. 만약 spell 로 알려지지 않은 것이라면, 아무런 일도 일어나지 않는다. 
- launchSpell, spell의 이름에 대응하는 string, ATarget의 레퍼런스를 취한다, 선택된 타겟에 spell을 실행히킨다. 만약 알려지지 않은 spell이라면 아무런 작업이 일어나지 않는다. 

당신은 Warlock이 spell을 저장할 새로운 속성이 필요할 것이다. 몇몇 type들은 bill에 맞고, 이는 당신이 선택하는 최적의 것으로 만들면 된다. 

아래는 테스트용 main문이며 예상되는 출력이다 : 
```cpp
int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
}
```

```shell
~$ ./a.out | cat -e
Richard: This looks like another boring day.$
Richard: I am Richard, the Titled!$
Target Practice Dummy has been fwooshed!$
Richard: My job here is done!$
```
- - - 
# cpp_module_02
Assignment name : cpp_module_02
Expected files : Warlock.cpp, Warlock.hpp ASpell.hpp ASpell.cpp
									ATarget.hpp ATarget.cpp
									Fwoosh.hpp Fwoosh.cpp
									Dummy.hpp Dummy.cpp
									Fileball.hpp Fireball.cpp
									Polymorph.hpp Polymorph.cpp
									BrickWall.hpp BrickWall.cpp
									SpellBook.hpp SpellBook.cpp
									TargetGenerator.hpp TargetGenerator.cpp

Warlock 클래스에서, SpellBook, 그리고 TargetGenerator 클래스들 에서는 switch 문은 금지되며, 사용시 -42 받음!

다음 두개의 spell을 만들며 Foowsh와 동일한 구조를 가진다 : 
- Fireball(Name: "Fireball", Effects: "burnt to a crsip")
- Polymorph(Name: "Polymorph", Effects: "turned into a critter")

여기에다가, warlock은 dummy 에다가만 공격을 하지 않을것이니, 그를 위한 새로운 타겟을 만들어 봅시다. BrickWall(Type: "Inconspicuous Red-brick Wall")

이제 SpellBook class 를 만들고, 인정된 형태로, 이는 복사 불가이며, copy에 의해 인스턴스화도 되지 않는다. 이 클래스는 다음 함수들을 갖고 있다. 
- `void learnSpell(ASpell *)` spell을 book에 복사한다. 
- `void forgetSpell(string const &)` book 에서 spell 삭제하는데, 없으면 하지 않는다. 
- `ASpell* createSpell(string const &)` 특정 타입의 타겟을 생성한다. 

이제 다됬네요. 테스트 메인문을 보고 당신의 답들이 작동하는지 점검하세요. 
```cpp
int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  richard.introduce();
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);
}
```

```shell
~$ ./a.out | cat -e
Richard: This looks like another boring day.$
Richard: I am Richard, Hello, I'm Richard the Warlock!!$
Inconspicuous Red-brick Wall has been turned into a critter!$
Inconspicuous Red-brick Wall has been burnt to a crisp!$
Richard: My job here is done!$
~$
```



- - - 

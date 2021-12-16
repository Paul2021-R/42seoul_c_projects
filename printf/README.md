# ft_printf(내용 이해 중)

[](https://cdn.intra.42.fr/pdf/pdf/35908/en.subject.pdf)

- [ ]  모르는 단어 정리
- [ ]  printf 관련 매뉴얼 정독
- [ ]  추가적으로 허용된 모르는 함수 정리
- [ ]  로직 짜기
- [ ]  실제 사용 방식 고려하여 빌드 시작
- [ ]  평가 후 보너스 고려

### Chapter I Introduction

C에서 printf 함수의 다재다능함은 우리들에게 훌륭한 프로그래밍 연습이 됩니다. 이 프로젝트는 평이한 난이도를 가집니다. C 에서 가변 함수를 발견하게 해줄 겁니다. 

성공적인 `ft_printf` 의 열쇠는 잘 구조화된, 그리고 확장성이 좋은 코드입니다. 

### Chapter II Common Instructions

기존 C 프로그래밍 관련 공통 사항임!

- 너의 프로젝트들은 당연히 놈을 지켜야 한다. 보너스 파일이나 함수도놈 지켜야 하고, 안 지키면 0점.
- 당신의 함수들이 지정되지 않은 행위들과는 별개로 예상치 못하게 종료되면 안됨. 만약 발생시 당신의 프로젝트는 0점이다.
- 모든 heap 은 메모리 공간에 적절하게 할당되고 free 되야 한다(필요시). 누출은 x
- 필요시에는 소스 파일들을  컴파일 할 Makefile 을 제출할 것. 이때 gcc -Wall -Wextra -Werror는 포함시킬 것. relink 하면 안된다
- 보너스 제출 시, 메인 프로젝트 부분에서 금지된 다양한 헤더, 라이브러리 혹은 함수들을 추가시키는 Makefile에 보너스 룰을 추가해야한다. 보너스는 반드시 다른 파일 안에 존재해야 한다. (파일명)_bonus.{c /h} 평가는 각각 진행됨.
- 프로젝트에서 자체 라이브러리(libft) 사용이 허가 될 시, 그것의 소스 및 Makefile libft 에 포함되어 있어야 함. 그리고 해당 프로젝트는 반드시 그  Makefile을 이용하여 컴파일 되어야 한다.
- 테스트 프로그램을 만들 것을 권장함. (제출 안해도)
- 나머지 동료평가 후 기계평가 되는 등의 것은 기존과 동일 한 듯.

### Chapter III Mandatory part

| Program name | libftprintf.a |
| --- | --- |
| Turn in files | *.c, */*.c, *.h, */*.h, Makefile |
| Makefile | all, clean, fclean, re, bonus |
| External fucts. | malloc, free, write, va_start, va_arg, va_copy, va_end |
| Libft authorized | yes |
| Description | ft_printf, 실제 printf 를 모방한 함수를 담은 라이브러리를 작성하라. |
- ft_printf 의 프로토타입은 반드시 `int ft_printf(const char *,...)`; 이어야 한다.
- libc의 printf 함수를 recode 해야 한다.
- 실제 printf 처럼 buffer 관리를 하진 않는다.
- 다음 conversions를 처리할 것이다. : cspdiuX%
- 함수는 실제 printf와 비교될 것이다.
- 라이브러리 작성을 위해 `ar` 을 반드시 사용하고, `libtool` 사용은 금지된다.

요구되는 변환에 대한 개요 

- %c : 한글자를 표현한다.
- %s : 문자열을 표현한다.
- %p : void * 포인터 인자를 16진법으로 표시한다.
- %d : 10진법의 수를 표시한다.
- %i : 10진법의 정수를 표시한다.
    
    `an integer in base 10` 위와 차이점 알아야 할듯 
    
- %u : unsigned 십진수를 표시한다.
- %x : 16진법의 숫자를 소문자로 표시한다.
- %X : 16진법의 숫자를 대문자로 표시한다.
- %% : 퍼센트를 표시한다.

> 💡 더 자세한 정보는 `man 3 printf` / `man 3 stdarg`
> 

### Chapter IV Bonus part

- 만약 필수 파트가 완벽하지 않다면 보너스는 결코 고려하지 말것!
- 모든 보너스를 할 필요는 없습니다.
- 다음 플래그 의 조합을 처리하십시오 : `-0.` 그리고 모든 conversions와 함께 최소 범위
- 다음 플래그들을 모두 처리하십시오 : `#` `_` `+` (하나는 여백입니다.)

> 💡 만약 당신이 보너스들을 계획 한다면, 당신은 시작부터 단순한 접근법을 피하기 위해 그들을 어떻게 할지에 관해 고려해야 합니다.
>

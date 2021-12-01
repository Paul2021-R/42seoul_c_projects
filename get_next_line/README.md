# Get Next Line(진행중)

[https://cdn.intra.42.fr/pdf/pdf/35332/en.subject.pdf](https://cdn.intra.42.fr/pdf/pdf/35332/en.subject.pdf)

### 핵심 요약 : FD 로부터 읽은 라인 한줄을 반환하는 함수를 만들어내는 것이다.

## Chapter 1

### Goals

해당 프로젝트는 당신의 컬렉션에 매우 편리한 함수를 추가 시켜 줄 뿐만 아니라, C 프로그래밍의 매우 흥미로운 개념을 배울 수있게 해줍니다. : `Static variables`

## Chapter 2

### Common Instructions

- 당신의 프로젝트는 반드시 놈을 기준으로 쓰여져야 한다. 만약 보너스 파일, 함수가 있고 그들이 놈 에러 발생시 0점을 받게 됩니다.
- 당신의 함수들은 undefined behavior 들로부터 구분되어 예상치 못한 종료를 하면 안됩니다. 만약 발생 시 기능 비정상으로 고려되고, 0점을 받게 됩니다.
- 모든 힙 할당 메모리 공간은 적절하게 free 되야합니다(필요시). 메모리 누수는 용납되지 않는다.
- 만약 과제가 그것을 필요로 할때, 반드시 Makefile 이 컴파일 할 소스 파일들과 함께 제출되어야 합니다.(옵션 flag -Wall -Wextra Werror, cc 사용하고, relink는 허용되지 않음)
- Makefile은 최소한  $(NAME), all, clean, fclean, re 룰은 담고 있어야 합니다.
- 당신의 프로젝트에서 보너스를 제출 시에는, 반드시 bonus 룰을 당신의 Makefile에 포함시켜야 하며, 그것은 금지된 다양한 헤더, 라이브러리 함수들을 더할 것입니다. 보너스 들은 다른 파일이름 (_bonus.{c/h})으로 되어 있고, 평가는 별개로 진행됩니다.
- 만약 당신의 libft를 사용하기가 프로젝트 상에 허락된다면, 반드시 그것의 소스 그리고 Makefile이 libft 폴더 안에 복사해두어야 합니다. 반드시 당신의 프로젝트의 Makefile은 그것의 Makefile을 사용함에따라 라이브러리(libft)를 컴파일 하고 프로젝트를 컴파일 해야 합니다.
- 우리는 당신이 테스트 프로그램을 만드는 것을 장려합니다. 이 작업이 제출될 필요가 없거나, 평가 될 것이 아님에도... 해당 작업은 당신의 작업과 동료들의 작업을 쉽게 검사하는 기회를 얻게 될 것입니다. 디펜스 활용에도 유효합니다. 실제로 디펜스 동안 당신은 당신의 테스 혹은 동료의 당신이 평가중인 테스트를 자유롭게 될 수 있습니다.
- 당신의 작업을 할당된 git repository로 제출하십시오. git reposigory 안에 있는 작업물에 대해서 평가될 것입니다. 만약 Deepthought 가 당신의 작업물에 평가가 할당되면 동료평가 후 진행이 마무리 될 것입니다. 만약 에러 발생 시 그 평가는 멈출 것입니다.

## Chapter 3

### Mandatory Part - Get_next_line

| Function name | get_next_line |
| --- | --- |
| Prototype | char *get_next_line(int fd); |
| Turn in files | get_next_line.c, get_next_line_utils.c, get_next_line.h |
| Parameters | File descriptor to read from  |
| Return value | Read line : correct behavior
NULL : Nothing else to read or an error occurred  |
| External functs. | read, malloc, free |
| Description | Write a function which returns a line read from a file descriptor |
- get_next_line 이라 불리는 루프 함수는 당신이 file descriptor 한 줄의 텍스트를 그것의 끝 부분까지 즉시 읽는 것을 허락합니다.
- 당신의 함수는 반드시 읽은 그 줄을 반환해야 합니다. 만약 아무것도 읽을 것이 없거나, 에러가 발생하면 NULL을 반환합니다.
- 표준 출력으로부터 그것을 읽을 때, 그리고 파일로부터 읽을 때 당신의 함수의 행동이 확실하게 되는지 확인하십시오.
- libft는 이 프로젝트에선 허용되지 않습니다. 
반드시 `get_next_line_utils.c` 파일을 추가하십시오. 이 파일은 get_next_line 이 작동하는데 필요시되는 함수들을 담고 있습니다.
- 당신의 프로그램은 반드시 `-D BUFFER_SIZE=xx` 플래그와 함께 컴파일 되어야 하며, 해당 플래그는 당신의 get_next_line  안에서 호출을 읽고 사이즈 버퍼로 사용될 것입니다. 해당 값은 당신의 평가자, 뮬리넷에 의해 수정될 것입니다.
- 이 프로그램은 이 방식으로 컴파일 될 것입니다.
    
    ```bash
    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c.
    ```
    
- 당신의 read는 표준 출력으로부터 혹은 파일로부터 읽혀진 읽힘에 편집 동안 정의된 BUFFER_SIZE를 반드시 사용합니다.  이 값은 목적을 평가 목적으로 평가동안 수정될 것입니다.
- get_next_line.h 파일에는 반드시 최소한 get_next_line의 함수의 프로토타입이 최소한 존재해야합니다.
- wild card
    
    💡  혹시 BUFFER_SIZE가 9999 일때 작동합니까? 1일 땐? 10,000,000일 땐? 왜 그런지 알고 있나요?
    
    💡  당신은 반드시 get_next_line이 호출 되는 가능한 각각의 짧은 시간동인 읽도록 해봅시다. 만약 개행을 만난다면, 당신은 최근의 줄을 반환해야합니다. 전체 파일을 읽지 말고, 각 라인을 처리하십시오. 
    
    💡   테스트 없이 프로젝트를 반환하지 마세요. 수많은 돌려볼 테스트가 존재하고, 당신의 토대를 보호할. 파일로부터 읽는 것, 표준출력, redirection으로부터 읽는 것을 시도해보세요. 표준 출력에 개행을 보낼때 당신의 프로그램을 어떻게 작동하나요? 그리고 Ctrl-d를 하면? 
    
- lseek 은 허용되지 않는 함수이며, 파일 읽기는 반드시 한 줄 씩 진행되어야 한다.
- get_next_line은 두번의 호출 사이에, 동일한 FD가 최초 FD로부터 모든 것을 읽기 전 에 다른 파일로 바뀐다면, undefined behavior를 갖게 된다.
- 바이너리 파일로부터 읽을 때 get_next_line은 undefined behavior를 가진다.
- 전역변수 활용은 금지된다.
- (중요)반환 라인은 개행문자를 포함해야한다. 대신, 파일의 끝에 도달한 경우, 개행문자는 존재하지 않는다.
- 정보
    
    성공적인 시작을 위해 static variable 에 대해 알아봐라 
    
    [Static variable - Wikipedia](https://en.wikipedia.org/wiki/Static_variable)
    

## Chapter 4

### Bonus part

get_next_line 프로젝트는 직선적이며, 보너스를 위해 매우 작은 여지가 남아 있다. 하지만 우리는 많은 상상력을 당신이 갖고 있음을 확신합니다. 

만약 필수 파트를 성공적이었다면 더 나아가 보너스 파트를 완수 하십시오. 

만약 필수 파트가 완벽하지 않다면, 그저 명료하게, 보너스들 없는 것에 대한 숙고로 넘어가시기길.

이 파트를 위해 _bonus.c\h로 끝나는 필수 3가지 파일을 제출하세요. 

- 하나의 static variable 로 get_next_line 성공시키기
- 당신의 get_next_line으로 여러 file descriptors 를 다룰 수 있게 하십시오. 예를들면...
    - fd가 3, 4, 5가 읽기 접근이 가능할 때, 당신은 get_next_line을 일단 3, 그리고 4, 이후 다시 3 그리곤 5.. 등등 descriptors의 각각 쓰레드에서 읽는 것을 잃지 않은 채로로 호출할 수 있다. (리스트를 활용해야함)

## Reference

[파일 디스크립터(File Descriptor)란?](https://code4human.tistory.com/123)

[[C]저수준 파일입출력 함수(1)[fd(파일 기술자), open, close]](https://kirkim.github.io/c/2021/02/18/lowfildefunc(1).html)

[read(2) - 파일에서 데이터를 읽기](https://www.it-note.kr/201)

[정적변수(static variable) - 인코덤, 생물정보 전문위키](http://www.incodom.kr/%EC%A0%95%EC%A0%81%EB%B3%80%EC%88%98%28static_variable%29)

[[파일입출력] 2. read()로 파일 읽기](https://sonseungha.tistory.com/279)

[텍스트 파일과 바이너리 파일에 대하여!](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=tipsware&logNo=221353023593)

### 아이디어 정리

**로직 :** 

1. 파일 오픈(이건 뮬넷이 알아서?) — 내가 할 땐 직접 구현이 필요
2. FD보냄
3. FD 를 통해 읽을 내용 긁어오기 (구분자가 있어야함) 
    1. 정상적인 경우, 한 문장의 종료와 함께 개행문자를 고려하여 malloc  을 해야 하며,  문제시 free를 진행함. 
    2. 고려 ) 버퍼는 유동적임. 즉, 버퍼를 넘치는 경우 고려해야함 
    3. 고려2 ) 파일이 읽는 과정에서 EOF를 만났을 때
        1. 해당 경우 개행하지 않는다. 
    4. 고려 3) 중간에 FD가 변경되거나, FD는 같은데 다른 파일이 들어왔을 때
    5. 고려 4) 바이너리 파일은 읽으면 안된다. → 어떻게 구분 하는가? 
4. 리턴 하고 마무리... 

**필요 항목** 

1. 데이터가 담기는 영역을 할당, 진행하고, fd의 변동에 따라 새롭게 구현되는 구조가 되어야 한다.(그러니 아예 데이터 구조 항목을 리스트로 만들어야 하고, 이에 대한 기믹을 추가해야함. )
2. 파일 FD를 파악하고, get_next_line함수로 입력시키는 메인 함수 구현 
3. 허용되는 함수가 read 뿐이므로(사실상) 이것의 활용 방법에 대해 확실하게 기억하고 있어야 할듯 하다. 
    1. 그 외의 사실상 허용 영역이 어디까진지를 알아야 한다...더불어 해당 기능을 위한 내장 함수들을 어느정도 전체적으로 파악이 필요

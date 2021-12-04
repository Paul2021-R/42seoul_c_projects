# Get Next Line(진행중)

[https://cdn.intra.42.fr/pdf/pdf/35332/en.subject.pdf](https://cdn.intra.42.fr/pdf/pdf/35332/en.subject.pdf)

## 해야할 일

- [ ]  헤더 파일 작성 하기
- [ ]  txt 파일 입력 가능 main 함수 작성
    - [x]  open 함수 활용한 메인문 구현
    - [x]  stdin 활용한 메인문 구현
- [ ]  get_next_line_utils 함수 구현
    - [x]  strchr
    - [x]  strndup
    - [x]  strlen
- [ ]  get_next_line의 함수 구현
- [ ]  함수 중 모듈화 가능한 함수를  utils  쪽으로 구현 하기
- 테스터 목록
    
    [https://github.com/DontBreakAlex/gnlkiller](https://github.com/DontBreakAlex/gnlkiller)
    
    [https://github.com/Mazoise/42TESTERS-GNL](https://github.com/Mazoise/42TESTERS-GNL)
    
    [https://github.com/mrjvs/42cursus_gnl_tests](https://github.com/mrjvs/42cursus_gnl_tests)
    
    [https://github.com/charMstr/GNL_lover](https://github.com/charMstr/GNL_lover)
    

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
- get_next_line 이라 불리는 함수는 반복문안에서 호출하면 당신이 file descriptor 한 줄의 텍스트를 그것의 끝 부분까지 즉시 읽는 것을 허락합니다.
- 당신의 함수는 반드시 읽은 그 줄을 반환해야 합니다. 만약 아무것도 읽을 것이 없거나, 에러가 발생하면 NULL을 반환합니다.
- **stdin으로부터 그것을 읽을 때, 그리고 파일로부터 읽을 때 당신의 함수의 행동이 확실하게 되는지 확인하십시오.**
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
- 바이너리 파일로부터 읽을 때 get_next_line은 **undefined behavior**를 가진다.
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
4.  read 를 해서 한줄을 읽고, 결국 읽은 내용에서 그 글자수를 읽는 것이 핵심이려나? 
5. 권한설정을 해서 읽을 수 있도록 해야하는데, 그 이상의 권한 셋팅은 하면 안될듯? ⇒ 확인 필요 

### 디펜스 준비

- 파일 디스크립터(FD, File Descriptor)
    - Unix 시스템에서 네트워크 소캣과 같은 파일이나 기타 입/출력 리소스 액세스 하는데 사용하는 추상 표현, 각 파일이나 소캣을 대표하는 정수 형태
        
        질문 ) 소켓이란?[https://reakwon.tistory.com/81](https://reakwon.tistory.com/81)
        
        네트워크 통신을 하는 표준 방법으로 프로세스 간 연결의 종점. 
        
        각 프로세스는 소켓을 가지고, 간단히 말해 ip주소, 포트번호를 갖고 있는 인터페이스이다. 
        
        이를 사용할 때는 리눅스 시스템 상에서 파일로 다뤄지기에 파일 디스크립터를 통해 읽기 쓰기가 가능함. 
        
    - 음이 아닌 정수 형태 (Non-negative integer), 일반적으로 int형식으로 C프로그래밍 언어로 표현된다. = windows 에서는 'File Handle'이라고 불림
    - 0 ~ 2번은 고정되어있음(unistd.h 명시)
        
        ![Untitled](Get%20Next%20Line(%E1%84%8C%E1%85%B5%E1%86%AB%E1%84%92%E1%85%A2%E1%86%BC%E1%84%8C%E1%85%AE%E1%86%BC)%20cd758086df304ef9a8202f0c93ed1126/Untitled.png)
        
    - FD가 숫자인 이유는 file descriptor 테이블의 인덱스이기 때문이다.
    - 파일 오픈 / 소캣 생성 시 부여되는 FD는 3부터 시작 → 현재 사용되는 숫자 중 사용하지 않은 가장 작은 값으로 할당 해준다.
    - open 되어 있는 fd 확인하기
        
        `/proc/"pid"/fd` ← 해당부분에서 ls 시 사용중인 fd확인이 가능하다. 
        
    - file descriptor 테이블의 각 항목은 FD 플래그, 파일 테이블로의 포인터를 갖고 있고, 이 포인터를 이용해 FD를 통해 시스템 파일을 참조할 수 있는 것이다. ⇒ 이러한 FD테이블, 파일 테이블 정보는 직접 수정 불가. `커널`을 통해서 수정된다.
    - FD의 최대값 = OPEN_MAX
        - 프로세스 하나당 최대 OPEN_MAX 개 만큼 파일을 열수 있고, 이는 플랫폼에 따라 다르다.
            
            질문 ) 플랫폼이라는 것이 뭘 의미할까? HW, SW, OS?
            
            질문 ) FOPEN_MAX란? 
            
            fopen으로 최대 열수 있는 파일 핸들러의 수. 
            
        - OPEN_MAX 확인 방법
            1. 터미널에서 getconf 명령어로 확인
                
                ```bash
                getconf OPEN_MAX
                
                /*result*/
                1024
                ```
                
            2. <unistd.h> 의 sysconf()함수로 확인 
                
                ```c
                #include <unistd.h>
                #include <stdio.h>
                
                int	main(void)
                {
                	int	max;
                	
                	max = sysconf(_SC_OPEN_MAX);
                	printf("OPEN_MAX : %d\n", max);
                	max = sysconf(FOPEN_MAX);
                	printf("FOPEN_MAX : %d\n", max);
                	return (0);
                }
                
                /*컴파일 후 결과값*/
                OPEN_MAX : 1024
                FOPEN_MAX : 200809
                ```
                
            
            [OPEN_MAX, 번호,](https://www.javaer101.com/article/2890626.html)
            
            OPEN_MAX추가 자료
            
    - Finally.. FD를 쉽게 생각하면, 파일 혹은 소켓을 생성 시 좀더 편한 대화를 위하여 OS가 만들어 건네주는 꼬리표 같은 것이다.
    
- 저수준 파일입출력 함수 [fd(파일 기술자), open, close]
    - 저수준 파일입출력 함수는 유닉스 기반의 고전입출력함수로 리눅스 기준 `unistd.h` 헤더 파일에 선언되어 있다.
    - 이때, 표준입출력 함수들 `fopen(), fclose() 등등...` 은 버퍼를 사용하지만, 저수준의 경우 버퍼를 사용하지 않는 `비버퍼링`  함수다.
    - 버퍼(buffer)란 어떤 장치에서 다른 장치로 데이터를 송신할 때 일어나는 시간차, 데이터 흐름 속도 차를 조정하기 위한 일시적 데이터 기억 장치이다. 따라서 `저수준입출력함수` 는 이처럼 버퍼를 이용하지 않고 파일 바이트를 그대로 이용하기 때문에 속도가 빠르다는 장점이 있다.
    - 단, 고전함수다 보니 윈도우에서 달라지는 부분 있음. 윈도우에선 `<io.h>` 선언해야한다.
    
    |  |  저수준 파일 입출력 | 고수준 파일 입출력 |
    | --- | --- | --- |
    | 파일 지시자 | int df; | FILE *fp; |
    | 열린 파일 참조 | 파일 기술자를 사용 |  파일 포인터를 사용 |
    | 특징 | 1. 훨씬 빠름
    2. 바이트 단위로 읽고 쓴다
    3. 특수 파일에 대한 접근이 가능하다.
    4. 바이트단위로 입출력함으로 추가적인 기능을 구현해야하는 단점이 있다. 
    (바이트를 적당한 형태의 데이터로 변화하는 함수 등) | 1. 사용하기 쉽다.
    2. 버퍼 단위로 읽고 쓴다.
    3. 데이터의 입출력 동기화가 쉽다.
    4. 여러가지 형식을 지원한다.  |
    | 주요함수 | open, close, read, write, dup, dup2, fcntl, lseek, fsync | fopen, fclose, fread, fwrite, fputs, fgets, fpritf, fscanf, freopen, fseek |
    - 파일 기술자 (fd, FILE Descriptor, 파일 디스크립터) ⇒ 이미 학습했으니 스킵
    - open 함수
        - 파일을 열거나 생성할 때 사용한다.
        - 성공시 fd를 3번부터 순차적으로 (int)자료형으로 반환한다.
        - 실패시 -1을 반환한다.
        - prototype : `int open(const char path, int oflag, [mode_t mode]);`
        - oflag
            - 함수 작동 방식을 결정하는 옵션들
            - `<fcntl.h>` 헤더에 정의되어 있다.
            - 옵션들은 비트 연산자 OR로 결합하여 사용가능. 단, `O_RDONLY, O_WRONLY, O_RDWR` 중 하나는 반드시 지정해야 한다.
                
                ex) `#define WRITE_FLAGS (O_WRONLY | O_CREAT | O_EXCL )
                
            
            | oflag | 설명 |
            | --- | --- |
            | O_RDONLY | 읽기 전용으로 연다 |
            | O_WRONLY | 쓰기 전용으로 연다 |
            | O_RDWR | 읽기 및 쓰기용으로 연다  |
            | O_APPEND | 파일 기록 시 내용을 파일 끝에 추가한다.  |
            | O_CREAT |  존재하지 않으면 새로 생성한다. 셋째 인수 mode도 지정해야 된다.  |
            | O_EXCL | O_CREAT 와 이 옵션을 함께 지정하면 파일이 이미 존재하는 경우에 오류가 발생한다.  |
            | O_TRUNC | 이미 존재하는 파일을 읽기 또는 쓰기 모드로 열었을 때 파일의 크기가 0으로 잘라버린다.  |
            | O_NOCTTY | 열려 있는 장치가 컨트롤링 터미널이 되지 못하도록 한다.  |
            | O_NONBLOCK | 즉시 리턴될 것인지 아니면 장치가 준비될때까지 블록될 것인지 제어한다.  |
        - mode(파일 권한을 설정)>
            - <sys/stat.h> 헤더에 선언되어 있습니다.
            - 소유자 | 그룹 | 기타 사용자|를 r(읽기) | w(쓰기) | x(실행) 을 8진수 단위씩 나눠서 지정할 수 있다.
            - 뿐만아니라 다음과 같이 매크로 선언되어 있는 mode명을 직접 작성해도 된다.
            
            | mode | 설명 |
            | --- | --- |
            | S_IRWXU | 0700, 파일 소유자에게 읽기, 쓰기, 실행 권한 부여  |
            | S_IRUSR | 0400, 사용자에게 읽기 권한 부여 |
            | S_IWUSR | 0200, 사용자에게 쓰기 권한 부여  |
            | S_IXUSR | 0100, 사용자에게 실행 권한 부여 |
            | S_IRWXG | 0700, 그룹에게 읽기, 쓰기, 실행권한 부여 |
            | S_IRGRP | 0400, 그룹에게 읽기 권한 부여 |
            | S_IWGRP | 0200, 그룹에게 쓰기 권한 부여 |
            | S_IXGRP | 0100, 그룹에게 실행권한 부여  |
            | S_IRWXO | 0700, 기타 사용자에게 읽기, 쓰기, 실행권한 부여 |
            | S_IROTH | 0400, 기타 사용자에게 읽기 권한 부여 |
            | S_IWOTH | 0200, 기타 사용자에게 쓰기 권한 부여 |
            | S_IXOTH | 0100, 기타 사용자에게 실행 권한 부여 |
            
            ```c
            /*open 함수 예시*/
            #include <sys/stat.h>        // mode_t형식자
            #include <fcntl.h>           // oflag 옵션,mode 옵션
            #include <unistd.h>          // 저수준함수 open(),close()함수
            #include <stdio.h>           // perror()함수
            #include <stdlib.h>          // exit()함수
            
            int main(void)
            {
            	int fd;
            	mode_t mode;         // 윈도우에서는 mode_t형식자가 없다..
            
            	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; //"0644"와 같다.윈도우에서는 이런 mode플래그가 없는듯하다..
            
            	fd = open("unix.txt", O_CREAT, mode);
            
            	if (fd == -1)        // open에 실패할시 -1을 반환한다
            	{
            		perror("CREAT\n");    // 오류코드를 해석해서 stderr스트림으로 출력해주는 함수이다.
            		exit(1);              // 에러코드 1을 반환하고 프로그램을 정리하고 종료합니다.
            	}
            	close(fd);                    // 파일을 열었으면 꼭 닫아줍니다
            	return (0);
            }
            ```
            
            - open 함수도 파일입출력 함수처럼 에러시에는  `errno` 값이 자동으로 설정됩니다. 그렇기 때문에 `perror함수` 로 오류코드를 해석할 수 있다.
            - `open함수` 로 파일을 열었으면, 반드시 `close함수` 로 파일을 닫아주어야 한다.
    - close 함수
        - prototype : `int close(int fd);`
        - 파일 입출력 작업이 모두 완료되면 반드시 파일을 닫아야 한다.
        - 성공적으로 닫으면 0 반환, 실패시 -1을 반환. (오류코드를 외부 변수 errno에 저장한다)
    - read 함수
        - prototype : `ssize_read(int fides, void *buf, size_t nbytes);`
            - 윈도우에선 int형
        - n바이트 만큼 읽어서 buf에 저장한다. 오류가 발생하면 -1을 반환하고, 성공 시 읽어온 바이트 수를 리턴한다.
        
        ```c
        #include <sys/stat.h>          // mode_t
        #include <fcntl.h>
        #include <unistd.h>            // 윈도우에선 <io.h>헤더
        #include <stdio.h>
        #include <stdlib.h>           // exit함수
        
        #define BUFFER (10)
        
        int main(void)
        {
        	int fd, n1, n2;
        	mode_t mode;      // 윈도우에선 unsigned short 형식자로 바꿔서 사용
        	char buf1[BUFFER];
        	char buf2[BUFFER];
        
        	mode = 0644;             // mode(권한옵션)을 8진수로 저장
        
        	if(!(fd = open("test.txt",O_RDONLY, mode)))
        	{
        		perror("Open");
        		exit(1);
        	}
        	n1 = read(fd, buf, BUFFER - 1);     // 마지막에 '\0'을 넣어주기 위해 "BUFFER - 1"크기로 설정
        	n2 = read(fd, buf2, BUFFER - 1);   // read함수의 오프셋이 이어짐을 확인하기위해 read()함수를 2번실행
        	if (n == -1 || n2 == -1)
        	{
        		close(fd);
        		perror("Read");
        		exit(1);
        	}
        	buf[n1] = '\0';        //read()함수가 읽어들인 값을 반환함을 이용하여 '\0'값을 넣어준다
        	buf2[n2] = '\0';
            
        	printf("n = %d, buf = %s\nn2 = %d, buf = %s\n", n1, buf1, n2, buf2);
        	close(fd);
        	
        	return (0);
        }
        /*---test.txt파일 내용---*/
        abcdefghijklmn
        /*---결과---*/
        n1 = 9, buf1 = abcdefghi
        n2 = 5, buf2 = jklmn
        ```
        
    - write  함수
        - prototype : `ssize_t write(int fildes, const void* buf, size_t nbytes);`
            - 윈도우 int 형
        - n 바이트 만큼 크기를 읽어서 파일 기술자(fd)에 작성한다.
        - 오류 발생하면 -1, 성공 시 수행 성공한 바이트 수를 리턴한다.
        
        ```c
        #include <unistd.h>
        
        int main(void)
        {
        	char str[] = "Hello";
        	write(1, str, sizeof(str));
        }
        ```
        
    - lseek 함수
        - prototype : `off_t lseek(int fildes, off_t offset, int whence);`
            - 윈도우에선 long 형
        - whence
            
            
            | 값 | 설명 |
            | --- | --- |
            | SEEK_SET | 파일의 시작 기준 |
            | SEEK_CUR | 현재 위치 기준 |
            | SEEK_END | 파일의 끝 기준 |
        - 열린 파일 지정자(fd)로부터 offset만큼의 위치를 변경한다. 이때, whence값을 기준으로 offset을 계산합니다.
        - 실패 했을 경우 -1 리턴하고 성공했을 경우 파일의 시작으로부터 떨어진 n바이트 만큼의 offset을 리턴한다ㅏ.
        - 고수준파일 입출력함수에서 `fseek함수` 와 `파일스트림(stream)` 을 받는지 `파일디스크립터(fd)` 를 받는지의 차이만 있을 뿐 동작하는 방식과 쓰임은 비슷하다.
    
- read_deepthought ← 해당 내용 리버스하여서 작동 방식을 알아내면 read의 기능을 더 응용이 될 것 같다.
    
    ```c
    //Prototype
    #include <unistd.h> ssize_t read(int fd, void *buf, size_t count);
    ```
    
    ```c
    //Parameter
    fd      - open(2), creat(2), socket(2), accept(2) 등을 통하여 정상적으로 open한 file descriptor
    buf     - 읽을 데이터를 저장할 메모리 영역(buffer)
    count   - 읽을 size (byte 수)
    ```
    
    ```c
    //Return
    0 보다 큰 수
     - 실제로 읽은 데이터 byte 수.
     - 일반적으로 count와 같은 값을 return하지만, count보다 작은 경우에는 end of file에 도달하였거나, socket통신에서는 수신할 데이터가 아직 도착하지 않은 경우나 peer(상대)에서 socket을 close했을 때입니다. 
    
    0
     - end of file에 도달하여 더 이상 읽을 자료가 없는 경우
    
    -1
     - 오류가 발생한 경우이며 상세한 오류는 errno에 설정됩니다. 
    
    EAGAIN : file을 open할 때에 O_NONBLOCK flag이 설정되었으며, 현재 읽을 데이터가 없어서 read()함수를 바로 return함. 
    
    EAGAIN or EWOULDBLOCK : fd가 socket이고 socket에 O_NONBLOCK으로 설정된 경우 읽을 데이터를 수신하지 못하여 바로 return함. 
    
    EBADF : fd가 유효하지 않은 file descriptor임. 
    EFAULT : buf가 access할 수 없는 영역의 데이터 buffer임. 주로 변수를 pointer로 설정한 후에 malloc(3)하지 않은 경우 
    
    EINTR : signal이 발생하여 interrupt됨. 
    EINVAL : fd, buf, count 등의 변수가 잘못 설정된 경우. (예, count가 -값이 설정된 경우 등) 
    EIO : I/O 오류. background process에서 terminal에 대한 I/O를 시도했다든 지... 
    EISDIR : open된 fd가 directory인 경우
    ```
    
    ```c
    // 활용 예제 _ sample.파일 back up 
    #include <sys/types.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdio.h> 
    #include <errno.h> 
    
    /* 
    * 읽을 데이터를 요청한 사이즈 만큼 읽어들임. 
    * 파일의 끝이면 요청한 사이즈보다 작을 수 있음. 
    * Signal이 발생하더라도 읽기를 처리함. 
    */ 
    
    int read_data(int fd, char *buffer, int buf_size) 
    {
    	int size = 0;
    	int len;
    
    	while(1)
    	{
    		if((len = read(fd, &buffer[size], buf_size - size)) > 0)
    		{
    			size += len;
    			if(size == buf_size)
    				return size;
    		}
    		else if(len == 0)
    			return size;
    		else
    		{
    			if(errno == EINTR)
    				continue;
    			else
    				return -1;
    		} 
    	}
    } 
    /*
     * 저장할 데이터를 요청한 사이즈 만큼 write함
     * signal이 발생하더라도 저장함
     */ 
    int write_data(int fd, const char *buffer, int buf_size) 
    {
    	int size = 0;
    	int len;
    
    	while(1) 
    	{
    		if((len = write(fd, &buffer[size], buf_size - size)) > 0) 
    		{
    			size += len; 
    			if(size == buf_size)
    			{
    				return size; } 
    			}
    			else if(len == 0)
    			{
    				return size; }
    			else 
    			{
    				if(errno == EINTR) 
    					continue;
    				else
    				{ return -1; } 
    		} 
    	} 
    } 
    
    int main(int argc, char *argv[])
    {
    	int rfd; 
    	int wfd; 
    	int len; 
    	char buffer[4096]; 
    
    /* 파일을 읽기 전용으로 open함 */ 
    	if((rfd = open("sample.txt", O_RDONLY)) == -1)
    	{
    		fprintf(stderr, "FILE READ OPEN ERROR: %s\n", strerror(errno)); return 1; 
    	} 
    
    /* 쓰기 전용으로, 파일이 없으면 생성하고, 파일이 있으면 전체데이터를 삭제하고 open함 */ 
    	if((wfd = open("sample.txt.bak", O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
    	{
    		fprintf(stderr, "FILE WRITE OPEN ERROR: %s\n", strerror(errno));
    		return 1; 
    	} 
    
    	while(1) 
    	{
    		if((len = read_data(rfd, buffer, 4096)) == -1)
    		{
    			fprintf(stderr, "READ ERROR: %s\n", strerror(errno)); 
    			return 1; 
    		} 
    		if(len == 0) 
    		{
    			break;
    		} 
    		if((len = write_data(wfd, buffer, len)) == -1)
    		{
    			fprintf(stderr, "WRITE ERROR: %s\n", strerror(errno)); 
    			return 1; 
    		} 
    	} 
    	close(rfd); close(wfd); return 0; 
    }
    ```
    
- static(정적 변수와 메소드)I
    
    변수나 메소드 앞에서 static을 붙여 사용한다. 
    
    [https://iamnotokay.tistory.com/57](https://iamnotokay.tistory.com/57)
    
    [https://dojang.io/mod/page/view.php?id=690](https://dojang.io/mod/page/view.php?id=690)
    
    - 기본적으로 특정 함수 안에 들어있는 변수 → 지역변수 따라서 함수를 벗어나서 다시 호출하면, 그 값은 변수와 상관없이 새로운 변수를 생성시킨다.
        
        ⇒ static자료형 변수를 넣으면?  ⇒ 정적 변수로 만들어지면 함수를 벗어나도 해당 변수의 값이 사라지지 않아, 연산자나 내부 명령을 통해 변경된 값이 변하지 않는다. 
        
    - 이러한 특징에서, 정적 변수 설정이되면 정적 변수이면서도 지역변수로 함수 블록을 벗어나도 변하지 않고, 함수 블록 범위 안에서만 접근할 수 있다.
    - 단, 이렇게 선언한 뒤 다른 곳에서 extern 으로 사용하려고 하면? 컴파일 에러 발생함.
        
        ![Untitled](Get%20Next%20Line(%E1%84%8C%E1%85%B5%E1%86%AB%E1%84%92%E1%85%A2%E1%86%BC%E1%84%8C%E1%85%AE%E1%86%BC)%20cd758086df304ef9a8202f0c93ed1126/Untitled%201.png)
        
    - 전역 변수든 지역변수든 정적 변수로 설정하는 경우 모두 0으로 초기화 된다.
    - 더불어 정적 변수(전역, 지역)는 프로그램 시작시 생성,  초기화되고 프로그램 끝날 때 사라진다.
    - 정적 변수는 함수 매개변수로 사용할 수 없고,   static을 붙이더라도 매개변수는 정적변수가 되지 않느는다
    - 활용방안 ⇒ 프로그램으로 호출 했을 때, 반복문이 아닌 구조로도 호출을 통해 지속적으로 데이터 입력및 추가로 만들어 볼 수 있다.
    - wiki 백과 기록
        - 기억장소가 콜 스택에서 할당 및 할당 해제되는, 수명이 더 짧은 자동변수와는 반대되는 개념이다. ⇒ 기억장소가 힙 메모리에 동적 할당되는 객체와 반의어이다.
        - 이때 정적메모리 할당은 컴파일 시간에 메모리를 할당하는 것으로 런타임중 필요시 할당되는 동적 메모리나, 자동 메모리 할당과 다르다는 특징을 기억하자.
    
    ### 03. static variables
    
    - 정의
        - 기억장소가 콜 스택에서 할당 및 할당 해제되는, 수명이 더 짧은 자동변수와는 반대되는 개념이다. ⇒ 기억장소가 힙 메모리에 동적 할당되는 객체와 반의어이다.
        - 이때 정적메모리 할당은 `컴파일 시간`에 메모리를 할당하는 것으로 런타임중 필요시 할당되는 동적 메모리나, 자동 메모리 할당과 다르다는 특징을 기억하자.
    - 초기화 및 저장
        - `static` 을 붙임으로써 정적 변수로 할당이 된다.
        - `static` 변수 설정 시, 초기화를 시키지 않을 시 모두 0으로 초기화된다.
        - 더불어 프로그램이 계속 살아있는 동안은 해당 변수값을 기억하고 있으며, 프로그램이 종결되는 순간 그 값이 사라진다.
    - 저장 장소 및 범위
        - `Data`영역에 static변수는 저장되므로, 프로그램 종료시 시스템에게 그 공간을 반환한다.
        - 단, 이러한 static 변수는 extern으로 호출을 하더라도 호출되지 못하며, 해당 범위(전역이면 전역, 지역이면 지역)로 한정된 공간에서만 Data로써 사용된다.
- 텍스트 파일과 바이너리 파일에 대하여
    - 컴퓨터 문법에서는 '텍스트 파일'과 '바이너리 파일'은 구분해서 사용한다. 이는 잘못 읽어 들이는 것을 방지하기 위함이다.
        
        
        | 종류 |  |
        | --- | --- |
        | 텍스트 타일
        (Text File) | - 문자로 구성된 파일 
        - 대부분 ASCI 문자로 이뤄진 파일이나 사람이 사용하는 한글 영문등과 같은 문장들로 이뤄진 파일 
        - 소스코드파일 (.cpp), README.txt 등 |
        | 이진 파일 
        (Binary File) | - 데이터로 구성된 파일 
        - 모든 파일은 0, 1 로 이루어져 있다. 
        - 바이너리 파일이라고도 부른다. 
        - 이미지 파일(.png), 데이터 파일(.dat), 실행파일(.exe) 등  |
    - 텍스트 저장시 운영체제 마다 달라지는 개행문자 처리
        - C : HELLO \n
        - Windows : HELLO\r\n
        - Unix, Linux : HELLO\n
        - Mac : HELLO\r
    - 텍스트 파일 저장 되는 방식
        
        ![Untitled](Get%20Next%20Line(%E1%84%8C%E1%85%B5%E1%86%AB%E1%84%92%E1%85%A2%E1%86%BC%E1%84%8C%E1%85%AE%E1%86%BC)%20cd758086df304ef9a8202f0c93ed1126/Untitled%202.png)
        
    - 이진파일
        - 사람이 읽을 수 없으나, 컴퓨터는 읽을 수 있는 파일
        - 이진 데이터가 직접 저장되어 있는 파일
        - 이진 파일은 라인들로 분리되지 않는다.
        - 모든 데이터들은 문자열 변환이 없이 입출력되어진다.
        - 이진 파일은 특정 프로그램으로만 판독이 가능하다.
    - 이진파일 저장 방식 : 이진수 형태로 그대로 저장된다.
        
        ![Untitled](Get%20Next%20Line(%E1%84%8C%E1%85%B5%E1%86%AB%E1%84%92%E1%85%A2%E1%86%BC%E1%84%8C%E1%85%AE%E1%86%BC)%20cd758086df304ef9a8202f0c93ed1126/Untitled%203.png)
        
    
- redirection
    
    [https://ko.wikipedia.org/wiki/리다이렉션](https://ko.wikipedia.org/wiki/%EB%A6%AC%EB%8B%A4%EC%9D%B4%EB%A0%89%EC%85%98)
    

- contents

---

## Libft

---

### 01.  pointer / keyword

- const / char *
- `restrict` pointer
    - `restrict` pointer는 각 포인터가 서로 다른 메모리 공간을 가리키고 있고, 
    다른 곳에서 접근하지 않음을 컴파일러에게 알려주는 키워드 — 최적화 키워드 중 하나
        - 특정 메모리 영역에 접근할 수 있는 포인터가 단 하나임을 보장하는 키워드
    - 이 포인터 외에는 프로그래머가 해당 메모리 영역에 접근할 수단이 없음을 미리 알리며
    사용자에게 같은 변수의 주소를 넘기지 말라는 뜻으로도 볼 수 있다.
- function pointer
    - 함수 포인터는 함수의 주소를 가리키는 포인터
    - `반환값자료형 (*함수포인터이름)();`
        
        ```cpp
        #include <stdio.h>
        
        void hello(void)
        {
            printf("Hello, world!\n");
        }
        
        void bonjour(void)
        {
            printf("bonjour le monde!\n");
        }
        
        int main(void)
        {
            void (*fp)();
        
            fp = hello;
            fp();
            fp = bonjour;
            fp();
            return (0);
        }
        ```
        
- deprecated function (`bzero`)
    - In software development, "deprecated" refers to functions or elements that are in the process of being replaced by newer ones.
    - `bzero()` 는 `memset()`으로 대체되었으며 이제는 잘 사용되지 않는다!

---

### 02. size_t / unsigned int

- `size_t` : 해당 시스템에서 어떤 객체(값)가 포함 가능한 최대 크기의 데이터를 표현하는 타입
    - `typedef unsigned intsize_t;`
    - `size_t` 는 `unsigned int` 이며, 문자열이나 메모리의 사이즈를 나타낼 때 사용
    → 하지만 엄연히 다르다!
    - 메모리나 문자열 등의 길이를 구할 때에는 `unsigned int` 대신 `size_t` 로 반환
    - `size_t` 는 고정된 크기를 갖기 때문에 함수의 이식성을 위해 사용한다.
        - 32비트 운영체제에서는 부호 없는 32비트 정수
        - 64비트 운영체제에서는 부호 없는 64비트 정수
- `unsigned int` 또는 `int`는 64비트 OS라고 해서 꼭 64비트 정수는 아니다. 
— 여전히 32비트일 수도 있으며 OS에 따라 달라질 수 있음
- 예를들어 64비트환경에서 `sizeof(size_t)`를 하면 8바이트(64비트) 메모리가 나오는데 
같은 환경에서 `sizeof(unsigned int)`를 하면 7(또는 그 외 64비트가 아닌 다른값)이 나오는 경우가 있다고 함.
- links
    - [https://code4human.tistory.com/119](https://code4human.tistory.com/119)
    - [http://mwultong.blogspot.com/2007/06/c-sizet-unsigned-int.html](http://mwultong.blogspot.com/2007/06/c-sizet-unsigned-int.html)

---

### 03. memcpy / memmove

- `memcpy`
    - prototype : void *memcpy(void * restrict dest, const void *restrict src, size_t n);
    - 설명 : n바이트 만큼 메모리 에리어를 복사하여(src) 붙여넣는다(dest), 만약 dest와 src가 겹쳐지면, 함수가 제대로 작동하지 않아서, memmove 함수를 사용하면 된다.
    - 특징 : 메모리 주소 위치에 따른 overlap에 대한 처리가 없고, 이에 대한 결과물은 undefined behavior이다. 그러나, 해당 함수의 로직으로 인해 공통적인 오류 형태를 볼 수 있다.
- `memmove`
    - prototype : void *memmove(void *dst, const void *src, size_t len);
    - 설명 : len 바이트 만큼 src를 복사하여서, dst에 옮긴다. memcpy보다 안정성을 높이며, 주소값이 인접하여 생기는 오류를 개선한다.
    - 특징 : dst 와 src간의 메모리 overlap 현상에서 생길 수 있는 값의 복사 실패 및 데이터 파손을 막는다.

---

### 04. strlcpy와 strlcat

- `strlcpy` 및 `strlcat` 함수는 문자열을 각각 복사하고 연결한다. 오류가 발생하지 않으므로, 유사한 기능을 수행하는 `strncpy` 및 `strncat` 보다 안전하게 작동할 수 있도록 설계되었다.
    - `strncpy` 및 `strncat` 와 달리 `strlcpy` 및 `strlcat` 은 버퍼의 전체 크기를 취하고 결과가 `\0`로 종료되도록 보증한다 (따라서 `\0`의 바이트가 크기에 포함되어야한다).
    - `strlcpy` : `\0`로 종료하는 문자열 `src`에서 `dst`로 복사하고 `\0`로 문자열을 종료한다.
    - `strlcat` : `\0`로 종료하는 문자열 `src`를 `dst` 뒤에 추가한다.
        - `size - strlen(dst) - 1` 만큼 추가하고 `\0`로 문자열을 종료한다.
- return value
    - 생성하려고 시도한 문자열 전체의 길이를 반환한다.
        - `strlcpy` : `strlen(src)`
        - `strlcat` : `strlen(dst + src)`
    - 이는 복사하거나 붙여넣는 길이에서 절단되는 부분을 찾는 것을 목적으로 한다.
    - `strlcat`의 경우 `\0`가 발견되기 전 `size`를 넘는 경우 dst의 길이는 size(dstsize)로 간주되며 대상 문자열은 `\0`로 종료되지 않게된다 (`\0`에 대한 공간이 없으므로). 이렇게 하면 `strlcat`은 문자열의 끝에서 벗어나지 않게된다.
        - 이러한 상황은 `size`가 올바르지 않거나 `dst`가 적절한 c문자열이 아님을 의미함으로 발생하지 말아야 한다. → 잘못된 코드의 잠재적 보안문제를 방지하기 위한 검사이다.

---

### 05. atoi : LONG_MAX 및 LONG_MIN 처리

- `strtol`
    - atoi의 경우 내부에서 정수로 함수가 구현되어 돌아가는 것이 아니라 `strtol` 함수를 활용하여 해당 함수가 구현되어 있다. 단, 이는 무조건 이렇게 구현하라는 것은 아니며, 속도 등의 이유로 별개 구현도 가능은 하다.
    - 단 특징적으로 기능상 strtol은 atoi의 `superset`(확대 집합) 으로 이루어져 있다.
    - strtol 은 Long 값까지 받게 되는데, 이때 오버플로우 발생시 `LONG_MAX`값으로, 언더플로우 발생시 `LONG_MIN`값으로 변환하여 반환시킨다. ⇒ 그러나 실제 리눅스 상에 구현된 것을 보면 atoi 상에서 long long 범주까지는 정상 출력이 된다.
    - 단, long long Max 값, 또는 long long min 값 이상의 값을 입력되었을 때 각각 -1, 0 이 반환된다.
    - 이러한 결과가 나오는 이유는, atoi가 실제 구동될 때, `atoill` 과 호출시 함께 작동하여 자동으로 long long 까지는 담아낼 수 있도록 구현되어 있기 때문이다.
- `stdlib.h`의 `atoi`
    - man을 참고하면, 실제 `atoi`는 `atoill` 와 함께 동일한 atoi라는 명령으로 진행되므로 long, long long의 값을 표현한다.
    - 그러나 libft 라이브러리 서브젝트의 경우 `int` 로 한정시켜 하였기에 오로지 LONG_MAX, LONG_MIN 일 때 들어오지 말아야 할 값이 들어왔기에 출력되는 -1, 0이 출력되도록 구현을 요구했던 것이다.

---

---

## get_next_line

---

### 01. FD, file descriptor

- `FD` — File Descriptor, 파일 디스크립터
    - Unix 시스템에서 네트워크 소캣과 같은 파일이나 기타 입/출력 리소스 액세스 하는데 사용하는 추상 표현, 각 파일이나 소캣을 대표하는 정수 형태
        
        <aside>
        💡 질문 ) 소켓이란?[https://reakwon.tistory.com/81](https://reakwon.tistory.com/81)
        
        ---
        
        - 네트워크 통신을 하는 표준 방법으로 프로세스 간 연결의 종점.
        - 각 프로세스는 소켓을 가지고, 간단히 말해 ip주소, 포트번호를 갖고 있는 인터페이스이다.
        - 이를 사용할 때는 리눅스 시스템 상에서 파일로 다뤄지기에 파일 디스크립터를 통해 읽기 쓰기가 가능함.
        </aside>
        
    - 음이 아닌 정수 형태 (Non-negative integer), 일반적으로 int형식으로 C프로그래밍 언어로 표현된다. = windows 에서는 'File Handle'이라고 불림
    - 0 ~ 2번은 고정되어있음(unistd.h 명시)
        
        ![Untitled](Get%20Next%20Line(%E1%84%8C%E1%85%B5%E1%86%AB%E1%84%92%E1%85%A2%E1%86%BC%E1%84%8C%E1%85%AE%E1%86%BC)%20cd758086df304ef9a8202f0c93ed1126/Untitled.png)
        
    - FD가 숫자인 이유는 file descriptor 테이블의 인덱스이기 때문이다.
    - 파일 오픈 / 소캣 생성 시 부여되는 FD는 3부터 시작 → 현재 사용되는 숫자 중 사용하지 않은 가장 작은 값으로 할당 해준다.
    - open 되어 있는 fd 확인하기
        
        `/proc/"pid"/fd` ← 해당부분에서 ls 시 사용중인 fd확인이 가능하다. 
        
    - file descriptor 테이블의 각 항목은 FD 플래그, 파일 테이블로의 포인터를 갖고 있고, 이 포인터를 이용해 FD를 통해 시스템 파일을 참조할 수 있는 것이다. ⇒ 이러한 FD테이블, 파일 테이블 정보는 직접 수정 불가. `커널`을 통해서 수정된다.
    - FD의 최대값 = `OPEN_MAX`
        - 프로세스 하나당 최대 OPEN_MAX 개 만큼 파일을 열수 있고, 이는 플랫폼에 따라 다르다.
            
            질문 ) 플랫폼이라는 것이 뭘 의미할까? HW, SW, OS?
            
            질문 ) FOPEN_MAX란? 
            
            fopen으로 최대 열수 있는 파일 핸들러의 수. 
            
        - OPEN_MAX 확인 방법
            1. 터미널에서 getconf 명령어로 확인
                
                ```bash
                getconf OPEN_MAX
                
                /*result*/
                1024
                ```
                
            2. <unistd.h> 의 sysconf()함수로 확인 
                
                ```c
                #include <unistd.h>
                #include <stdio.h>
                
                int	main(void)
                {
                	int	max;
                	
                	max = sysconf(_SC_OPEN_MAX);
                	printf("OPEN_MAX : %d\n", max);
                	max = sysconf(FOPEN_MAX);
                	printf("FOPEN_MAX : %d\n", max);
                	return (0);
                }
                
                /*컴파일 후 결과값*/
                OPEN_MAX : 1024
                FOPEN_MAX : 200809
                ```
                
            
            [OPEN_MAX, 번호,](https://www.javaer101.com/article/2890626.html)
            
            OPEN_MAX추가 자료
            
    - Finally.. FD를 쉽게 생각하면, 파일 혹은 소켓을 생성 시 좀더 편한 대화를 위하여 OS가 만들어 건네주는 꼬리표 같은 것이다.
- example
    
    ![스크린샷 2021-12-02 오후 11.47.25.png](Get%20Next%20Line(%E1%84%8C%E1%85%B5%E1%86%AB%E1%84%92%E1%85%A2%E1%86%BC%E1%84%8C%E1%85%AE%E1%86%BC)%20cd758086df304ef9a8202f0c93ed1126/%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA_2021-12-02_%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE_11.47.25.png)
    

---

### 02. stdin

- standard streams, 표준 스트림
    
    ![Screen Shot 2021-12-03 at 11.53.55 AM.png](Get%20Next%20Line(%E1%84%8C%E1%85%B5%E1%86%AB%E1%84%92%E1%85%A2%E1%86%BC%E1%84%8C%E1%85%AE%E1%86%BC)%20cd758086df304ef9a8202f0c93ed1126/Screen_Shot_2021-12-03_at_11.53.55_AM.png)
    
    - 컴퓨터 프로그램과 그 환경(일반적으로 단말기) 사이에 미리 연결된 입출력 통로
    - 표준 스트림은 크게 세 가지로 구분된다 — `STDIN`(0), `STDOUT`(1), `STDERR`(2)
- `stdin` — standard input, 표준 입력
    - 표준 입력은 프로그램으로 들어가는 데이터(보통은 문자열) 스트림이다.
    - 프로그램은 `read()` 명령을 이용하여 데이터 전송을 요청한다.
    - 별도의 리다이렉션 없이 프로그램을 시작하면 표준 입력 스트림은 키보드에서 받아온다.

---

### 03. read() / redirection

- 저수준 파일입출력 함수 비교
    - 저수준 파일입출력 함수는 유닉스 기반의 고전입출력함수로 리눅스 기준 `unistd.h` 헤더 파일에 선언되어 있다.
    - 이때, 표준입출력 함수들 `fopen(), fclose() 등등...` 은 버퍼를 사용하지만, 저수준의 경우 버퍼를 사용하지 않는 `비버퍼링`  함수다.
    - 버퍼(buffer)란 어떤 장치에서 다른 장치로 데이터를 송신할 때 일어나는 시간차, 데이터 흐름 속도 차를 조정하기 위한 일시적 데이터 기억 장치이다. 따라서 `저수준 입출력 함수` 는 이처럼 버퍼를 이용하지 않고 파일 바이트를 그대로 이용하기 때문에 속도가 빠르다는 장점이 있다.
    - 단, 고전함수다 보니 윈도우에서 달라지는 부분 있음. 윈도우에선 `<io.h>` 선언해야한다.
    
    |  |  저수준 파일 입출력 | 고수준 파일 입출력 |
    | --- | --- | --- |
    | 파일 지시자 | int df; | FILE *fp; |
    | 열린 파일 참조 | 파일 기술자를 사용 |  파일 포인터를 사용 |
    | 특징 | 1. 훨씬 빠름
    2. 바이트 단위로 읽고 쓴다
    3. 특수 파일에 대한 접근이 가능하다.
    4. 바이트단위로 입출력함으로 추가적인 기능을 구현해야하는 단점이 있다. 
    (바이트를 적당한 형태의 데이터로 변화하는 함수 등) | 1. 사용하기 쉽다.
    2. 버퍼 단위로 읽고 쓴다.
    3. 데이터의 입출력 동기화가 쉽다.
    4. 여러가지 형식을 지원한다.  |
    | 주요함수 | open, close, read, write, dup, dup2, fcntl, lseek, fsync | fopen, fclose, fread, fwrite, fputs, fgets, fpritf, fscanf, freopen, fseek |
- `read()`
    - prototype : `ssize_read(int fides, void *buf, size_t nbytes);`
        - 윈도우에선 int형
    - n바이트 만큼 읽어서 buf에 저장한다.
        - 오류가 발생하면 -1을 반환
        - 성공 시 읽어온 바이트 수를 반환
    - example code
        
        ```c
        #include <sys/stat.h>          // mode_t
        #include <fcntl.h>
        #include <unistd.h>            // 윈도우에선 <io.h>헤더
        #include <stdio.h>
        #include <stdlib.h>           // exit함수
        
        #define BUFFER (10)
        
        int main(void)
        {
        	int fd, n1, n2;
        	mode_t mode;      // 윈도우에선 unsigned short 형식자로 바꿔서 사용
        	char buf1[BUFFER];
        	char buf2[BUFFER];
        
        	mode = 0644;             // mode(권한옵션)을 8진수로 저장
        
        	if(!(fd = open("test.txt",O_RDONLY, mode)))
        	{
        		perror("Open");
        		exit(1);
        	}
        	n1 = read(fd, buf, BUFFER - 1);     // 마지막에 '\0'을 넣어주기 위해 "BUFFER - 1"크기로 설정
        	n2 = read(fd, buf2, BUFFER - 1);   // read함수의 오프셋이 이어짐을 확인하기위해 read()함수를 2번실행
        	if (n == -1 || n2 == -1)
        	{
        		close(fd);
        		perror("Read");
        		exit(1);
        	}
        	buf[n1] = '\0';        //read()함수가 읽어들인 값을 반환함을 이용하여 '\0'값을 넣어준다
        	buf2[n2] = '\0';
            
        	printf("n = %d, buf = %s\nn2 = %d, buf = %s\n", n1, buf1, n2, buf2);
        	close(fd);
        	
        	return (0);
        }
        /*---test.txt파일 내용---*/
        abcdefghijklmn
        /*---결과---*/
        n1 = 9, buf1 = abcdefghi
        n2 = 5, buf2 = jklmn
        ```
        
- redirection
    - **리다이렉션(redirection)**은 컴퓨팅에서 표준 스트림을 사용자 지정 위치로 우회할 수 있는 다양한 유닉스 shell을 포함한 대부분의 명령어 인터프리터에 일반적인 명령이다.
        - 명령어 인터프리터(command-line interpreter) : 운영체제나 프로그래밍 언어의 환경에서 해석하는 입력된 명령어를 읽고 실행하는 컴퓨터 프로그램
    - redirection은 특정한 문자열들을 명령어 사이에 두어서 추가되는 것이 보통이다.
        - `command1 > file1`
            - `cmd1`을 실행하며 나오는 출력을 `file1`로 내보낸다.
            - 기존에 `file1`이 존재하는 경우 기존의 파일 내용은 지우고 새롭게 추가된다.
        - `command1 >> file1`
            - 파일의 끝에 출력을 추가할 때는 위의 연산자를 사용한다.
        - `command1 < file1`
            - `cmd1`을 실행하되, `file1`이 입력의 대상이 된다.
        - `command1 < file1 > file2`
            - `cmd1`은 `file1`에서 내용을 불러들인 뒤 `file2`에 기록된다.

---

### 04. static variables

- 정의
    - 기억장소가 콜 스택에서 할당 및 할당 해제되는, 수명이 더 짧은 자동변수와는 반대되는 개념이다. ⇒ 기억장소가 힙 메모리에 동적 할당되는 객체와 반의어이다.
    - 이때 정적메모리 할당은 `컴파일 시간`에 메모리를 할당하는 것으로 런타임중 필요시 할당되는 동적 메모리나, 자동 메모리 할당과 다르다는 특징을 기억하자.
- 초기화 및 저장
    - `static` 을 붙임으로써 정적 변수로 할당이 된다.
    - `static` 변수 설정 시, 초기화를 시키지 않을 시 모두 0으로 초기화된다.
    - 더불어 프로그램이 계속 살아있는 동안은 해당 변수값을 기억하고 있으며, 프로그램이 종결되는 순간 그 값이 사라진다.
- 저장 장소 및 범위
    - `Data`영역에 static변수는 저장되므로, 프로그램 종료시 시스템에게 그 공간을 반환한다.
    - 단, 이러한 static 변수는 extern으로 호출을 하더라도 호출되지 못하며, 해당 범위(전역이면 전역, 지역이면 지역)로 한정된 공간에서만 Data로써 사용된다.

---
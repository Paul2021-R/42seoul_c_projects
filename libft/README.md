#Libft

## Goal
함수를 이해하고, 사용법을 배우며, 재구성하는 것. 
해당 과제를 통해 만들어낸 자체 제작 라이브러리는 다른 C 프로젝트들에 도움이 될 것이므로, 지속적으로 추가할 것. 

## Common Instructions 
* 놈을 지킬 것. 보너스도 놈을 안지키면 안 된다.
* 지정되지 않은 것에 대한 것과는 별개의 종료 발생 시 프로젝트는 0점이 된다. 
* 메모리의 적절한 할당 및 적절한 free가 되어야 하며, 누수는 있어서는 안된다. 
* 필요시 Makefile 을 제출하며, flags를 포함할것. 
* 그 외의 내용은 생략한다. 

## Mandatory Part
### Technical Considerations 
* `전역변수`는 선언하지 말것
* 복잡한 함수 작성시 하위 함수가 필요하다면, 이러한 하위 함수를 라이브러리와 함께 배포하지 않도록 `static(정적)`으로 정의할 것.
* 모든 파일은 `root`위치에 제출할 것
* 사용하지 않은 파일 제출은 금지 
* 라이브러리 작성시 `ar` 사용, `libtool` 사용은 금지

#### Libc Functions
해당 내용에서 필요한 함수는 아래와 같다. 

##### 외부함수가 필요없는 함수목록
>   `isalpha` , `isdigit`, `isalnum`, `isascii`,
>   `isprint`, `strlen`, `memset`, `bzero`,  
>   `memcpy`, `memmove`, `strlcpy`, `strlcat`,
>   `toupper`, `tolower`, `strchr`, `memchr` ,  
>   `strncmp`, `strrchr`, `memcmp`, `strnstr`, `atoi`  


##### 외부함수 필요한 함수목록
>    `calloc`, `strdup`

#### Addtional Functions
추가적으로 유용한 함수들 목록이다. 길므로 이름만 나열한다. 

>    `substr` , `strjoin` ,`strtrim`, `split`, `itoa`,
>    `strmapi`, `striteri`, `putchar_fd`, `putstr_fd`, `putendl_fd`, `putnbr_fd`

## Bonuse Part
list 활용을 위한 기초적인 조작 함수를 구현한다. 
>    `lstnew` , `lstadd_front` , `lstsize`, `lstlast` , `lstadd_back` ,
>    `lstdelone`, `lstclear` , `lstiter` , `lstmap`	

## 기타 내용
학습을 위한 추가적인 사항들을 기록해두었다. 
1. 알아야 도움이 되는 것 
	- 파일 디스크립션 
	- `restrict`의 의미 
	- `Makefile` 듀토리얼 및 구현 방법 
	-  배열 할당의 `malloc`과 `free`의 사용 방법
2. 현재 학습 완료 된 것
	- 
	-
3. 특이사항
	- `libft_back.h` 가 진짜 헤더 파일이며, 현재 헤더 파일은 restrict를 인식하지 못하는 테스트 프로그램 호환을 위한 임시 파일이다. 

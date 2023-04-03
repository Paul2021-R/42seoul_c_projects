# containers_test


## Warning
본 테스터는 mli42 님의 테스터 코어를 활용하여 자작한 테스터기입니다. 
기능은 다음과 같습니다. 
- 개별 컨테이너에 대한 테스팅 
- 전체 컨테이너에 대한 테스팅 

## Usage

Expected tree:

```
. [ft_container]
├── <container>.hpp
├── [...]
└── containers_test
    └── [...]
```

컨테이너들이 있는 루트 폴더에 삽입 할 것.
해당 폴더에 들어가서 컴파일 된 프로그램들을 convention에 맞추어 실행할 것

```bash
./do.sh [container_to_test] [...]
./cmp_one <path/to/test_file>
./one <path/to/test_file> [namespace=ft]
```

Examples:
```bash
./do.sh # tests every containers
./do.sh vector list # tests only vector && list

./cmp_one srcs/list/size.cpp # 특정 테스트 파일을 STD와 확인하는 테스팅 방식

./one srcs/list/rite.cpp # 직접 제작한 ft 컨테이너를 테스트한다.
./one srcs/list/rite.cpp std # std 라이브러리를 컴파일해서 테스팅을 진행해본다.
```

결과물 확인 방법
```
The [ ✅ / ❌ ] emojis shows if they behave the same, i.e if the STL and your implementation:
- compile the same way,
- return the same number,
- print the same output.

If a diff occurs, a deepthought is created and logs are kept.

The [Y/N] shows if the STL compile (Y) or not (N), there are some test where you should not compile.
```

## Tested features
- [x] vector
- [x] list
- [x] map
- [x] stack
- [x] queue
- [x] deque
- [x] multimap
- [x] set
- [x] multiset

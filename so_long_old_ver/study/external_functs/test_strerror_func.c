/*

존재하지 않는 파일 unexist.ent 를 열라고 해 오류가 발생한다.
이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/strerror/
에서 가져왔습니다.

 */
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main() {
  FILE* pFile;
  pFile = fopen("unexist.ent", "r");
  if (pFile == NULL)
    printf("unexist.ent 파일에 관하여 에러가 발생하였습니다.:\n[%s]\n", strerror(errno));
  return 0;
}

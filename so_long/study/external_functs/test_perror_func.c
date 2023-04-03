/*존재하지 않는 파일(unexist.ent) 을 열어 오류를 발생시켜 perror 함수를
 * 호출시킨다.이 예제는
 * http://www.cplusplus.com/reference/clibrary/cstdio/perror/에서
 * 가져왔습니다.
 * */
#include <stdio.h>

int main()
{
	FILE* pFile;
	
	pFile = fopen("unexist.ent", "rb");
	if (pFile == NULL)
	   	perror("에러가 발생했습니다");
	else
    	fclose(pFile);
	return 0;
}

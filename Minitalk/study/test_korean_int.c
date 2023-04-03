#include <stdio.h>
#include <string.h>

int main(void)
{
	char	*str;

	str = "안녕하세요.\n";
	int i = 0;
	while (i < strlen(str))
	{
		printf("%c : %i\n", str[i], (int)str[i]);
		i++;
	}
	printf("%s\n", str);
}
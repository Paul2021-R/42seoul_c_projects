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
	int rfd; //읽을 fd 
	int wfd; //쓸 fd
	int len; 
	char buffer[4096]; 

/* 파일을 읽기 전용으로 open함 */ 
	if((rfd = open("sample.txt", O_RDONLY)) == -1)
	{
		fprintf(stderr, "FILE READ OPEN ERROR: %s\n", strerror(errno)); 
		return 1; 
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
	close(rfd); 
	close(wfd); 
	return 0; 
}

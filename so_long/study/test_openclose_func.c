#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
	char *fname = "ssu_test.txt";
	int fd;

	if ((fd = open(fname, O_RDONLY)) < 0) {
		fprintf(stderr, "open error for %s\n", fname);//stdio.h
		exit(1);
	}

	printf("Success!\nFilename : %s\nDescriptor : %d\n", fname, fd);
	close(fd);
	exit(0);
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

sem_t *sem;

void *routine(void *num)
{
	sem_wait(sem); // 세마포어 lock
	for (int i = 0; i < 3; ++i)
	{
		printf("%d uses semaphore\n", *(int *)num);
		usleep(1000 * 1000);
	}
	sem_post(sem); // 세마포어 unlock
	return (num);
}

int main(void)
{
	int ret;
	pthread_t tid[4];
	int num[4];

	sem = sem_open("test_sem", O_CREAT | O_EXCL, 0644, 4); // value(counter)가 3인 세마포어 생성
	if (sem == SEM_FAILED) // 세마포어 생성 실패시
	{
		fprintf(stderr, "sem errro\n");
		return (-1);
	}

	for (int i = 0; i < 4; ++i) // 쓰레드 3개 생성 및 쓰레드 루틴 실행
	{
		num[i] = i;
		pthread_create(&tid[i], NULL, routine, (void *)&num[i]);
	}
	for (int i = 0; i < 4; ++i)
		pthread_join(tid[i], NULL);
	ret = sem_close(sem); // 세마포어 종료 및 할당한 자원 해제
	printf("sem_close: %d\n", ret);
	ret = sem_unlink("test_sem"); // 세마포어 객체 해제
	printf("sem_unlink: %d\n", ret);
	return 0;
}

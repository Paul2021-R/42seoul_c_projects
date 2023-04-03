/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_yes_mutex_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 01:10:21 by haryu             #+#    #+#             */
/*   Updated: 2022/05/20 17:03:26 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t mutex;
int cnt=0;

void *count(void *arg){
    int i;
    char* name = (char*)arg;

    pthread_mutex_lock(&mutex);
    //======== critical section =============
    cnt=0;
    for (i = 0; i < 5; i++)
    {
        printf("%s cnt: %d\n", name,cnt);
        cnt++;
        sleep(1);
    }
    //========= critical section ============
    pthread_mutex_unlock(&mutex);
	return (NULL);
}

int main(void)
{
    pthread_t thread1,thread2;

	pthread_mutex_init(&mutex, NULL);
    pthread_create(&thread1, NULL, count, (void *)"thread1");
    pthread_create(&thread2, NULL, count, (void *)"thread2");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
	pthread_mutex_destroy(&mutex);
}
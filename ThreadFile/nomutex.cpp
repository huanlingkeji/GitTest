/*************************************************************************
没有添加信号量的程序
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
int sharedi = 0;
void* increse_num(void *ptr);
/* 毫秒级 延时 */
void Sleep(int ms)
{
	struct timeval delay;
	delay.tv_sec = 0;
	delay.tv_usec = ms * 1000; // 20 ms
	select(0, NULL, NULL, NULL, &delay);
}

int main() {
	int ret;
	pthread_t thrd1, thrd2, thrd3;

	ret = pthread_create(&thrd2, NULL, increse_num, (void*)"线程2");
	ret = pthread_create(&thrd1, NULL, increse_num, (void*)"线程1");
	ret = pthread_create(&thrd3, NULL, increse_num, (void*)"线程3");
	
	pthread_join(thrd3, NULL);
	pthread_join(thrd1, NULL);
	pthread_join(thrd2, NULL);

	printf("sharedi = %d\n", sharedi);

	return 0;

}

void* increse_num(void *ptr) {
	long i, temp;
	for (i = 0; i < 5; i++) {
		temp=sharedi;
                temp=temp+1;
                sharedi=temp;
	}
}


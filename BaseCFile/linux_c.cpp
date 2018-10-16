#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <pthread.h>

void* thread_func(void* arg)
{
	printf("线程函数22222: %s\n", static_cast<char*>(arg));
	return nullptr;
}

int main()
{
	pthread_t tid;
	int errnum = pthread_create(&tid, nullptr, thread_func,
		const_cast<char*>("Hello Linux!"));
	if (errnum != 0) {
		fprintf(stderr, "pthread_create error: %s\n", strerror(errnum));
		exit(1);
	}

	errnum = pthread_join(tid, nullptr);
	if (errnum != 0) {
		fprintf(stderr, "pthread_join error: %s\n", strerror(errnum));
		exit(1);
	}

	return 0;
}

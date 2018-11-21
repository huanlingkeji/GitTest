#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// 声明一个都用的量
static int _old;

// 线程跑的函数
static void _run(int n) {
    int piyo = 10;    
    int i;
    
    ++n;    
    for(i=0; i<n; ++i) {
        printf("n=%d, i=%d\n", n, i);
        ++_old;
        printf("n=%d, piyo = %d, _old=%d\n", n, piyo, _old);
    }
}

#define _INT_PTX (3)

int main(void) {
    int i;
    pid_t rt;

    puts("main beign");    

    for(i=0; i<_INT_PTX; ++i) {
        // &i 是有问题的, 但是这里为了测试, 可以乱搞
        rt = fork();
        if(rt < 0) {
            printf("fork clone error! rt = %d, i=%d\n", rt, i);
            break;
        }
        if(rt == 0) {
            _run(i);
            exit(EXIT_FAILURE);
        }
    }

    //等待子进程结束
　　for(;;) {
　　　　rt = waitpid(-1, NULL, WNOHANG);
　　　　if(rt>=0 || errno==EINTR)
　　　　　　continue;
　　　　break;
　　}   
    
    puts("end");    

    // 这里继续等待 
    for(i=0; i<190; ++i){
        printf("等待 有缘人[%d]!\n", i);
        sleep(1);
    }    

    return 0;
}

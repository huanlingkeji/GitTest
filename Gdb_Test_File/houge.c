#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * arr 只能是数组
 * 返回当前数组长度
 */
#define LEN(arr) (sizeof(arr)/sizeof(*arr))

// 简单数组打印函数
static void _parrs(int a[], int len) {
    int i = -1;
    puts("当前数组内容值如下:");

    while(++i < len) 
        printf("%d ", a[i]);    
    putchar('\n');
}

// 简单包装宏, arr必须是数组
#define PARRS(arr) \
    _parrs(arr, LEN(arr))

#define _INT_OLD (23)

/*
 * 主函数,简单测试
 * 测试 core文件, 
 * 测试 宏调试
 * 测试 堆栈内存信息
 */
int main(void) {
    int i;
    int a[_INT_OLD];
    int* ptr = NULL;    

    // 来个随机数填充值吧
    srand((unsigned)time(NULL));
    for(i=0; i<LEN(a); ++i)
        a[i] = rand()%222;
    
    PARRS(a);

    //全员加double, 包含一个错误方便测试
    for(i=1; i<=LEN(a); ++i)
        a[i] <<= 1;
    PARRS(a);

    // 为了错,强制错
    //*ptr = 0;

    return 0;
}

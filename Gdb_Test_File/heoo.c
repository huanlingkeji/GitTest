#include <stdio.h>

int g_var = 0;

static int _add(int a, int b) {
    printf("_add callad, a:%d, b:%d\n", a, b);
    return a+b;
}

int main(void) {
    int n = 1;
    
    printf("one n=%d, g_var=%d\n", n, g_var);
    ++n;
    --n;
    
    g_var += 20;
    g_var -= 10;
    n = _add(1, g_var);
    printf("two n=%d, g_var=%d\n", n, g_var);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>

/**
 *  查看编译当前代码的是c还是c++，查看当前的版本 
 */

int main() {
/* 如果 __STDC__ 定义，则表示当前是 c/c++ */
#ifdef __STDC__
/* 如果定义 __cplusplus 表示是c++程序，否则就是 c语言程序 */
#ifdef __cplusplus
    printf("this is c++.\n");
    printf("c++ version is: %ld\n", __cplusplus);
#else
    printf("this is c.\n");
    printf("Version: %ld\n", __STDC_VERSION__);
#endif
#else
/* 否则就不是 */
printf("this not is c or c++ pragram.\n");
#endif

    int a = 0;
    int *s = NULL;
    s = &a;
    printf("%d\n", _msize((void *)s));
    return 0;
}
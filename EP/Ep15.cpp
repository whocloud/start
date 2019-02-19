/*************************************************************************
	> File Name: Ep15.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月22日 星期六 18时09分54秒
 ************************************************************************/
#include<stdio.h>
#include<inttypes.h>
#define max_n 20
typedef int64_t int1;
int1 C(int1 n, int1 x) {
    int1 m = 1;
    for (int1 i = n; i > x; i--) {
        m *= i;
    }
    return m;
}

int1 CC(int1 n) {
    return C(2 * n, n) / (C(n, 0) * C(n, 0));
}

int main() {
    int1 n = max_n;
    printf("%"PRId64"\n", CC(n));
    return 0;
}

/*************************************************************************
	> File Name: EP208-test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月12日 星期六 16时29分58秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include "008.h"

int main() {
    int64_t zero = 0, ans = 0, p = 1;
    for (int i = 0; a[i]; i++) {
        if (a[i] == '0') {
            zero++;
        }
        else {
            p *= a[i] - '0';
        }
        if (i >= 13) {
            if (a[i - 13] == '0') {
                zero--;
            } else {
                p /= a[i - 13] - '0';
            }
        }
        if (zero == 0 && p > ans) ans = p;
    }
    printf("%"PRId64"\n", ans);
    int a = 6, b = 2;
    printf("%d\n", a /= b - 1);
    return 0;
}

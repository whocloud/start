/*************************************************************************
	> File Name: EP03.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 16时42分53秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

int main() {
    int64_t num = 600851475143, x = 2, ans;
    while(x * x <= num) {
        if (num % x) {
            x++;
            continue;
        }
        ans = x;
        while (num % x == 0) num /= x;//这行执行while循环，除尽因子xg
        x += 1;
    }
    if (num - 1) ans = num;
    printf("%" PRId64 "\n", ans);
    return 0;
}

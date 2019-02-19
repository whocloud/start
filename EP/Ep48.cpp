/*************************************************************************
	> File Name: Ep48.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月15日 星期二 19时12分51秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define max 10000000000

int64_t num[1005] = {0};

int count(int64_t n) {
    int64_t temp = 0;
    while (n) {
        temp++;
        n /= 10;
    }
    return temp;
}

int main() {
    for (int i = 1; i <= 1000; i++) {
        int64_t temp = i;
        for (int j = 1; j < i; j++) {
            while(count(temp) > 10) {
                temp = temp % max;
            }
            temp *= i;
        }
        num[i] = temp;
    }
    int64_t ans = 0;
    for (int i = 1; i <= 1000; i++) {
        ans += num[i];
    }
    int64_t sum = 0;
    sum = ans % max;
    printf("%"PRId64"\n", sum);
    return 0;
}

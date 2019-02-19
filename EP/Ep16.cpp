/*************************************************************************
	> File Name: Ep16.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月22日 星期六 18时31分40秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#define base 10000

int get_digit(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int sum = 0;
    int ans[400] = {0};
    ans[0] = ans[1] = 1;
    for (int i = 0; i <100; i++) {
        for (int j = 1; j <= ans[0]; j++) ans[j] <<= 10;
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < base) continue;
            ans[j + 1] += ans[j] / base;
            ans[j] %= base;
            ans[0] += (j == ans[0]);
        }
    }
    for (int i = 1; i <= ans[0]; i++) sum += get_digit(ans[i]);
    printf("%d\n", sum);
    return 0;
}

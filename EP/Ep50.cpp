/*************************************************************************
	> File Name: Ep50.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月15日 星期二 16时53分00秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define max 1000000

int prime[max + 5] = {0};
int num[max + 5] = {0};
int sum[max + 5] ={0};
int temp = 0;

void init() {
    for (int i = 2; i < max; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            num[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 1; i <= prime[0]; i++) {
        if (sum[i - 1] + prime[i] > max) break;
        sum[i] = sum[i - 1] + prime[i];
        if (i > temp) temp = i;
    }
}

int main() {
    init();
    printf("%d\n", sum[temp]);
    int n = 0;
    for (int i = temp; i >= 1; i--) {
        for (int j = 0; j < temp; j++) {
            if (num[sum[i] - sum[j]] == 1 && (i - j) > n) {
                n = i - j;
                num[0] = sum[i] - sum[j];
            }
        }
    }
    printf("%d\n", num[0]);
    return 0;
}

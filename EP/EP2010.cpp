/*************************************************************************
	> File Name: EP2010.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 11时19分52秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define MAX 2000000
int prime[MAX + 5] = {0};

void init() {
    for (int i = 2; i * i <= MAX; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= MAX; j += i) {
            prime[j] = 1;
        }
    }
    for (int i = 2; i < MAX; i++) {
        if (prime[i]) continue;
        prime[++prime[0]] = i;
    }
    return ;
}

int main () {
    init ();
    int64_t sum = 0;
    for (int i = 1; i <= prime[0]; i++) {
        sum += prime[i];
    }
    printf("%s\n",PRId64);
    printf("%" PRId64,sum);
    return 0;
}


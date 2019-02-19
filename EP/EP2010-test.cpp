/*************************************************************************
	> File Name: EP2010-test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月12日 星期六 16时57分14秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define max 2000000
int prime[max + 5] = {0};

void init() {
    for (int i = 2; i <= max; i++) {
        if(!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int main() {
    init();
    int64_t temp = 0;
    for (int i = 1; i <= prime[0]; i++) {
        temp += prime[i];
    }
    printf("%"PRId64"\n", temp);
    return 0;
}

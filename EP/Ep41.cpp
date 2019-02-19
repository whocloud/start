/*************************************************************************
	> File Name: Ep41.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月17日 星期四 20时32分13秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define max 987654322

int64_t prime[max + 5] = {0};

int is_prime1(int64_t x) {
    for (int i = 2; i < max; i++) {
        if(!prime[i]) prime[++prime[0]];
        for (int j = 1;j <= prime[0]; j++) {
            if (prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

int is_prime(int64_t x) {
    int num[10] = {0};
    while (x > 0) {
        num[x % 10] = 1;
        x /= 10;
    }
    for (int i = 1; i < 10; i++) {
        if(num[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int64_t ans = 0;
    for (int64_t i = prime[0]; i >= 200000000; i--) {
        if(!is_prime(prime[i])) continue;
        if (prime[i] > ans) ans = prime[i];
        break;
    }
    printf("%"PRId64"\n", ans);
    return 0;
}

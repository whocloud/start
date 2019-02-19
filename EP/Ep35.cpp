/*************************************************************************
	> File Name: Ep35.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月24日 星期四 09时05分41秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#include<inttypes.h>
#define MAX 1000000

int digit[7] = {0};
int prime[MAX + 5] = {0};
int isprime[MAX + 5] = {0};
int memory[MAX + 5] = {0};
int64_t han[7] = {1, 1, 10, 100, 1000, 10000, 100000};

void is_prime() {
    for(int i = 2; i < MAX; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            isprime[i] = 1;
        }
        for(int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > MAX) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}

void circular(int x) {
    int num = floor(log10(x)) + 1;
    for(int i = 0; i < 7; i++) {
        digit[i] = 0;
    }
    int m = 1;
    while(m < num) {
        digit[m] = x;
        int temp = x % 10;
        x /= 10;
        x += temp * han[num];
        digit[0]++;
        m++;
    }
    return ;
}

int circularprime(int x) {
    for(int i = 1; i <= digit[0]; i++) {
        if(isprime[i]) continue;
        else return 0;   
    }
    for(int i = 1; i <= digit[0]; i++) {
        memory[digit[i]] = 1;
    }
    return 1;
}

int main() {
    int sum = 0;
    is_prime();
    for(int i = 1; i <= prime[0]; i++) {
        circular(i);
        if(memory[i]) sum++;
        else if(circularprime(i)) sum++;
    }
    printf("%d\n", sum);
    return 0;
}

/*************************************************************************
	> File Name: EP207-test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月11日 星期五 20时45分57秒
 ************************************************************************/

#include<stdio.h>
#define max 200000
int prime[max + 5] = {0};

void init() {
    for (int i = 2; i <= max; i++) {
        if(!prime[i]){
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int main() {
    init ();
    printf("%d\n", prime[10001]);
    return 0;
}

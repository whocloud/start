/*************************************************************************
	> File Name: Ep47.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月28日 星期五 19时26分55秒
 ************************************************************************/

#include<stdio.h>
#define max_n 1000000
int prime[max_n + 5] = {0};
int dnum[max_n + 5] = {0};
void init() {
    for (int i = 2; i <= max_n; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            dnum[prime[j] * i] = dnum[i] + (i % prime[j] != 0);
            if (i % prime[j] == 0) break; 
        }
    }
}
int main() {
    init ();
    for (int i = 210; i <= max_n - 3; i++) {
        if (dnum[i] ^ 4) continue;
        if (dnum[i + 1] ^ 4) continue;
        if (dnum[i + 2] ^ 4) continue;
        if (dnum[i + 3] ^ 4) continue;
        printf("%d\n", i);
        break;
    }    
    return 0;
}

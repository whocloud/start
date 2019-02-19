/*************************************************************************
	> File Name: Ep21.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月02日 星期三 18时30分52秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max 10000

int prime[max + 5] = {0};
int snum[max + 5] = {0};
int mnum[max + 5] = {0};

void init() {
    for (int i = 2; i <= max; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            mnum[i] = 1;
            snum[i] = 1 + i;
        }    
        for (int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) {
                mnum[prime[j] * i] = mnum[i] + 1;  
                snum[prime[j] * i] = snum[i] / (pow(prime[j], mnum[i] + 1) - 1) * (pow(prime[j], mnum[i] + 2) - 1);
                break;
            } else {
                mnum[prime[j] * i] = 1;
                snum[prime[j] * i] = snum[prime[j]] * snum[i];
            }
        }
    }
    return ;
}

int main() {
    init();
    int sum = 0;
    printf("%d\n",snum[6]);
    for (int i = 2; i <= max; i++) {
        snum[i] -= i; 
    }
    for (int i = 2; i <= max; i++) {
        if (snum[i] <= max && snum[i] != i && i == snum[snum[i]]) {
            printf("%d %d\n", i, snum[i]);
            sum += i;
        }
    }
    printf("%d\n",sum);
    return 0;
}

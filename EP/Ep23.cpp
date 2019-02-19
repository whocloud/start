/*************************************************************************
	> File Name: Ep21.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月02日 星期三 18时30分52秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max 28123

int prime[max + 5] = {0};
int snum[max + 5] = {0};
int mnum[max + 5] = {0};
int xnum[max + 5] = {0};

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

void y() {
    for (int i = 1; i <= max; i++) {
        snum[i] -= i;
        if(i < snum[i])  mnum[++mnum[0]] = i;
    }
    return ;
}

int main() {
    init();
    y();
    int sum = 0;
    for (int i = 1; i < mnum[0]; i++) {
        for (int j = 1; j < mnum[0]; j++) {
            if (mnum[i] + mnum[j] > max) break; 
            xnum[mnum[i] + mnum[j]] = 1;
        }
    }
    for (int i = 1;i < max; i++) {
        if (xnum[i] == 0) {
            sum += i;
        } else {
            continue;
        }
    }
    printf("%d\n",sum);
    return 0;
}

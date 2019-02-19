/*************************************************************************
	> File Name: Ep12.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月22日 星期六 14时16分46秒
 ************************************************************************/

#include<stdio.h>
#define max_n 100000

int prime[max_n + 5] = {0};
int dnum[max_n + 5] = {0};//记录约数个数
int mnum[max_n + 5] = {0};

void init() {
    for (int i = 2;i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 2;
            mnum[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                mnum[prime[j] * i] = mnum[i] + 1;
                dnum[prime[j] * i] = dnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
                break;
            } else {
                mnum[prime[j] * i] = 1;
                dnum[prime[j] * i] = dnum[prime[j]] * dnum[i];
            }
        }
    }
}

int num(int n) {
    return n * (n + 1) / 2;
}

int fac_num(int n) {
    if (n & 1) {
        return dnum[n] * dnum[(n + 1) >> 1];
    } else {
       return dnum[n >> 1] * dnum[n + 1]; 
    }
}

int main() {
    init ();
    int n = 1;
    while (fac_num(n) < 500) n++;
    printf("%d\n", num(n));
    return 0;
}

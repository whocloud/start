/*************************************************************************
	> File Name: EP207-3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 14时54分01秒
 ************************************************************************/
#include<stdio.h>
#define MAX 200000
int prime[MAX + 5] = {0};
void init () {//先从最小素数开始找
    for (int i = 2; i <=MAX; i++) {
        //未标记的数和素数进入素数表
        if(!prime[i]) prime[++prime[0]] = i;
        //用素数表中的数乘以i的值标记合数
        for (int j = 1; j <= prime[0]; j++) {
            //不会超过i^2
            if (prime[j] * i > MAX) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}    
int main () {
    init ();
    printf("%d\n", prime[10001]);
    return 0;
}

/*************************************************************************
	> File Name: EP207-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 10时40分32秒
 ************************************************************************/

#include<stdio.h>
#define MAX 200000
int prime[MAX + 5] = {0};
void init() {
    for (int i = 2; i * i <= MAX; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= MAX; j += i) {
            prime[j] = 1;
        }
    }
    for (int i = 2; i <= MAX; i++) {
        if (prime[i]) continue;
        prime[++prime[0]] = i;
        //prime[0] += 1;
        //prime[prime[0]] = i;
    }
    return ;
}
int main () {
    init();
    printf("%d\n",prime[10001]);
    return 0;
}

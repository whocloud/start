/*************************************************************************
	> File Name: EP207-2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 13时08分37秒
 ************************************************************************/

#include<stdio.h>
#define MAX 10000
int prime[MAX + 5] = {0};
void init () {
    for (int i = 2; i * i <= MAX; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= MAX; j += i) {
            //if (prime[j]) continue;
            prime[j] = i; 
        }
    }
    return;
}
int main () {
    init ();
    int n;
    while (~scanf("%d", &n)) {
        printf("%d(%d)\n",n,prime[n]);
    }
    return 0;
}

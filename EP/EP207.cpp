/*************************************************************************
	> File Name: EP207.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 10时02分34秒
 ************************************************************************/

#include<stdio.h>
int prime (int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
int main () {
    int n = 0,num = 1;
    do {
        num += 1;
        while (!prime(num)) num++;
        n += 1;
    }while (n < 10001);
    printf("%d(%d)\n" , n, num);
    return 0;
}

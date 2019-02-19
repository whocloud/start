/*************************************************************************
	> File Name: EP205.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 09时38分31秒
 ************************************************************************/

#include<stdio.h>
int gcd (int a, int b) {
    return (b ? gcd(b, a % b) : a);
}
int main () {
    int sum = 1;
    for (int i = 1; i <= 20; i++) {
        if (sum % i == 0) continue;
        sum = i * sum / gcd(sum, i);
    }
    printf("%d\n",sum);
    return 0;
}


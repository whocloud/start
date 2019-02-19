/*************************************************************************
	> File Name: EP30.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 19时30分12秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX_N 354294
int is_valid(int x) {
    int sum = 0, temp = x;
    while (x) {
        sum += (int)pow(x % 10, 5);
        x /= 10;
    }
    return temp == sum;
}
int main () {
    int sum = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_valid(i)) continue;
        printf("%d\n", i);
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}

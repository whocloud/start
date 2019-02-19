/*************************************************************************
	> File Name: EP34.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 20时26分25秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX_N 2540160
int fun (int i) {
    int n = 1, s = 1;
    while (n <= i) {
        s *= n;
        n += 1;
    }
    return s;
}
int is_valid(int x) {
    int sum = 0, temp = x, a = 0;
    while (x) {
        a = x % 10;
        sum += fun(a);
        x /= 10;
    }
    return temp == sum;
}
int main () {
    int sum = 0;
    for (int i = 3; i < MAX_N; i++) {
        if(!is_valid(i)) continue;
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}

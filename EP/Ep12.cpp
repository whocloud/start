/*************************************************************************
	> File Name: Ep12.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月22日 星期六 14时16分46秒
 ************************************************************************/

#include<stdio.h>

int num(int n) {
    return n * (n + 1) / 2;
}

int fac_num(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) cnt += 2;
    }
    return cnt;
}

int main() {
    int n = 1;
    while (fac_num(num(n)) < 500) n++;
    printf("%d\n", num(n));
    return 0;
}

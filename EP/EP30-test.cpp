/*************************************************************************
	> File Name: EP30-test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月22日 星期二 20时50分13秒
 ************************************************************************/

#include<stdio.h>

#define MAX 354294

int quickpow(int a, int b) {
    int ans = 1, temp = a;
    while(b) {
        if(b & 1) ans = ans * temp;
        temp *= temp;
        b >>= 1;
    }
    return ans;
}


int allnum(int x) {
    int temp = 0, temp1 = x;
    while(x) {
        temp += quickpow((x % 10), 5);
        x /= 10;
    }
    if (temp == temp1) return 1;
    return 0;
}

int main() {
    int sum = 0;
    for(int i = 2; i <= MAX; i++) {
        if(!allnum(i)) continue;
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}

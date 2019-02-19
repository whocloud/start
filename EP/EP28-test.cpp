/*************************************************************************
	> File Name: EP28-test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月22日 星期二 20时31分15秒
 ************************************************************************/

#include<stdio.h>

int quickmin(int a, int b) {
    int ans = 1, temp = a;
    while(b) {
        if(b & 1) ans = ans * temp;
        temp *= temp;
        b >>= 1;
    }
    return ans;
}

int main() {
    int sum = 1;
    for (int i = 3; i <= 1001; i += 2) {
        sum += 4 * quickmin(i, 2) - 6 * (i - 1);
        printf("%d %d\n", i, quickmin(i, 2));
    }
    printf("%d\n", sum);
    return 0;
}

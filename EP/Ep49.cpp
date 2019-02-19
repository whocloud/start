/*************************************************************************
	> File Name: Ep49.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月15日 星期二 17时53分03秒
 ************************************************************************/

#include<stdio.h>
#define max 10000

int prime[max + 5] = {0};
int num[max + 5] = {0};

void init() {
    for (int i = 2; i < max; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            num[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int is_interesting(int a, int b, int c) {
    int sum[2][10] = {0};
    for (int i = 0; i < 4; i++) {
        sum[0][a % 10] += 1;
        sum[1][a % 10] += 1;
        a /= 10;
    }
    for (int i = 0; i < 4; i++) {
        if (sum[b % 10] != 0 && sum[c % 10] != 0) {
            sum[0][b % 10] -= 1;
            sum[1][c % 10] -= 1;
            b /= 10;
            c /= 10;
        } else break;
    }
    for (int i = 0; i <= 9; i++) {
        if (sum[0][i] > 0) {
            return 0;
        } else if (sum[1][i] > 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    init();
    printf("%d\n", is_interesting(1487, 4817, 8147));
    printf("%d\n", is_interesting(1051, 5101, 9151));
    for (int i = 1000; i < max; i++) {
        for (int j = 1; j < 9000; j++) {
            if ((i + 2 * j) > max) break;
            if (num[i] == 1 && num[i + j] == 1 && num[i + 2 * j] == 1) {
                if (is_interesting(i, i + j, i + 2 * j)) {
                    printf("%d ", i);
                    printf("%d ", i + j);
                    printf("%d\n", i + 2 * j);
                    break;
                } 
            }
        }
    }
    return 0;
}

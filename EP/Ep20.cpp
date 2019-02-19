/*************************************************************************
	> File Name: Ep20.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月19日 星期六 20时49分49秒
 ************************************************************************/

#include<stdio.h>

int finall[500] = {0};

void change() {
    finall[0] = finall[1] = 1;
    for (int i = 1; i <= 100; i++) {
        for (int m = 1; m <= finall[0]; m++)
        finall[m] *= i;
        for (int j = 1; j <= finall[0]; j++) {
            if (finall[j] < 10) continue;
            finall[j + 1] += finall[j] / 10;
            finall[j] %= 10;
            if (j == finall[0]) finall[0]++;
        }
    }
}

int main() {
    int sum = 0;
    change();
    for (int i = 1; i <= finall[0]; i++) {
        sum += finall[i];
    }
    printf("%d\n", sum);
    return 0;
}

/*************************************************************************
	> File Name: Ep02.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月04日 星期五 20时01分06秒
 ************************************************************************/

#include<stdio.h>
#define max 4000000

int num[max + 5] = {0};

void init() {
    num[0] = 1;
    num[1] = 1;
    for (int i = 2; i <= max; i++) {
        num[i] = num[i - 1] + num[i - 2];
        if (num[i] > max) break;
    }
    return ;
}

int main() {
    init();
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", num[i]);
    }
    for (int i = 2;i <= max; i += 3) {
        if (num[i] > max) break;
        sum += num[i];
    }
    printf("%d\n", sum);
    return 0;
}

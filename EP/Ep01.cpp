/*************************************************************************
	> File Name: Ep01.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月04日 星期五 19时01分39秒
 ************************************************************************/

#include<stdio.h>
#define max 1000

int num[max + 5] = {0};

void init() {
    int temp = 3;
    while (temp < max) {
        num[temp] = 1;
        temp += 3;
    }
    int temp1 = 5;
    while (temp1 < max) {
        num[temp1] = 1;
        temp1 += 5;
    }
    return ;
}

int main() {
    init();
    int sum = 0;
    for (int i = 1; i < max; i++) {
        if (num[i]) sum += i;
    }
    printf("%d\n",sum);
    return 0;
}

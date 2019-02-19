/*************************************************************************
	> File Name: EP04.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月05日 星期六 17时47分46秒
 ************************************************************************/

#include<stdio.h>

int is_palindromic(int x) {
    int temp = x;
    int ans = 0;
    while(x) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return temp == ans;
    //if (temp == ans) return 1;
    //return 0;
}

int main() {
    int sum = 10000;
    //int sum = 0;
    for (int i = 100; i < 1000; i++) {
        //for (int j = 100; j < 1000; j++) 
        for (int j = sum / (i + 1); j <= i; j++){
            if(is_palindromic(i * j)) sum = sum > i * j ? sum : i * j;
            continue;
        }
    }
    printf("%d\n", sum);
    return 0;
}

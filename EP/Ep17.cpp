/*************************************************************************
	> File Name: Ep17.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月19日 星期三 18时25分11秒
 ************************************************************************/

#include<stdio.h>

int get_letter_nums(int x) {
    static int arr1[20] = {
        0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3,
        6, 6, 8, 8, 7, 7, 9, 8, 8
    };
    static int arr2[10] = {
        0, 0, 6, 6, 5, 5, 5, 7, 6, 6
    };
    if (x < 20) {
        return arr1[x];
    } else if (x < 100) {
        return arr2[x / 10] + arr1[x % 10];
    } else if (x < 1000) {
        if (x % 100 == 0) {
            return arr1[x / 100] + 7;
        }
        return arr1[x / 100] + 10 + get_letter_nums(x % 100);
    } else {
        return 11;
    }
}

int main() {
    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        ans += get_letter_nums(i);
    }
    printf("%d\n", ans);
    return 0;
}

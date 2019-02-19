/*************************************************************************
	> File Name: Ep31.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月21日 星期五 18时58分53秒
 ************************************************************************/

#include<stdio.h>

int m[13][205] = {0};

int w(int k) {
    static int arr[8] = {
        1, 2, 5, 10, 20, 50, 100, 200
    };
    return arr[k - 1];
}

int f(int k, int n) {
    if (k == 1) return 1;
    if (n == 0) return 1;
    m[1][n] = 1;
    m[k][0] = 1;
    if (n < 0) return 0;
    if (m[k][n] == 0) {
        m[k][n] = f(k - 1, n) + f(k, n - w(k));
        return f(k - 1, n) + f(k, n - w(k));
    //    return m[k][n];都可以
    } else {
        return m[k][n];
    }   
}

int main() {
    int k = 8, n = 200;
    printf("%d", f(k, n));
    return 0;
////    int k = 9;
////    int m[k] = {0, 1, 2, 5, 10, 20, 50, 100, 200};
////    int n = 200;
////    int f[k][n];
////    f[1][] = {1};
////    for (int i = 2; i <= k; i++) {
////        while (f[i - 1][n] != 1 || f[i][n - m[i]] != 1) {
////            f[i][n] = f[i - 1][n] + f[i][n - m[i]];
////        }
////    }
////    printf("%d", f[k][n]);
}

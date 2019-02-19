/*************************************************************************
	> File Name: Ep33.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月18日 星期五 23时17分11秒
 ************************************************************************/

#include<stdio.h>

int a[100] = {0};

int gcd(int x, int y) {
    if (!y) return x;
    return gcd (y, x % y);
}

bool is_nontrivial(int x, int y) {
    if (x < 10 || x > 100) return false;
    if (y < 10 || y > 100) return false;
    if (x >= y) return false;
    int x1, y1, x2, y2;
    x1 = x / 10, x2 = x % 10, y1 = y / 10, y2 = y % 10;
    if (!x1 || !x2 || !y1 || !y2) return false;
    if (x1 == y1 && x2 * y == y2 * x) return true;
    if (x1 == y2 && x2 * y == y1 * x) return true;
    if (x2 == y1 && x1 * y == y2 * x) return true;
    if (x2 == y2 && x1 * y == y1 * x) return true;
    return false;
}

int main() {
    int ans1 = 1, ans2 = 1;
    for (int i = 11; i <= 99; i++) {
        for (int j = 11; j <= 99; j++) {
            if (is_nontrivial(i, j)) {
                ans1 *= i;
                ans2 *= j;
            }
        }
    }
    printf("%d %d\n", ans1, ans2);
    ans1 = ans2 / gcd(ans1, ans2);
    printf("%d\n", ans1);
    return 0;
}

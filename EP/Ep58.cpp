/*************************************************************************
	> File Name: Ep58.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月29日 星期六 20时35分00秒
 ************************************************************************/
#include<cmath>
#include<iostream>
using namespace std;

int  is_prime(int x) {
    if (x <= 1) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n = 0, m = 1, len = 3;
    for (; len; len += 2) {
        int val1 = len * len;
        int val2 = val1 - len + 1;
        int val3 = val2 - len + 1;
        int val4 = val3 - len + 1;
        n += is_prime(val1);
        n += is_prime(val2);
        n += is_prime(val3);
        n += is_prime(val4);
        m += 4;
        if (n * 10 < m) break;
    }
    cout << len << endl;
    return 0;
}

/*************************************************************************
	> File Name: Ep54.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月29日 星期六 19时44分47秒
 ************************************************************************/
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;

#define max 300

int main() {
    int ans = 0;
    for (int t = 2; t < 100; t++) {
        int f[max + 5] = {0};
        f[0] = f[1] = 1;
        f[1] = t;
        for (int o = 2; o < 100; o++) { 
            for (int i = 1; i <= f[0]; i++) f[i] *= t;
            for (int i = 1; i <= f[0]; i++) {
                if (f[i] < 10) continue;
                f[i + 1] += f[i] / 10;
                f[i] = f[i] % 10;
                f[0] += (f[0] == i);
            }
            int sum = 0;
            for (int i = 1; i <= f[0]; i++) sum += f[i];
            if (ans < sum) ans = sum;
        }
    }
    cout <<  ans << endl;
    return 0;
}

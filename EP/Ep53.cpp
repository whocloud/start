/*************************************************************************
	> File Name: Ep53.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年12月29日 星期六 19时25分39秒
 ************************************************************************/
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;

#define max 100

int f[max + 5][100 + 5] = {0};



int main() {
    for (int i = 0; i <= max; i++) {
        f[i][0] = f[i][i] = 1;
        for (int j = 1; j < i; j++) {
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
            if (f[i][j] > 1000000) f[i][j] = 1000001;
        }
    }

    return 0;
}

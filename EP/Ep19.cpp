/*************************************************************************
	> File Name: Ep19.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月19日 星期六 19时49分53秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

int64_t weekday(int y, int m, int d) {
    if (m < 3) {
        m += 12;
        --y;
    }
    int64_t temp; 
    temp = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    return temp;
}

int main() {
    int64_t y, m, d = 1, w = 0;
    for (y = 1901; y <= 2000; y++) {
        for (m = 1; m <= 12; m++) {
            if (weekday(y, m, 1) == 6) {
                w++;
            }
        }
    }
    printf("%" PRId64"\n", w);
    return 0;
}
